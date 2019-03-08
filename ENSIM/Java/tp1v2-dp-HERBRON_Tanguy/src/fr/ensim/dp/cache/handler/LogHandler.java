package fr.ensim.dp.cache.handler;

import fr.ensim.dp.util.LoggerUtil;
import org.apache.log4j.Logger;

public class LogHandler extends Handler {

    private static final Logger LOG = LoggerUtil.getLogger();

    @Override
    public byte[] doAdd(String key, byte[] buf) {

        LOG.debug("Writing " + buf.length + " bytes in memory at index " + key);

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

        LOG.debug("Retrieved " + buf.length + " bytes from memory cache from index " + key);

        return buf;
    }
}
