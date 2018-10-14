package fr.ensim.json;

import static org.junit.Assert.*;

import java.io.InputStream;
import java.util.List;

import org.apache.log4j.Logger;
import org.junit.Test;

import fr.ensim.xml.deezer.data.Album;

public class JSONSearchAlbumTracksTest {

	private static final Logger LOG = Logger.getLogger(JSONSearchAlbumTest.class);

	@Test
	public void test() throws Exception {
		LOG.debug(">>testParse");

		// Recuperation du flux a parser
		//InputStream in = getClass().getResourceAsStream("../list-albums.json");
		InputStream in = getClass().getClassLoader().getResourceAsStream("fr/ensim/json/list-albums.json");

		List<Tra> listAlbums = new JSONSearchAlbum().readAlbums(in);

		assertEquals(10, handler.getListAlbum().size());
	    //First album
	    assertEquals("47685332", handler.getListAlbum().get(0).getId());
	    assertEquals("The Evol", handler.getListAlbum().get(0).getTitle());
	    assertEquals("http://api.deezer.com/2.0/album/47685332/image", handler.getListAlbum().get(0).getCover());
	    assertEquals("83325", handler.getListAlbum().get(0).getArtist().getId());
	    assertEquals("Shaka Ponk", handler.getListAlbum().get(0).getArtist().getName());

	    //Second album
	    assertEquals("1121440", handler.getListAlbum().get(1).getId());
	    assertEquals("The Geeks And The Jerkin' Socks", handler.getListAlbum().get(1).getTitle());
	    assertEquals("http://api.deezer.com/2.0/album/1121440/image", handler.getListAlbum().get(1).getCover());
	    assertEquals("83325", handler.getListAlbum().get(1).getArtist().getId());
	    assertEquals("Shaka Ponk", handler.getListAlbum().get(1).getArtist().getName());
	    
	    LOG.debug("<<testParse");
	}

}
