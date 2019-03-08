package fr.ensim.dp.map.tile;

import org.jdesktop.swingx.mapviewer.AbstractTileFactory;


/**
 * @author Denis Apparicio
 * 
 */
public final class OpenStreetMapTileFactory extends AbstractTileFactory {
  // mapnik
  private static final String   MAPNIK       = "mapnik";

  private static final String   MAPNIK_URL   = "http://tile.openstreetmap.org";

  // OSM France
  private static final String   OSM_FRANCE         = "OSM France";

  private static final String   OSM_FRANCE_URL     = "http://a.tile.openstreetmap.fr/osmfr";

  // Carto Light
  private static final String   LANDSCAPE     = "Thunderforest Landscape";

  private static final String   LANDSCAPE_URL = "https://cartodb-basemaps-1.global.ssl.fastly.net/light_all";

 // OpenPtMap
 private static final String   TRANSPORT     = "Transport OpenPtMap";
 
 private static final String   TRANSPORT_URL = "http://www.openptmap.org/tiles";
 
  private static final String[] TILE_NAMES   = { MAPNIK,
	  OSM_FRANCE,
	  LANDSCAPE,
	  TRANSPORT};

  private OpenStreetMapTileFactory(OpenStreetMapTileProviderInfo tileProviderInfo) {
    super(tileProviderInfo);
    //TODO valoriser Le DiskCache adpator
    // methode void org.jdesktop.swingx.mapviewer.AbstractTileFactory.setTileCache(TileCache cache)
    //setTileCache(disk cache adaptor);
  }

  /**
   * @param name
   * @return
   */
  public static AbstractTileFactory getTileFactory(String name) {
    if (MAPNIK.equals(name)) {
      return createMap(MAPNIK_URL, MAPNIK);
    }
    if (OSM_FRANCE.equals(name)) {
        return createMap(OSM_FRANCE_URL, OSM_FRANCE);
    }
    if (LANDSCAPE.equals(name)) {
        return createMap(LANDSCAPE_URL, LANDSCAPE);
    }
    if (TRANSPORT.equals(name)) {
        return createMap(TRANSPORT_URL, TRANSPORT);
    }

    throw new IllegalArgumentException("Tile inconnu " + name);
  }


  /**
   * 
   * @return Restitue la map Mapnik
   */
  private static AbstractTileFactory createMap(String url, String name) {
    OpenStreetMapTileProviderInfo info = new OpenStreetMapTileProviderInfo(url, name);
    return new OpenStreetMapTileFactory(info);
  }

  /**
   * Restitue les noms des maps.
   * 
   * @return les noms des maps
   */
  public static String[] getTileNames() {
    return TILE_NAMES;
  }
}
