package fr.ensim.xml.deezer;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

import fr.ensim.xml.deezer.dom.DOMSearchAlbumsTest;
import fr.ensim.xml.deezer.sax.SAXSearchAlbumsTest;
import fr.ensim.xml.deezer.stax.StAXSearchAlbumsTest;

@RunWith(Suite.class)
@SuiteClasses({ DOMSearchAlbumsTest.class, SAXSearchAlbumsTest.class, StAXSearchAlbumsTest.class})
public class AllTests {
 
}
