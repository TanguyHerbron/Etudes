package fr.ensim.xml.deezer.dom;

import static org.junit.Assert.assertEquals;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;
import org.junit.Test;
import org.w3c.dom.Document;

import fr.ensim.xml.deezer.data.Album;
import org.xml.sax.SAXException;

/**
 * @author Denis Apparicio
 * 
 */
public class DOMSearchAlbumsTest {
  static {
    DOMConfigurator.configure("log4J.xml");
  } 

  private static final Logger LOG = Logger
                                      .getLogger(DOMSearchAlbumsTest.class);

  @Test
  public void testParse() throws ParserConfigurationException,
  								IOException,
  								SAXException {
    LOG.debug(">>testParse");

    // Recuperation du flux a parser
    InputStream in = getClass().getResourceAsStream("../list-albums.xml");

    List<Album> listAlbums = new DOMSearchAlbums().readAlbums(in);

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
