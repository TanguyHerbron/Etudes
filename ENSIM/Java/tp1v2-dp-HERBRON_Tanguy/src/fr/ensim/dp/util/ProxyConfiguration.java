package fr.ensim.dp.util;

/**
 * @author Denis Apparicio 
 * 
 */
public class ProxyConfiguration {

  /**
   * Configuration du proxy.
   */
  public static void configure() {
    System.setProperty("http.proxyHost", "vproxy.univ-lemans.fr");
    System.setProperty("http.proxyPort", "3128");
  }
}
