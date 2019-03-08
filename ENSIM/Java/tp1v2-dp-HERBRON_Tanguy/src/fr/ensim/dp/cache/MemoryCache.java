package fr.ensim.dp.cache;

import java.util.HashMap;

public class MemoryCache extends Cache {

    private static MemoryCache INSTANCE;

    private HashMap<String, byte[]> memoryMap;

    public static MemoryCache getInstance()
    {
        if(INSTANCE == null)
        {
            INSTANCE = new MemoryCache();
        }

        return INSTANCE;
    }

    private MemoryCache() {
        memoryMap = new HashMap<>();
    }

    @Override
    public int size() {
        int size = 0;

        for(String str : memoryMap.keySet())
        {
            size += memoryMap.get(str).length;
        }

        return size;
    }

    @Override
    public boolean add(String key, byte[] buf) {

        buf = handler.doAdd(key, buf);

        memoryMap.put(key, buf);

        return memoryMap.containsKey(key);
    }

    @Override
    public byte[] retrieve(String key) {

        return handler.doRetrieve(key, memoryMap.get(key));
    }

    @Override
    public void clear() {

        memoryMap.clear();
    }
}
