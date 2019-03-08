package fr.ensim.dp.util;

import org.apache.log4j.Logger;
import org.apache.log4j.xml.DOMConfigurator;

/**
 * Classe Utilitaire pour récupérer un logger. 
 * 
 * @author Denis Apparicio.
 * @version 1.0
 * 
 */
public final class LoggerUtil {

  static {
    DOMConfigurator.configure("log4j.xml");
  }

  /**
   * Constructeur privé pour éviter la création d'objet.
   */
  private LoggerUtil() {
  }

  /**
   * @return Restitue le logger pour la classe appelante.
   */
  public static Logger getLogger() {
    // Le 2nd element de la stacktrace correspond a la trace appelante.
    String clazzName = new Exception().getStackTrace()[1].getClassName();
    return Logger.getLogger(clazzName);
  }
}
