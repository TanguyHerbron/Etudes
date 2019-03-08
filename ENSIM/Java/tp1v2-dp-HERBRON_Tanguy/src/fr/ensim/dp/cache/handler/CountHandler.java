package fr.ensim.dp.cache.handler;

import fr.ensim.dp.util.LoggerUtil;
import org.apache.log4j.Logger;

public class CountHandler extends Handler {

    private static final Logger LOG = LoggerUtil.getLogger();
    private int nbWritten = 0;
    private int nbRead = 0;

    @Override
    public byte[] doAdd(String key, byte[] buf) {
        nbWritten++;

        LOG.debug("Nb data written : " + nbWritten);

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

        nbRead++;

        LOG.debug("Nb data read : " + nbRead);

        return buf;
    }
}
