package fr.ensim.xml.deezer.stax;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.events.EndElement;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;

import org.apache.log4j.Logger;

import fr.ensim.xml.deezer.AbstractSearchAlbum;
import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Artist;

/**
 * @author Denis Apparicio
 * 
 */
public class StAXSearchAlbums extends AbstractSearchAlbum {
  private static final Logger LOG = Logger.getLogger(StAXSearchAlbums.class);
 
  /**
   * Compte le nombre d'albums.
   * 
   * @param in
   *          le flux xml.
   * @return le nombre d'albums.
   * @throws XMLStreamException
   */
  public int count(InputStream in) throws XMLStreamException {
    LOG.debug(">>count");

    int nbAlbums = 0;
    // recuperation d'un parser StAX
    // @ TODO
    XMLEventReader reader = XMLInputFactory.newInstance().createXMLEventReader(in);
    
    while(reader.hasNext())
    {
    	XMLEvent event = reader.nextEvent();
    	
    	if(event.isStartElement())
    	{
    		StartElement startElement = event.asStartElement();
    		
    		if(startElement.getName().toString().equals("album"))
    		{
    			nbAlbums++;
    		}
    	}
    }

    LOG.debug("<<count " + nbAlbums);
    return nbAlbums;
  }
  
  private Album buildingAlbum;
  private Artist buildingArtist;
  private String element;
  private boolean isArtist;

  @Override
  public List<Album> readAlbums(InputStream in) throws XMLStreamException {
    LOG.debug(">>readAlbums");

    List<Album> listAlbums = new ArrayList<Album>();
    
    XMLStreamReader reader = XMLInputFactory.newInstance().createXMLStreamReader(in);
    
    while(reader.hasNext())
    {
    	switch(reader.next())
    	{
    	case XMLEvent.START_ELEMENT:
    		switch(reader.getName().toString())
    		{
    		case "album":
    			buildingAlbum = new Album();
    			break;
    		case "artist":
    			buildingArtist = new Artist();
    			isArtist = true;
    			break;
    		default:
    			element = reader.getName().toString();
    		}
    		break;
    	case XMLEvent.CHARACTERS:
    		switch(element)
    		{
    		case "id":
    			if(isArtist)
    			{
    				buildingArtist.setId(reader.getText());
    			}
    			else
    			{
    				buildingAlbum.setId(reader.getText());
    			}
    			break;
    		case "title":
    			buildingAlbum.setTitle(reader.getText());
    			break;
    		case "cover":
    			buildingAlbum.setCover(reader.getText());
    			break;
    		case "name":
    			buildingArtist.setName(reader.getText());
    			break;
    		case "link":
    			if(isArtist) buildingArtist.setLink(reader.getText());
    			break;
    		case "picture":
    			buildingArtist.setPicture(reader.getText());
    			break;
    		}
    		break;
    	case XMLEvent.END_ELEMENT:
    		switch(reader.getName().toString())
    		{
    		case "album":
    			listAlbums.add(buildingAlbum);
    			break;
    		case "artist":
    			buildingAlbum.setArtist(buildingArtist);
    			isArtist = false;
    			break;
    		default:
    			element = "";
    		}
    	}
    }

    LOG.debug("<<readAlbums");
    return listAlbums;
  }
}
