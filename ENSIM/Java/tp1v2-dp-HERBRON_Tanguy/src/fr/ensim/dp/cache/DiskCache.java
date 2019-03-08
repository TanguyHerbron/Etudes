package fr.ensim.dp.cache;

import java.io.*;
import java.util.HashMap;

public class DiskCache extends Cache {

    private static HashMap<String, DiskCache> INSTANCES = new HashMap<>();

    private String mapName;

    public static DiskCache getInstance(String mapName) {
        if (!INSTANCES.containsKey(mapName)) {
            INSTANCES.put(mapName, new DiskCache(mapName));
        }

        return INSTANCES.get(mapName);
    }

    private DiskCache(String mapName) {
        this.mapName = mapName;
    }

    @Override
    public int size() {
        int counter = 0;

        initFolder();

        File folder = new File(mapName);

        try {
            for (File file : folder.listFiles()) {
                FileInputStream fis = new FileInputStream(file);

                int r = fis.read();

                while (r != -1) {
                    counter++;
                    r = fis.read();
                }

                fis.close();
            }
        } catch (IOException e) {
            e.printStackTrace();

            counter = -1;
        }

        return counter;
    }

    private void initFolder() {
        File folder = new File(mapName);

        if (!folder.exists()) {
            folder.mkdirs();
        }
    }


    @Override
    public boolean add(String key, byte[] buf) {

        buf = handler.doAdd(key, buf);

        initFolder();

        FileOutputStream fos = null;
        try {
            fos = new FileOutputStream(mapName + "/" + key);

            fos.write(buf);

            return true;
        } catch (IOException e) {
            e.printStackTrace();

            return false;
        } finally {
            try {
                if(fos != null) fos.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public byte[] retrieve(String key) {
        initFolder();

        FileInputStream fis = null;
        try {
            fis = new FileInputStream(mapName + "/" + key);

            ByteArrayOutputStream bos = new ByteArrayOutputStream();

            byte[] buf = new byte[1024];
            int len;

            while ((len = fis.read(buf)) > 0) {
                bos.write(buf, 0, len);
            }

            return handler.doRetrieve(key, bos.toByteArray());

        } catch (IOException e) {
            e.printStackTrace();
        }
        finally {
            try {
                if (fis != null) fis.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        return null;
    }

    @Override
    public void clear() {
        File folder = new File(mapName);

        if (folder.exists()) {

            for (File file : folder.listFiles()) {
                file.delete();
            }

            folder.delete();
        }
    }
}
