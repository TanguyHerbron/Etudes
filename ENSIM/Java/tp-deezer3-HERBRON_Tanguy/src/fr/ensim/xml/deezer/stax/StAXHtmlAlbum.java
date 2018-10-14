package fr.ensim.xml.deezer.stax;

import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.util.List;

import javax.xml.stream.XMLOutputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamWriter;

import org.apache.log4j.Logger;

import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Track;

public class StAXHtmlAlbum {
	private static Logger log = Logger.getLogger(StAXHtmlAlbum.class);
	
	public static void write(List<Album> albums, OutputStream outputStream) throws IOException
	{
		log.debug(">>write");

		XMLOutputFactory factoty = XMLOutputFactory.newInstance();
		FileWriter fileWriter = new FileWriter(albums.get(0).getArtist().getName() + ".html");
		
		try {
			XMLStreamWriter writer = factoty.createXMLStreamWriter(fileWriter);
			writer.writeStartDocument();
			writer.writeStartElement("html");
			writer.writeAttribute("xmlns", "http://www.w3.org/1999/xhtml");
				writer.writeStartElement("head");
					writer.writeStartElement("link");
					writer.writeAttribute("rel", "stylesheet");
					writer.writeAttribute("href", "https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css");
					writer.writeEndElement(); //Close link
					
					writer.writeStartElement("script");
					writer.writeAttribute("src", "https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js");
					writer.writeEndElement(); //Close script
				writer.writeEndElement(); //Close head
				
				writer.writeStartElement("body");
					writer.writeStartElement("div");
						writer.writeStartElement("nav");
						writer.writeAttribute("style", "background-color: #3A3A3A");
							writer.writeStartElement("div");
							writer.writeAttribute("class", "nav-wrapper");
								writer.writeStartElement("a");
								writer.writeAttribute("href", "#");
								writer.writeAttribute("class", "brand-logo");
									writer.writeCharacters(albums.get(0).getArtist().getName());
								writer.writeEndElement(); // Close a
							writer.writeEndElement(); // Close div
						writer.writeEndElement(); // Close nav
					writer.writeEndElement(); // Close div
					writer.writeStartElement("div");
					writer.writeAttribute("class", "container");
					
					generateAlbumElements(writer, albums);
					
					writer.writeEndElement(); // Close div
				writer.writeEndElement(); // Close body
			writer.writeEndElement(); // Close html
			writer.writeEndDocument();
		} catch (XMLStreamException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			fileWriter.close();
		}
	}
	
	private static void generateAlbumElements(XMLStreamWriter writer, List<Album> albums) throws XMLStreamException
	{
		int i = 0;
		
		while(i < albums.size())
		{
			writer.writeStartElement("div");
			writer.writeAttribute("class", "row");
			
			generateAlbumCards(writer 
					, albums.get(i).getTitle()
					, albums.get(i).getCover()
					, albums.get(i).getTracks());
			
			if(albums.size() > i+1)
			{
				i++;
				
				generateAlbumCards(writer 
						, albums.get(i).getTitle()
						, albums.get(i).getCover()
						, albums.get(i).getTracks());
			}
			
			i++;
			
			writer.writeEndElement();
		}
	}
	
	private static void generateAlbumCards(XMLStreamWriter writer, String title, String cover, List<Track> tracks) throws XMLStreamException
	{
		writer.writeStartElement("div");
		writer.writeAttribute("class", "col s12 m6");
			writer.writeStartElement("div");
			writer.writeAttribute("class", "card blue-grey darken-1");
				writer.writeStartElement("div");
				writer.writeAttribute("class", "card-content white-text");
					writer.writeStartElement("ul");
					writer.writeAttribute("class", "collection with-header blue-grey darken-1");
						writer.writeStartElement("li");
						writer.writeAttribute("class", "collection-header blue-grey darken-1");
							writer.writeStartElement("div");
								writer.writeStartElement("img");
								writer.writeAttribute("class", "responsive-img circle");
								writer.writeAttribute("style", "max-height: 50px; max-width: 50px");
								writer.writeAttribute("src", cover);
								writer.writeEndElement(); // Close img
								writer.writeStartElement("span");
								writer.writeAttribute("class", "card-title");
								writer.writeAttribute("style", "display: inline-block;");
								writer.writeCharacters(title);
								writer.writeEndElement(); // Close span
							writer.writeEndElement(); // Close div
						writer.writeEndElement(); // Close li
						
						generateTracks(writer, tracks);
						
					writer.writeEndElement(); // Close ul
				writer.writeEndElement(); // Close div
			writer.writeEndElement(); // Close div
		writer.writeEndElement(); // Close div
	}
	
	private static void generateTracks(XMLStreamWriter writer, List<Track> tracks) throws XMLStreamException
	{
		for(int i = 0; i < tracks.size(); i++)
		{
			writer.writeStartElement("li");
			writer.writeAttribute("class", "collection-item blue-grey darken-1");
				writer.writeStartElement("span");
				writer.writeCharacters(tracks.get(i).getTitle());
				writer.writeEndElement(); // Close span
				writer.writeStartElement("audio controls");
				writer.writeAttribute("style", "display: block");
					writer.writeStartElement("source");
					writer.writeAttribute("src", tracks.get(i).getPreview());
					writer.writeAttribute("type", "audio/mpeg");
					writer.writeEndElement(); // Close source
				writer.writeEndElement(); // Close audio controls
			writer.writeEndElement(); // Close li
		}
	}
}
