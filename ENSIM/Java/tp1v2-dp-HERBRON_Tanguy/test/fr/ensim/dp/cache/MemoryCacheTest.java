package fr.ensim.dp.cache;

import fr.ensim.dp.cache.handler.CompressHandler;
import fr.ensim.dp.cache.handler.CountHandler;
import fr.ensim.dp.cache.handler.EncryptHandler;
import fr.ensim.dp.cache.handler.LogHandler;
import fr.ensim.dp.util.LoggerUtil;
import org.apache.log4j.Logger;
import org.junit.Test;

import static org.junit.Assert.*;

public class MemoryCacheTest {

    private static final Logger LOG = LoggerUtil.getLogger();

    private byte[] buffer = {0x01, 0x02, 0x03};
    private byte[] buffer2 = {0x03, 0x05, 0x06, 0x07, 0x08, 0x09};

    @Test
    public void test() {

        LOG.debug("Testing MemoryCache");

        Cache memoryCache = CacheFactory.getInstance().getMemoryCache();

        LogHandler logHandler =  new LogHandler();
        CountHandler countHandler = new CountHandler();
        EncryptHandler encryptHandler = new EncryptHandler();
        CompressHandler compressHandler = new CompressHandler();

        logHandler.nextHandler = countHandler;
        countHandler.nextHandler = encryptHandler;
        encryptHandler.nextHandler = compressHandler;

        memoryCache.handler = logHandler;

        MemoryCache memoryCache1 = MemoryCache.getInstance();

        assertNotNull(memoryCache);
        assertEquals(memoryCache, memoryCache1);


        //Size and add
        memoryCache.add("buffer", buffer);
        memoryCache.add("buffer2", buffer2);

        //Cannot be true because the encryption, if applied, changes the size of
        //the buffer stored in memory, which is computed here
        assertNotEquals(buffer.length + buffer2.length, memoryCache.size());

        //Retrieve test and singleton verification
        assertArrayEquals(buffer, memoryCache.retrieve("buffer"));
        assertArrayEquals(buffer2, memoryCache1.retrieve("buffer2"));

        //Cache verification with singleton last verification
        memoryCache.clear();

        assertEquals(0, memoryCache.size());
        assertEquals(0, memoryCache1.size());

        LOG.debug("End of MemoryCache test");
    }
}