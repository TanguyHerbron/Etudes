package fr.ensim.xml.deezer.dom;

import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;
import org.junit.Test;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

import fr.ensim.xml.deezer.data.Track;
import fr.ensim.xml.deezer.sax.SAXSearchAlbumsHandler;
import fr.ensim.xml.deezer.sax.SAXSearchAlbumsTest;

public class DOMSearchAlbumTracksTest {
	  static {
		    DOMConfigurator.configure("log4J.xml");
		  }

	private static final Logger LOG = Logger.getLogger(DOMSearchAlbumTracksTest.class);

	@Test
	public void test() throws ParserConfigurationException, SAXException, IOException {
		LOG.debug(">>testParse");

	    // Recuperation du flux a parser
	    InputStream in = getClass().getResourceAsStream("../album-stupeflip.xml");
	    
	    List<Track> trackList = new DOMSearchAlbumTracks().find(in);
	    
	    assertEquals(19, trackList.size());
	    //First album
	    assertEquals("Intro", trackList.get(0).getTitle());
	    assertEquals("http://cdn-preview-f.deezer.com/stream/c-f4d3cef094894988635ab62f1e8d6c4e-3.mp3", trackList.get(0).getPreview());

	    //Second album
	    assertEquals("The Antidote", trackList.get(1).getTitle());
	    assertEquals("http://cdn-preview-a.deezer.com/stream/c-ac96a1f36c1ffe00fa17919160081e77-3.mp3", trackList.get(1).getPreview());
	    
	    LOG.debug("<<testParse");
	}

}
