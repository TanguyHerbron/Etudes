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

import fr.ensim.json.JSONSearchAlbum;
import fr.ensim.json.JSONSearchAlbumTracks;
import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Track;
import fr.ensim.xml.deezer.dom.DOMSearchAlbums;
import fr.ensim.xml.deezer.dom.DOMSearchAlbumTracks;
import fr.ensim.xml.deezer.sax.SAXSearchAlbums;
import fr.ensim.xml.deezer.stax.HtmlAlbum;
import fr.ensim.xml.deezer.stax.StAXHtmlAlbum;


/**
 * @author Denis Apparicio
 * 
 */
public class Runner {

	public Runner() {
		// configuration du proxy et des logs
		DOMConfigurator.configure("log4J.xml");
		ProxyConfiguration.configure();
	}
	
	public File start(String searchString, boolean useCustom)
	{
		Logger log = Logger.getLogger(Runner.class);
		
		FileOutputStream out = null;

		try {
			List<Album> listAlbum = new JSONSearchAlbum().find(searchString, false);
			
			for(int i = 0; i < listAlbum.size(); i++)
			{
				listAlbum.get(i).setTracks(JSONSearchAlbumTracks.find(listAlbum.get(i).getId()));
			}
			
			File fileHtml = new File(listAlbum.get(0).getArtist().getName() + ".html");
			out = new FileOutputStream(fileHtml);
			
			if(useCustom)
			{
				HtmlAlbum.write(listAlbum, out);
			}
			else
			{
				StAXHtmlAlbum.write(listAlbum, out);
			}
			

			out.close();
			
			if(fileHtml.isFile())
			{
				return fileHtml;
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
		
		return null;
	}
	
	public File start(String searchString, boolean useDom, boolean useCustom)
	{

		Logger log = Logger.getLogger(Runner.class);

		FileOutputStream out = null;

		try {
			List<Album> listAlbum;
			
			//listAlbum = new SAXSearchAlbums().find(args);
			listAlbum = new DOMSearchAlbums().find(searchString, true);

			// recuperation des titres de l album
			for(int i = 0; i < listAlbum.size(); i++)
			{
				listAlbum.get(i).setTracks(DOMSearchAlbumTracks.find(listAlbum.get(i).getId()));
			}

			// Ecriture de la page html
			File fileHtml = new File(listAlbum.get(0).getArtist().getName() + ".html");
			out = new FileOutputStream(fileHtml);
			
			if(useCustom)
			{
				HtmlAlbum.write(listAlbum, out);
			}
			else
			{
				StAXHtmlAlbum.write(listAlbum, out);
			}
			
			out.close();

			// Ouverture de la page
			if (fileHtml.isFile()) {
				return fileHtml;
				/*if (Desktop.isDesktopSupported()
						&& Desktop.getDesktop().isSupported(Action.BROWSE)) {
					Desktop.getDesktop().browse(fileHtml.toURI());
				}*/
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
		
		return null;
	}
}
