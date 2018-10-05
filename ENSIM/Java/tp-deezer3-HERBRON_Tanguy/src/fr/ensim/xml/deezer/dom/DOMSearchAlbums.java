package fr.ensim.xml.deezer.dom;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

import org.apache.log4j.Logger;
import org.xml.sax.SAXException;

import fr.ensim.xml.deezer.AbstractSearchAlbum;
import fr.ensim.xml.deezer.data.Album;

/**
 * @author Denis Apparicio
 * 
 */
public class DOMSearchAlbums extends AbstractSearchAlbum {
  private static final Logger LOG = Logger.getLogger(DOMSearchAlbumsTest.class);
 
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

    //TODO Recherche les albums en DOM


    LOG.debug("<<readAlbums");
    return listAlbums;
  }
}
