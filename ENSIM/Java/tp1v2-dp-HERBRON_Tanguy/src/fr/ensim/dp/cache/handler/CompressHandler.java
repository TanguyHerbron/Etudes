package fr.ensim.dp.cache.handler;

import fr.ensim.dp.util.LoggerUtil;
import org.apache.log4j.Logger;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.zip.DataFormatException;
import java.util.zip.Deflater;
import java.util.zip.Inflater;

public class CompressHandler extends Handler {

    private static final Logger LOG = LoggerUtil.getLogger();

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                                                                              //
    //      Despite the provided utility class, I chose to use an other solution in order to learn something new    //
    //      This solution makes the compressed data bigger if it's a small buffer                                   //
    //      However, the same problem applies for the provided utility class but with even bigger compressed data   //
    //      This solution : 16 bytes to 25 bytes                                                                    //
    //      Utility class : 16 bytes to 37 bytes                                                                    //
    //      It might change in the future if the other algorithm is better for bigger data                          //
    //                                                                                                              //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    @Override
    public byte[] doAdd(String key, byte[] buf) {

        LOG.debug("Compressing " + buf.length + " bytes");

        Deflater deflater = new Deflater();
        deflater.setInput(buf);

        ByteArrayOutputStream outputStream = new ByteArrayOutputStream(buf.length);
        deflater.finish();

        byte[] tempBuffer = new byte[1024];
        while (!deflater.finished())
        {
            int count = deflater.deflate(tempBuffer);
            outputStream.write(tempBuffer, 0, count);
        }

        try {
            outputStream.close();

            buf = outputStream.toByteArray();

            LOG.debug("Data compressed into : " + buf.length + " bytes");
        } catch (IOException e) {
            e.printStackTrace();
        }

        if(nextHandler != null)
        {
            return nextHandler.doAdd(key, buf);
        }

        return buf;
    }

    @Override
    public byte[] doRetrieve(String key, byte[] buf) {

        if(nextHandler != null)
        {
            buf = nextHandler.doRetrieve(key, buf);
        }

        LOG.debug("Decompressing " + buf.length + " bytes");

        Inflater inflater = new Inflater();
        inflater.setInput(buf);

        ByteArrayOutputStream outputStream = new ByteArrayOutputStream(buf.length);

        byte[] buffer = new byte[1024];
        try {

            while (!inflater.finished()) {
                int count = inflater.inflate(buffer);
                outputStream.write(buffer, 0, count);
            }

            outputStream.close();
        } catch (DataFormatException | IOException e) {
            e.printStackTrace();
        }

        buf = outputStream.toByteArray();

        LOG.debug("Data decompressed into : " + buf.length + " bytes");

        return buf;
    }
}
