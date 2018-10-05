package fr.ensim.xml.deezer;

import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.List;

import org.apache.log4j.Logger;

import fr.ensim.xml.deezer.data.Track;

/**
 * @author Denis Apparicio
 * 
 */
public abstract class AbstractSearchAlbumTracks {
  private static Logger log = Logger.getLogger(AbstractSearchAlbumTracks.class);

  /**
   * Restitue la liste des chansons d'un album.
   * 
   * @param id
   *          id de l'album.
   * @return la liste des chansons.
   * @throws Exception
   */
  public List<Track> find(String id) throws Exception {
    log.debug(">>find");

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
        return readTrack(cnx.getInputStream());
      }
    }
    finally {
      cnx.disconnect();
    }

    log.debug("<<find");
    return null;
  }

  /**
   * Restitue la liste des chansons d'un album &agrave; partir d'un flux.
   * 
   * @param in
   *          le flux.
   * @return la liste des chansons.
   * @throws Exception
   */
  public abstract List<Track> readTrack(InputStream in) throws Exception;

}