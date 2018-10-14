package fr.ensim.json;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONObject;

import fr.ensim.xml.deezer.AbstractSearchAlbum;
import fr.ensim.xml.deezer.data.Album;
import fr.ensim.xml.deezer.data.Artist;

public class JSONSearchAlbum extends AbstractSearchAlbum {
	private static final Logger LOG = Logger.getLogger(JSONSearchAlbum.class);
	
	public List<Album> readAlbums(InputStream in) throws Exception
	{
		LOG.debug(">>readAlbums");
		
		List<Album> listAlbums = new ArrayList<Album>();
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(in));
		
		String file = "";
		String line;
		
		while((line = reader.readLine()) != null)
		{
			file += line;
		}
		
		JSONObject jsonObject = new JSONObject(file);
		JSONArray dataArray = jsonObject.getJSONArray("data");
		
		for(int i = 0; i < dataArray.length(); i++)
		{
			JSONObject albumObject = dataArray.getJSONObject(i);
			JSONObject artistObject = albumObject.getJSONObject("artist");
			
			Album album = new Album();
			
			album.setId(String.valueOf(albumObject.getInt("id")));
			album.setTitle(albumObject.getString("title"));
			album.setCover(albumObject.getString("cover"));
			
			Artist artist = new Artist();
			
			artist.setId(String.valueOf(artistObject.getInt("id")));
			artist.setName(artistObject.getString("name"));
			artist.setLink(artistObject.getString("link"));
			artist.setPicture(artistObject.getString("picture"));
			
			album.setArtist(artist);
			
			listAlbums.add(album);
		}
		
		LOG.debug("<<readAlbums");
		return listAlbums;
	}
}
