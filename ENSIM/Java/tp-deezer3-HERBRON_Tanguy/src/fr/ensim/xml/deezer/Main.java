package fr.ensim.xml.deezer;

import static org.junit.Assert.fail;

import java.awt.Desktop;
import java.awt.Desktop.Action;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;

import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Track;
import fr.ensim.xml.deezer.dom.DOMSearchAlbums;
import fr.ensim.xml.deezer.dom.SearchAlbumTracks;
import fr.ensim.xml.deezer.sax.SAXSearchAlbums;
import fr.ensim.xml.deezer.stax.HtmlAlbum;


/**
 * @author Denis Apparicio
 * 
 */
public class Main {

	/**
	 * @param args
	 */
	public Main(String args) {
		// configuration du proxy et des logs
		DOMConfigurator.configure("log4J.xml");
		ProxyConfiguration.configure();

		Logger log = Logger.getLogger(Main.class);

		FileOutputStream out = null;

		try { 
			List<Album> listAlbum;
			
			//listAlbum = new SAXSearchAlbums().find(args);
			listAlbum = new DOMSearchAlbums().find(args);

			// recuperation des titres de l album
			for(int i = 0; i < listAlbum.size(); i++)
			{
				listAlbum.get(i).setTracks(SearchAlbumTracks.find(listAlbum.get(i).getId()));
			}

			// Ecriture de la page html
			File fileHtml = new File(listAlbum.get(0).getArtist().getName() + ".html");
			out = new FileOutputStream(fileHtml);
			HtmlAlbum.write(listAlbum, out);
			out.close();

			// Ouverture de la page
			if (fileHtml.isFile()) {
				if (Desktop.isDesktopSupported()
						&& Desktop.getDesktop().isSupported(Action.BROWSE)) {
					Desktop.getDesktop().browse(fileHtml.toURI());
				}
			}
		}
		catch (Exception e) {
			log.error("", e);
			fail(e.getMessage());
		}
		finally {
			try {
				if (out != null) {
					out.close();
				}
			}
			catch (IOException e) {
				log.error("", e);
			}
		}

		log.debug("<<main");
	}

}
