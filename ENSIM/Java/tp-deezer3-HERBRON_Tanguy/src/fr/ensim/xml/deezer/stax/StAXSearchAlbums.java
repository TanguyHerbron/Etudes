package fr.ensim.xml.deezer.stax;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.xml.stream.XMLStreamException;

import org.apache.log4j.Logger;

import fr.ensim.xml.deezer.AbstractSearchAlbum;
import fr.ensim.xml.deezer.data.Album;

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

    LOG.debug("<<count " + nbAlbums);
    return nbAlbums;
  }

  @Override
  public List<Album> readAlbums(InputStream in) throws XMLStreamException {
    LOG.debug(">>readAlbums");

    List<Album> listAlbums = new ArrayList<Album>();

    // recuperation d'un parser StAX
    // @ TODO

    // parsing
    // @ TODO

    LOG.debug("<<readAlbums");
    return listAlbums;
  }
}
