package fr.ensim.xml.deezer.data;

/**
 * 
 * @author Denis Apparicio
 *
 */
public class Track {

  private String title;

  private String preview;
 
  public Track() {
    super();
  }

  public Track(String title, String preview) {
    super();
    this.title = title;
    this.preview = preview;
  }

  public String getTitle() {
    return title;
  }

  public void setTitle(String title) {
    this.title = title;
  }

  public String getPreview() {
    return preview;
  }

  public void setPreview(String preview) {
    this.preview = preview;
  }

}
