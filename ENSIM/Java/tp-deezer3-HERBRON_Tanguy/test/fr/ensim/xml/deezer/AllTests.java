package fr.ensim.xml.deezer;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

import fr.ensim.json.JSONSearchAlbumTest;
import fr.ensim.json.JSONSearchAlbumTracksTest;
import fr.ensim.xml.deezer.dom.DOMSearchAlbumTracksTest;
import fr.ensim.xml.deezer.dom.DOMSearchAlbumsTest;
import fr.ensim.xml.deezer.sax.SAXSearchAlbumsTest;
import fr.ensim.xml.deezer.stax.StAXSearchAlbumsTest;

@RunWith(Suite.class)
@SuiteClasses({ JSONSearchAlbumTest.class, JSONSearchAlbumTracksTest.class
	, DOMSearchAlbumsTest.class, DOMSearchAlbumTracksTest.class
	, SAXSearchAlbumsTest.class
	, StAXSearchAlbumsTest.class})
public class AllTests {
 
}
