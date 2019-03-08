package fr.ensim.dp.cache.handler;

public abstract class Handler {

    public Handler nextHandler;

    public abstract byte[] doAdd(String key, byte[] buf);

    public abstract byte[] doRetrieve(String key, byte[] buf);
}
