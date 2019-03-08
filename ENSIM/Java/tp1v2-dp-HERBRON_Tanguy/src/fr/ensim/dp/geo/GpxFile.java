package fr.ensim.dp.geo;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.apache.log4j.Logger;
import org.jdesktop.swingx.mapviewer.GeoPosition;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.helpers.DefaultHandler;

import fr.ensim.dp.util.LoggerUtil;

/**
 * @author Denis Apparicio
 * 
 */
public class GpxFile {
  private static Logger log = LoggerUtil.getLogger();

  /**
   * 
   */
  private GpxFile() {
  }

  /**
   * Recupère la liste des points GPS.
   * 
   * @param file
   *          fichier GPX
   * @return liste des points.
   * @throws ParserConfigurationException
   * @throws SAXException
   * @throws IOException
   */
  public static List<GeoPosition> load(File file) throws ParserConfigurationException,
                                                 SAXException,
                                                 IOException {
    log.debug(">>load");

    // Lecture
    FileInputStream fis = new FileInputStream(file);

    GpxHandler handler = null;
    try {
      SAXParserFactory factory = SAXParserFactory.newInstance();
      factory.setNamespaceAware(true);
      SAXParser parser = factory.newSAXParser();

      handler = new GpxHandler();
      parser.parse(fis, handler);
    }
    finally {
      try {
        fis.close();
      }
      catch (IOException ioe) {
        log.error("", ioe);
      }
    }

    log.debug("<<load");
    return handler.listGeo;
  }

  /**
   * @author Denis Apparicio
   * 
   */
  private static class GpxHandler extends DefaultHandler {
    private List<GeoPosition> listGeo = new ArrayList<GeoPosition>();

    public GpxHandler() {
      super();

    }

    /*
     * (non-Javadoc)
     * 
     * @see org.xml.sax.helpers.DefaultHandler#startElement(java.lang.String,
     * java.lang.String, java.lang.String, org.xml.sax.Attributes)
     */
    public void startElement(String uri,
                             String localName,
                             String qName,
                             Attributes attrs) throws SAXParseException {
      if (localName.equals("trkpt")) {
        // Latitude
        String attr = attrs.getValue("lat");
        double lat = (attr != null) ? Double.valueOf(attr) : Double.NaN;

        // Longitude
        attr = attrs.getValue("lon");
        double lon = (attr != null) ? Double.valueOf(attr) : Double.NaN;

        listGeo.add(new GeoPosition(lat, lon));
      }
    }

  }

}
