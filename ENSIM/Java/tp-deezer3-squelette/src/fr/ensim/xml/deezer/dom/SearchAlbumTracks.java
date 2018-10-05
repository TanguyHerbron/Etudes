package fr.ensim.xml.deezer.dom;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
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

import fr.ensim.xml.deezer.data.Track;

/**
 * @author Denis Apparicio
 * 
 */
public class SearchAlbumTracks {
  private static Logger log = Logger.getLogger(SearchAlbumTracks.class);
 
  /**
   * Restitue la liste des chansons d'un album.
   * 
   * @param id
   *          id de l'album.
   * @return la liste des chansons.
   * @throws IOException
   * @throws ParserConfigurationException
   * @throws SAXException
   */
  
  private static Track buildingTrack;
  
  public static List<Track> find(String id) throws IOException,
                                           ParserConfigurationException,
                                           SAXException {
    log.debug(">>albums");

    // Constitution de l'URL
    StringBuilder sUrl = new StringBuilder();
    sUrl.append("http://api.deezer.com/2.0/album/");
    sUrl.append(id);
    sUrl.append("?output=xml");

    URL url = new URL(sUrl.toString());

    log.debug(url);

    HttpURLConnection cnx = (HttpURLConnection) url.openConnection();
    cnx.setConnectTimeout(5000);
    cnx.setReadTimeout(5000);
    cnx.setRequestMethod("GET");
    cnx.setDoInput(true);
    cnx.addRequestProperty("Accept-Language", "en;q=0.6,en-us;q=0.4,sv;q=0.2");

    try {
      if (cnx.getResponseCode() == HttpURLConnection.HTTP_OK) {
        return find(cnx.getInputStream());
      }
    }
    finally {
      cnx.disconnect();
    }

    log.debug("<<albums");
    return null;
  }

  /**
   * Restitue la liste des chansons d'un album &agrave; partir d'un flux.
   * 
   * @param in
   *          le flux.
   * @return la liste des chansons.
   * @throws SAXException
   * @throws ParserConfigurationException
   * @throws IOException
   */
  protected static List<Track> find(InputStream in) throws SAXException,
                                                   ParserConfigurationException,
                                                   IOException {
    log.debug(">>find");

    ArrayList<Track> listTracks = new ArrayList<Track>();

   //TODO Recherche les pistes d'albums en DOM
    DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
    DocumentBuilder db = dbf.newDocumentBuilder();
    Document doc = db.parse(in);
    doc.normalize();
    
    parseChildElements(doc.getDocumentElement(), listTracks);

    log.debug(">>find");
    return listTracks;
  }
  
  private static boolean isTrackBeingRead;
  
  private static void parseChildElements(Element el, List<Track> listTracks)
  {	  
	  if(el.getNodeName().equals("track"))
	  {
		  isTrackBeingRead = true;
		  
		  if(isTrackBeingRead)
		  {
			  if(buildingTrack != null)
			  {
				  listTracks.add(buildingTrack);
			  }
			  
			  buildingTrack = new Track();
		  }
	  }
	  
	  if(isTrackBeingRead)
	  {
		  switch(el.getNodeName())
		  {
		  case "title":
			  buildingTrack.setTitle(el.getTextContent());
			  break;
		  case "preview":
			  buildingTrack.setPreview(el.getTextContent());
			  break;
		  }
	  }
	  
	  NodeList nl = el.getChildNodes();
	  for(int i = 0; i < nl.getLength(); i++)
	  {
		  Node n = nl.item(i);
		  if(n instanceof Element)
		  {
			  parseChildElements((Element) n, listTracks);
		  }
	  }
  }
}
