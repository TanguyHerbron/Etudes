package fr.ensim.dp.cache;

import fr.ensim.dp.cache.handler.CompressHandler;
import fr.ensim.dp.cache.handler.CountHandler;
import fr.ensim.dp.cache.handler.EncryptHandler;
import fr.ensim.dp.cache.handler.LogHandler;
import fr.ensim.dp.util.LoggerUtil;
import org.apache.log4j.Logger;
import org.junit.Test;

import static org.junit.Assert.*;

public class DiskCacheTest {

    private static final Logger LOG = LoggerUtil.getLogger();

    private byte[] buffer = {1, 2, 3};
    private byte[] buffer2 = {3, 5, 6, 7, 8, 9};

    @Test
    public void test() {
        LOG.debug("Testing DiskCache");

        DiskCache diskCache = DiskCache.getInstance("landscape");

        LogHandler logHandler =  new LogHandler();
        CountHandler countHandler = new CountHandler();
        EncryptHandler encryptHandler = new EncryptHandler();
        CompressHandler compressHandler = new CompressHandler();

        logHandler.nextHandler = countHandler;
        countHandler.nextHandler = encryptHandler;
        encryptHandler.nextHandler = compressHandler;

        diskCache.handler = logHandler;

        DiskCache diskCache1 = DiskCache.getInstance("landscape");
        DiskCache diskCache2 = DiskCache.getInstance("magnik");

        assertNotNull(diskCache);
        assertEquals(diskCache, diskCache1);
        assertNotEquals(diskCache, diskCache2);
        assertNotEquals(diskCache1, diskCache2);

        diskCache.clear();
        diskCache1.clear();
        diskCache2.clear();

        diskCache.add("FIRSTTILE", buffer);
        diskCache.add("SECONDBUFFER", buffer2);

        //Cannot be true because the encryption, if applied, changes the size of
        //the buffer stored in memory, which is computed here
        assertNotEquals(buffer.length + buffer2.length, diskCache.size());

        assertArrayEquals(buffer, diskCache.retrieve("FIRSTTILE"));
        assertArrayEquals(buffer2, diskCache.retrieve("SECONDBUFFER"));

        diskCache.clear();

        assertEquals(0, diskCache.size());
        assertEquals(0, diskCache1.size());

        LOG.debug("End of DiskCache test");
    }

}