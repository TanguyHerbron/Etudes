import exception.LimiteVisiteurException;

import java.util.Arrays;

import static org.junit.Assert.*;

public class AppTest {

    public static void main(String[] args)
    {
        Zoo zoo = new Zoo();

        Chien chien = new Chien();

        zoo.nouvelAnimal(chien);

        for(int i = 0; i < 20; i++)
        {
            try {
                zoo.nouveauVisiteur();
            } catch (LimiteVisiteurException e) {
                System.out.println("Trop de visiteurs " + Arrays.toString(e.getStackTrace()));
            } finally {
                System.out.println(">> " + zoo.getNombreVisiteur() + "/" + zoo.getLimiteVisiteur());
            }
        }
    }

}