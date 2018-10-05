package fr.ensim.xml.deezer;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

import org.apache.log4j.Logger;
import org.xml.sax.SAXException;

import fr.ensim.xml.deezer.data.Album;

/**
 * @author Denis Apparicio
 *
 */
public abstract class AbstractSearchAlbum {
  private static final Logger LOG = Logger.getLogger(AbstractSearchAlbum.class);

  /**
   * Restitue la liste des albums d'un auteur.
   * 
   * @param author
   *          l'auteur.
   * @throws IOException
   * @throws ParserConfigurationException
   * @throws SAXException
   */
  public List<Album> find(String author) throws IOException,
                                        ParserConfigurationException,
                                        SAXException {
    LOG.debug(">>find author="+author);
    
    // Constitution de l'URL
    StringBuilder sUrl = new StringBuilder();
    sUrl.append("http://api.deezer.com/2.0/search/album?q=");
    sUrl.append(author);
    sUrl.append("&output=xml");

    URL url = new URL(sUrl.toString());
    LOG.debug(url);

    HttpURLConnection cnx = (HttpURLConnection) url.openConnection();
    
    List<Album> albums = null;
    try {

      // recuperation du flux xml
      cnx.setConnectTimeout(5000);
      cnx.setReadTimeout(5000);
      cnx.setRequestMethod("GET");
      cnx.setDoInput(true);
      cnx.addRequestProperty("Accept-Language", "en;q=0.6,en-us;q=0.4,sv;q=0.2");
      if (cnx.getResponseCode() != HttpURLConnection.HTTP_OK) {
        throw new IOException("http status code " + cnx.getResponseCode());
      }

      InputStream in = cnx.getInputStream();

      // Lecture
      albums = readAlbums(in);
    }
    catch(Exception e) {
      LOG.error("", e);
    }
    finally {
      cnx.disconnect();
    }
    
    LOG.debug("<<find");
    return albums;
  }

  /**
   * Restitue la liste des albums à partir du flux xml.
   * 
   * @param in
   *          le flux xml.
   * @return la liste des albums.
   */
  public abstract List<Album> readAlbums(InputStream in) throws Exception;

}
