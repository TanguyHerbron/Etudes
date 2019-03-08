package fr.ensim.dp.cache.handler;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.SecretKeySpec;
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;

public class EncryptHandler extends Handler {

    @Override
    public byte[] doAdd(String key, byte[] buf) {

        byte[] bufEncrypt = null;
        try {
            Cipher cipher = Cipher.getInstance("AES");

            SecretKeySpec skeySpec = new SecretKeySpec("Hello world11111".getBytes(StandardCharsets.UTF_8), "AES");

            cipher.init(Cipher.ENCRYPT_MODE, skeySpec);

            bufEncrypt = cipher.doFinal(buf);

        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException | BadPaddingException | IllegalBlockSizeException e) {
            e.printStackTrace();
        }

        if(nextHandler != null)
        {
            return nextHandler.doAdd(key, bufEncrypt);
        }

        return bufEncrypt;
    }

    @Override
    public byte[] doRetrieve(String key, byte[] buf) {

        if(nextHandler != null)
        {
            buf = nextHandler.doRetrieve(key, buf);
        }

        try {
            Cipher cipher = Cipher.getInstance("AES");

            SecretKeySpec skeySpec = new SecretKeySpec("Hello world11111".getBytes(StandardCharsets.UTF_8), "AES");

            cipher.init(Cipher.DECRYPT_MODE, skeySpec);

            buf = cipher.doFinal(buf);

        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException | BadPaddingException | IllegalBlockSizeException e) {
            e.printStackTrace();
        }

        return buf;
    }
}
