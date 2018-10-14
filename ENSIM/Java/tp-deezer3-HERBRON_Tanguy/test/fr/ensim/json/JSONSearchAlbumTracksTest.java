package fr.ensim.json;

import static org.junit.Assert.*;

import java.io.InputStream;
import java.util.List;

import org.apache.log4j.Logger;
import org.junit.Test;

import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Track;

public class JSONSearchAlbumTracksTest {

	private static final Logger LOG = Logger.getLogger(JSONSearchAlbumTest.class);

	@Test
	public void test() throws Exception {
		LOG.debug(">>testParse");

		// Recuperation du flux a parser
		//InputStream in = getClass().getResourceAsStream("../list-albums.json");
		InputStream in = getClass().getClassLoader().getResourceAsStream("fr/ensim/json/47685332.json");

		List<Track> trackList = new JSONSearchAlbumTracks().find(in);
		
	    assertEquals(13, trackList.size());
	    //First album
	    assertEquals("Gung Ho", trackList.get(0).getTitle());
	    assertEquals("http://cdn-preview-a.deezer.com/stream/c-abbf47cd151375ceee9a5d3835545268-4.mp3", trackList.get(0).getPreview());

	    //Second album
	    assertEquals("Fear Ya", trackList.get(1).getTitle());
	    assertEquals("http://cdn-preview-f.deezer.com/stream/c-f2ff0cdc8bd8e4764f59d36ccf996d7c-4.mp3", trackList.get(1).getPreview());
	    
	    LOG.debug("<<testParse");
	}

}
