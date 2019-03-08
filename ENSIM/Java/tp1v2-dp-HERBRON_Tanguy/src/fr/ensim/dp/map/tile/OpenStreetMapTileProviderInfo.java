package fr.ensim.dp.map.tile;

import org.apache.log4j.Logger;
import org.jdesktop.swingx.mapviewer.TileFactoryInfo;

import fr.ensim.dp.util.LoggerUtil;

/**
 * @author Denis Apparicio
 * 
 */
public class OpenStreetMapTileProviderInfo extends TileFactoryInfo {
  private static Logger    log            = LoggerUtil.getLogger();

  private static final int TOP_ZOOM_LEVEL = 17;

  protected OpenStreetMapTileProviderInfo(String url, String name) {
    // tile
    // size
    // is 256
    // and x/y
    // orientation
    // is normal
    super(name,
          1,
          TOP_ZOOM_LEVEL - 2,
          TOP_ZOOM_LEVEL,
          256,
          true,
          true,
          url,
          "x",
          "y",
          "z");

  }

  /*
   * (non-Javadoc)
   * 
   * @see org.jdesktop.swingx.mapviewer.TileFactoryInfo#getTileUrl(int, int,
   * int)
   */
  public String getTileUrl(int x, int y, int zoom) {
    if (log.isDebugEnabled()) {
      log.debug(">>getTileUrl [" + x + ", " + y + ", " + zoom + "]");
    }

    zoom = TOP_ZOOM_LEVEL - zoom;
    String url = this.baseURL + "/" + zoom + "/" + x + "/" + y + ".png";

    if (log.isDebugEnabled()) {
      log.debug("<<getTileUrl " + url);
    }

    return url;
  }

}
