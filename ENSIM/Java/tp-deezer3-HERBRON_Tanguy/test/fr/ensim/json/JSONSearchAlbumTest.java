package fr.ensim.json;

import static org.junit.Assert.*;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

import org.apache.log4j.Logger;
import org.junit.Test;
import org.xml.sax.SAXException;

import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.dom.DOMSearchAlbums;

public class JSONSearchAlbumTest {

	private static final Logger LOG = Logger.getLogger(JSONSearchAlbumTest.class);

	@Test
	public void testParse() throws Exception {
		LOG.debug(">>testParse");

		// Recuperation du flux a parser
		//InputStream in = getClass().getResourceAsStream("../list-albums.json");
		InputStream in = getClass().getClassLoader().getResourceAsStream("fr/ensim/json/list-albums.json");

		List<Album> listAlbums = new JSONSearchAlbum().readAlbums(in);

		assertEquals(10, listAlbums.size());
		assertEquals("47685332", listAlbums.get(0).getId());
		assertEquals("The Evol’", listAlbums.get(0).getTitle());
		assertEquals("http://api.deezer.com/2.0/album/47685332/image", listAlbums.get(0).getCover());
		assertEquals("83325", listAlbums.get(0).getArtist().getId());
		assertEquals("Shaka Ponk", listAlbums.get(0).getArtist().getName());

		// Second album
		assertEquals("56633592", listAlbums.get(1).getId());
		assertEquals("Smells Like Teen Spirit", listAlbums.get(1).getTitle());
		assertEquals("http://api.deezer.com/2.0/album/56633592/image", listAlbums.get(1).getCover());
		assertEquals("83325", listAlbums.get(1).getArtist().getId());
		assertEquals("Shaka Ponk", listAlbums.get(1).getArtist().getName());
		LOG.debug("<<testParse");
	}

}
