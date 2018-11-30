// Vos imports ici

import entity.Empruntable;
import entity.Emprunteur;
import material.UC;
import org.junit.Assert;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

//TODO Ajouter Log4J

public class EmprunteurTest {
    static Emprunteur e1;

    //TODO Passage de @Before à @BeforeAll + passage de la méthode en static
    @BeforeAll
    public static void setUp() {
        e1 = new Emprunteur();
    }

    @Test
    public void ajouterAuStock() {
        int stock = e1.listeMateriel().size();
        e1.ajouterAuStock(new UC());

        Assert.assertEquals("ajouterAuStock: fail", stock+1, e1.listeMateriel().size());
    }

    //TODO Expliquer la modifification du test unitaire
    @Test
    public void listeMateriel() {
        //e1.stock = new ArrayList<Empruntable>();
        int stock = e1.listeMateriel().size();
        //e1.stock.add(new UC());
        e1.ajouterAuStock(new UC());

        int newStock = e1.listeMateriel().size();

        Assert.assertEquals("listeMateriel: fail", stock+1, newStock);
    }

    @Test
    public void perdreMateriel() {
        Empruntable emprunt1 = new UC();
        e1.listeMateriel().add(emprunt1);

        boolean result = e1.perdreMateriel(emprunt1);

        Assert.assertEquals("perdreMateriel: méthode fail", true, result);
        Assert.assertEquals("perdreMateriel: taille fail", 0, e1.listeMateriel().size());
    }
}
