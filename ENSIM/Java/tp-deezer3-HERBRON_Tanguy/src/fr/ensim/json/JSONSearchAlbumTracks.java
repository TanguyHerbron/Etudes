package fr.ensim.json;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.apache.log4j.Logger;
import org.json.JSONArray;
import org.json.JSONObject;
import org.w3c.dom.Document;
import org.xml.sax.SAXException;

import fr.ensim.xml.deezer.data.Track;

public class JSONSearchAlbumTracks {
	private static Logger LOG = Logger.getLogger(JSONSearchAlbumTracks.class);

	public static List<Track> find(String id) throws IOException, ParserConfigurationException, SAXException {
		LOG.debug(">>albums");

		// Constitution de l'URL
		StringBuilder sUrl = new StringBuilder();
		sUrl.append("http://api.deezer.com/2.0/album/");
		sUrl.append(id);

		URL url = new URL(sUrl.toString());

		LOG.debug(url);

		HttpURLConnection cnx = (HttpURLConnection) url.openConnection();
		cnx.setConnectTimeout(5000);
		cnx.setReadTimeout(5000);
		cnx.setRequestMethod("GET");
		cnx.setDoInput(true);
		cnx.addRequestProperty("Accept-Language", "en;q=0.6,en-us;q=0.4,sv;q=0.2");

		try {
			if (cnx.getResponseCode() == HttpURLConnection.HTTP_OK) {
				return find(cnx.getInputStream());
			}
		} finally {
			cnx.disconnect();
		}

		LOG.debug("<<albums");
		return null;
	}

	protected static List<Track> find(InputStream in) throws SAXException, ParserConfigurationException, IOException {
		LOG.debug(">>find");

		ArrayList<Track> listTracks = new ArrayList<Track>();

		BufferedReader reader = new BufferedReader(new InputStreamReader(in));
		
		String file = "";
		String line;
		
		while((line = reader.readLine()) != null)
		{
			file += line;
		}
		
		JSONObject jsonObject = new JSONObject(file);
		JSONObject tracksDataObject = jsonObject.getJSONObject("tracks");
		JSONArray dataArray = tracksDataObject.getJSONArray("data");
		
		for(int i = 0; i < dataArray.length(); i++)
		{
			JSONObject trackObject = dataArray.getJSONObject(i);
			Track track = new Track();
			
			track.setPreview(trackObject.getString("preview"));
			track.setTitle(trackObject.getString("title"));
			
			listTracks.add(track);
		}

		LOG.debug(">>find");
		return listTracks;
	}
}
