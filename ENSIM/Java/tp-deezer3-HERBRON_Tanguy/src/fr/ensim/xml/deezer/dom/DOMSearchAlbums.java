package fr.ensim.xml.deezer.dom;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.apache.log4j.Logger;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import fr.ensim.xml.deezer.AbstractSearchAlbum;
import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Artist;
import fr.ensim.xml.deezer.data.Track;

/**
 * @author Denis Apparicio
 * 
 */
public class DOMSearchAlbums extends AbstractSearchAlbum {
  private static final Logger LOG = Logger.getLogger(DOMSearchAlbums.class);
 
  /*
   * (non-Javadoc)
   * 
   * @see
   * fr.ensim.xml.deezer.AbstractSearchAlbum#readAlbums(java.io.InputStream)
   */
  @Override
  public List<Album> readAlbums(InputStream in) throws ParserConfigurationException,
                                               SAXException,
                                               IOException {
    LOG.debug(">>readAlbums");

    List<Album> listAlbums = new ArrayList<Album>();

   //TODO Recherche les pistes d'albums en DOM
    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
    DocumentBuilder db = dbf.newDocumentBuilder();
    Document doc = db.parse(in);
    doc.normalize();
    
    parseChildElements(doc.getDocumentElement(), listAlbums);
    listAlbums.add(buildingAlbum);

    LOG.debug("<<readAlbums");
    return listAlbums;
  }
  
  private boolean isArtistBeingRead;
  private Album buildingAlbum;
  private Artist buildingArtist;
  
  protected void parseChildElements(Element el, List<Album> listAlbums)
  {
	  if(el.getNodeName().equals("album"))
	  {
		  if(buildingAlbum != null)
		  {
			  buildingAlbum.setArtist(buildingArtist);
			  listAlbums.add(buildingAlbum);
			  isArtistBeingRead = false;
		  }
		  
		  buildingAlbum = new Album();
	  }
	  
	  if(el.getNodeName().equals("artist"))
	  {
		  isArtistBeingRead = true;
		  
		  if(isArtistBeingRead)
		  {
			  buildingArtist = new Artist();
		  }
	  }
		
	  //x:album, id, title, cover, name, link, picture, x:s:artist
	  
	  if(isArtistBeingRead)
	  {
		  switch(el.getNodeName())
		  {
		  case "id":
			  buildingArtist.setId(el.getTextContent());
			  break;
		  case "name":
			  buildingArtist.setName(el.getTextContent());
			  break;
		  case "link":
			  buildingArtist.setLink(el.getTextContent());
			  break;
		  case "picture":
			  buildingArtist.setPicture(el.getTextContent());
			  break;
		  }
	  }
	  else
	  {
		  switch(el.getNodeName())
		  {
		  case "id":
			  buildingAlbum.setId(el.getTextContent());
			  break;
		  case "title":
			  buildingAlbum.setTitle(el.getTextContent());
			  break;
		  case "cover":
			  buildingAlbum.setCover(el.getTextContent());
			  break;
		  }
	  }
	  
	  NodeList nl = el.getChildNodes();
	  for(int i = 0; i < nl.getLength(); i++)
	  {
		  Node n = nl.item(i);
		  if(n instanceof Element)
		  {
			  parseChildElements((Element) n, listAlbums);
		  }
	  }
  }
}
