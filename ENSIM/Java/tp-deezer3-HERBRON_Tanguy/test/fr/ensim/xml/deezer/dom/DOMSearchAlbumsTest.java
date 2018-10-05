package fr.ensim.xml.deezer.dom;

import java.io.InputStream;

import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;
import org.junit.Test;

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
  public void testParse() {
    LOG.debug(">>testParse");

    // Recuperation du flux a parser
    InputStream in = getClass().getResourceAsStream("../album-stupeflip.xml");

   //TODO

    LOG.debug("<<testParse");
  }  
}
