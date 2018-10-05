package fr.ensim.xml.deezer.stax;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.NavigableMap;

import javax.xml.stream.XMLStreamException;

import org.apache.log4j.Logger;

import com.hp.gagawa.java.Document;
import com.hp.gagawa.java.DocumentType;
import com.hp.gagawa.java.elements.A;
import com.hp.gagawa.java.elements.Body;
import com.hp.gagawa.java.elements.Div;
import com.hp.gagawa.java.elements.Head;
import com.hp.gagawa.java.elements.Img;
import com.hp.gagawa.java.elements.Link;
import com.hp.gagawa.java.elements.Script;
import com.hp.gagawa.java.elements.Style;

import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Track;

/**
 * @author Denis Apparicio
 * 
 */
public class HtmlAlbum {
  private static Logger log = Logger.getLogger(HtmlAlbum.class);
 
  /**
   * Ecriture de la page HTML avec StAX.
   * 
   * @param album
   * @param out
   * @throws XMLStreamException
   * @throws IOException
   */
  public static void write(List<Album> albums, OutputStream outputStream) throws XMLStreamException,
                                                                  IOException {
    log.debug(">>write");
    
    Document document = new Document(DocumentType.HTMLTransitional);
    
    Head head = new Head();
    
    Link cssLink = new Link();
    cssLink.setRel("stylesheet").setHref("https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css");
    Script matScript = new Script(null);
    matScript.setSrc("https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js");
    
    head.appendChild(cssLink);
    head.appendChild(matScript);
    
    Body body = new Body();
    Div navDiv = new Div();
    navDiv.appendText(
    		"<nav style=\"background-color: #3A3A3A\">\r\n" + 
    		"    <div class=\"nav-wrapper\">\r\n" + 
    		"      <a href=\"#\" class=\"brand-logo\">" + albums.get(0).getArtist().getName() + "</a>\r\n" + 
    		"    </div>\r\n" + 
    		"  </nav>");
    
    body.appendChild(navDiv);
    
    Div container = new Div();
    container.setCSSClass("container");
    
    int i = 0; 
    
    while(i < albums.size())
    {
    	Div row = new Div();
    	row.setCSSClass("row");
    	
    	row.appendChild(createAlbumCard(albums.get(i).getTitle()
    			, albums.get(i).getCover()
    			, albums.get(i).getTracks()));
    	
    	if(albums.size() > i+1)
    	{
    		i++;

    		row.appendChild(createAlbumCard(albums.get(i).getTitle()
        			, albums.get(i).getCover()
        			, albums.get(i).getTracks()));
    	}
    	
    	i++;
    	
    	container.appendChild(row);
    }
    
    body.appendChild(container);
    
    document.head.appendChild(head);
    document.body.appendChild(body);

    PrintWriter p = new PrintWriter(outputStream);
    p.write(document.write());
    p.close();
    
    log.debug("<<write");
  }
  
  private static Div createAlbumCard(String title, String cover, List<Track> tracks)
  {	  
	  Div div = new Div().setCSSClass("col s12 m6").appendText(
			  "      <div class=\"card blue-grey darken-1\">\r\n" + 
			  "        <div class=\"card-content white-text\">\r\n" + 
			  "           <ul class=\"collection with-header blue-grey darken-1\">\r\n" + 
			  "             <li class=\"collection-header blue-grey darken-1\">" +
			  "               <div>" +
			  "                 <img class=\"responsive-img circle\" style=\"max-height: 50px; max-width: 50px\" src=\"" + cover + "\">" +
			  "                 <span class=\"card-title\" style=\"display: inline-block;\">" + title + "</span>\r\n" + 
			  "               </div>" +
			  "             </li>\r\n");
	  
	  for(int i = 0; i < tracks.size(); i++)
	  {
		  div.appendText("<li class=\"collection-item blue-grey darken-1\"><span>" + tracks.get(i).getTitle() + "</span>"
		  		+ "<audio controls style=\"display: block\">"
		  		+ "  <source src=\"" + tracks.get(i).getPreview() + "\" type=\"audio/mpeg\">"
		  		+ "</li>\r\n");
	  }
	  
	  div.appendText("</div></div>");
	  
	  return div;
  }
}
