package fr.ensim.xml.deezer.sax;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.apache.log4j.Logger;
import org.xml.sax.SAXException;

import fr.ensim.xml.deezer.AbstractSearchAlbum;
import fr.ensim.xml.deezer.data.Album;

/**
 * @author Denis Apparicio
 * 
 */
public class SAXSearchAlbums extends AbstractSearchAlbum {
  private static final Logger LOG = Logger.getLogger(SAXSearchAlbums.class);
 

  @Override
  public List<Album> readAlbums(InputStream in)  {
    LOG.debug(">>readAlbums");

    //TODO Recherche les albums en SAX
    SAXSearchAlbumsHandler handler = new SAXSearchAlbumsHandler();
    SAXParserFactory factory = SAXParserFactory.newInstance();
    factory.setNamespaceAware(true);
    try {
		SAXParser parser = factory.newSAXParser();
		parser.parse(in, handler);
	} catch (ParserConfigurationException e) {
		// TODO Auto-generated catch block
		LOG.error("ParserConfigurationException", e);
	} catch (SAXException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} catch (IOException e) {
		// TODO: handle exception
		e.printStackTrace();
	}
    

    LOG.debug("<<readAlbums");
    return handler.getListAlbum();
  }
}
