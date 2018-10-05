package fr.ensim.xml.deezer.sax;

import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Artist;

/**
 * @author Denis Apparicio
 * 
 */
public class SAXSearchAlbumsHandler extends DefaultHandler {
	private static final Logger LOG       = Logger.getLogger(SAXSearchAlbumsHandler.class);

	private List<Album>   listAlbum = new ArrayList<Album>();
	private String val;
	private Album buildingAlbum;
	private Artist buildingArtist;
	private boolean isArtist;

	/**
	 * Restitue la liste des albums.
	 * 
	 * @return la liste des albums.
	 */
	public List<Album> getListAlbum() {
		return listAlbum;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.xml.sax.helpers.DefaultHandler#startElement(java.lang.String,
	 * java.lang.String, java.lang.String, org.xml.sax.Attributes)
	 */
	@Override
	public void startElement(String uri,
			String localName,
			String qName,
			Attributes attributes) throws SAXException {

		if(localName.equals("album"))
		{		  
			buildingAlbum = new Album();
		}
		
		if(localName.equals("artist"))
		{
			buildingArtist = new Artist();
			isArtist = true;
		}
	}

	/*
	 * (non-Javadoc) BufferedReader
	 * 
	 * @see org.xml.sax.helpers.DefaultHandler#endElement(java.lang.String,
	 * java.lang.String, java.lang.String)
	 */
	@Override
	public void endElement(String uri, String localName, String qName) throws SAXException {
		switch(localName)
		{
		case "album":
			listAlbum.add(buildingAlbum);
			break;
		case "id":
			updateId();
			break;
		case "title":
			if(buildingAlbum != null) buildingAlbum.setTitle(val);
			break;
		case "cover":
			if(buildingAlbum != null) buildingAlbum.setCover(val);
			break;
		case "name":
			buildingArtist.setName(val);
			break;
		case "link":
			updateLink();
			break;
		case "picture":
			buildingArtist.setPicture(val);
			break;
		case "artist":
			buildingAlbum.setArtist(buildingArtist);
			isArtist = false;
			break;
		}
	}
	
	private void updateLink()
	{
		if(isArtist)
		{
			buildingArtist.setLink(val);
		}
	}
	
	private void updateId()
	{
		if(isArtist)
		{
			buildingArtist.setId(val);
		}
		else
		{
			buildingAlbum.setId(val);
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.xml.sax.helpers.DefaultHandler#characters(char[], int, int)
	 */
	@Override
	public void characters(char[] ch, int start, int length) throws SAXException {
		val = new String(ch, start, length);
	}
}
