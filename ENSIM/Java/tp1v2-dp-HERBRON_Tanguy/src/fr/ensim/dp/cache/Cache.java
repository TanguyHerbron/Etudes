package fr.ensim.dp.cache;

import fr.ensim.dp.cache.handler.Handler;

/**
 * @author Denis Apparicio
 */
public abstract class Cache {

    protected Handler handler;

    /**
     * @return Restitue la taille du cache
     */
    protected abstract int size();

    /**
     * Ajoute un tableau de byte dans le cache.
     *
     * @param key clé du buffer à mettre en cache.
     * @param buf le buffer à mettre en cache.
     * @return <code>true</code> si la mise en cache a réussi,
     * <code>false</code> sinon.
     */
    protected abstract boolean add(String key, byte[] buf);

    /**
     * Restitue le buffer en cache.
     *
     * @param key clé du buffer recherchée;
     * @return le buffer en cache ou <code>null</code> si pas de cache
     * trouvé pour cette clé
     */
    protected abstract byte[] retrieve(String key);

    /**
     * Efface le cache.
     */
    protected abstract void clear();


}
