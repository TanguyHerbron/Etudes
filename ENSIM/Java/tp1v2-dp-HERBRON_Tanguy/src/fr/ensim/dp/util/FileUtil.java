package fr.ensim.dp.util;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * @author Denis Apparicio
 * @version 1.0
 */
public final class FileUtil {

  private FileUtil() {
  }

  /**
   * @return Restitue le repertoire home de l'utilisateur.
   */
  public static File userHome() {
    return new File(System.getProperty("user.home"));
  }

  /**
   * Supprime un répertoire.
   * 
   * @param path
   *          le répertoire.
   * @return <code>true</code> si ok
   */
  public static boolean deleteDirectory(File path) {
    if (path.exists()) {
      File[] files = path.listFiles();
      if (files != null) {
        for (File f : files) {
          if (f.isFile()) {
            f.delete();
          }
        }
      }
    }
    return (path.delete());
  }

  /**
   * Restitue la taille d'un répertoire.
   * 
   * @param path
   *          le répertoire.
   * @return la taille d'un répertoire.
   */
  public static long dirLength(File path) {
    long length = 0;
    if (path.exists()) {
      File[] files = path.listFiles();
      if (files != null) {
        for (File f : files) {
          if (f.isFile()) {
            length += f.length();
          }
        }
      }
    }
    return length;
  }

  /**
   * Copie vers un fichier.
   * 
   * @param in
   *          l'inpustream à copier.
   * @param file
   *          la destination.
   */
  public static boolean copy(InputStream in, File file) {
    byte[] buf = new byte[4096];
    int len = -1;

    boolean isOk = false;
    boolean isCopyBegin = false;
    FileOutputStream out = null;
    try {
      out = new FileOutputStream(file);
      isCopyBegin = true;
      while ((len = in.read(buf)) > 0) {
        out.write(buf, 0, len);
      }
      in.close();
      out.close();
      isOk = true;
    }
    catch (Throwable th) {
      isOk = false;
      file.delete();
      try {
        if (out != null) {
          out.close();
        }
      }
      catch (IOException ioe) {
      }
      try {
        if (in != null) {
          in.close();
        }
      }
      catch (IOException ioe) {
      }
      // suppression du fichier
      if (isCopyBegin && file.exists()) {
        file.delete();
      }
    }

    return isOk;
  }

  /**
   * @return Lecture d'un fichier dans un tableau de byte.
   */
  public static byte[] readFile(File file) throws IOException {
    FileInputStream fis = null;
    try {
      ByteArrayOutputStream bos = new ByteArrayOutputStream();
      fis = new FileInputStream(file);
      byte[] buf = new byte[1024];
      int len = 0;
      while ((len = fis.read(buf)) != -1) {
        bos.write(buf, 0, len);
      }

      return bos.toByteArray();
    }
    finally {
      if (fis != null) {
        try {
          fis.close();
        }
        catch (IOException e) {
        }
      }
    }
  }
}
