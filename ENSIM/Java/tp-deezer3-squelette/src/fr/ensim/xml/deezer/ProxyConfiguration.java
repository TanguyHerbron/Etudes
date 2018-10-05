package fr.ensim.xml.deezer;

/**
 * Configuration du proxy pac de l'ensim.
 * 
 * @author Denis Apparicio
 * 
 */
public class ProxyConfiguration {

  private ProxyConfiguration() {
  } 

  /**
   * Configuration du proxy.
   */
  public static void configure() {
    System.setProperty("http.proxyHost", "vproxy.univ-lemans.fr");
    System.setProperty("http.proxyPort", "3128");
  }
}
