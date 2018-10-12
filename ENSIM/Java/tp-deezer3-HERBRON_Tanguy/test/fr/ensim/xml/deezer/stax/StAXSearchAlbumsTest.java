package fr.ensim.xml.deezer.stax;

import static org.junit.Assert.assertEquals;

import java.io.InputStream;
import java.util.List;

import javax.xml.stream.XMLStreamException;

import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;
import org.junit.Test;

import fr.ensim.xml.deezer.data.Album;

/**
 * @author Denis Apparicio
 * 
 */
public class StAXSearchAlbumsTest {
  static {
    DOMConfigurator.configure("log4J.xml");
  }

  private static final Logger LOG = Logger
                                      .getLogger(StAXSearchAlbumsTest.class);
 
  @Test
  public void testCount() throws XMLStreamException {
    LOG.debug(">>testCount");

    // Recuperation du flux a parser
    InputStream in = getClass().getResourceAsStream("../list-albums.xml");

    //TODO
    StAXSearchAlbums staxSearchAlbums = new StAXSearchAlbums();
    assertEquals(10, staxSearchAlbums.count(in));
    
    LOG.debug("<<testCount");
  }
  
  @Test
  public void testParse() throws XMLStreamException {
    LOG.debug(">>testParse");

    // Recuperation du flux a parser
    InputStream in = getClass().getResourceAsStream("../list-albums.xml");

    //TODO
    StAXSearchAlbums staxSearchAlbums = new StAXSearchAlbums();
    List<Album> listAlbums = staxSearchAlbums.readAlbums(in);
    assertEquals(10, listAlbums.size());
    assertEquals("47685332", listAlbums.get(0).getId());
    assertEquals("The Evol", listAlbums.get(0).getTitle());
    assertEquals("http://api.deezer.com/2.0/album/47685332/image", listAlbums.get(0).getCover());
    assertEquals("83325", listAlbums.get(0).getArtist().getId());
    assertEquals("Shaka Ponk", listAlbums.get(0).getArtist().getName());

    //Second album
    assertEquals("1121440", listAlbums.get(1).getId());
    assertEquals("The Geeks And The Jerkin' Socks", listAlbums.get(1).getTitle());
    assertEquals("http://api.deezer.com/2.0/album/1121440/image", listAlbums.get(1).getCover());
    assertEquals("83325", listAlbums.get(1).getArtist().getId());
    assertEquals("Shaka Ponk", listAlbums.get(1).getArtist().getName());
    
    LOG.debug("<<testParse");
  }
}
