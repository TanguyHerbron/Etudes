package fr.ensim.dp.cache;

public class CacheFactory implements ICacheFactory {

    private static CacheFactory INSTANCE;

    public static CacheFactory getInstance()
    {
        if(INSTANCE == null)
        {
            INSTANCE = new CacheFactory();
        }

        return INSTANCE;
    }

    public Cache getMemoryCache()
    {
        return MemoryCache.getInstance();
    }

    public Cache getDiskCache(String mapName)
    {
        return DiskCache.getInstance(mapName);
    }
}
