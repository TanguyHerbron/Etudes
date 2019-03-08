package fr.ensim.dp.util;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;

/**
 * @author Denis Apparicio
 * @version 1.0
 */
public class GzipUtil {

  /** Default buffer size */
  private static final int DEFAULT_BUFFER_SIZE = 4096;

  /**
   * Compression d'un buffer
   * 
   * @param uncompressed
   *          le buffer 
   * @return le buffer compressé
   * @throws IOException
   */

  public static final byte[] compress(final byte[] uncompressedBytes) throws IOException {
    ByteArrayOutputStream bos = new ByteArrayOutputStream();
    GZIPOutputStream gzip = new GZIPOutputStream(bos);

    gzip.write(uncompressedBytes, 0, uncompressedBytes.length);
    gzip.close();

    return bos.toByteArray();
  }

  /**
   * Uncompress a previously compressed string; this method is the inverse of
   * the compress method.
   * 
   * @param byte array containing compressed data
   * @return uncompressed string
   * @throws IOException
   *           if the inflation fails
   */

  public static final byte[] uncompress(final byte[] compressed) throws IOException {

    ByteArrayInputStream bais = new ByteArrayInputStream(compressed);
    GZIPInputStream gunzip = new GZIPInputStream(bais);

    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    int len = 0;
    byte[] tempBytes = new byte[DEFAULT_BUFFER_SIZE];
    while ((len = gunzip.read(tempBytes, 0, tempBytes.length)) != -1) {
      baos.write(tempBytes, 0, len);
    }

    return baos.toByteArray();
  }
}
