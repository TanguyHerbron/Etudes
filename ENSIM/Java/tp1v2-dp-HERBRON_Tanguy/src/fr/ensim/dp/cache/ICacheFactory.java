package fr.ensim.dp.cache;

public interface ICacheFactory {

    Cache getMemoryCache();

    Cache getDiskCache(String mapName);
}
