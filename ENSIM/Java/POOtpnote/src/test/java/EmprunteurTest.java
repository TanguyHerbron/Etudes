// Vos imports ici

import entity.Empruntable;
import entity.Emprunteur;
import material.UC;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;

public class EmprunteurTest {
    static Emprunteur e1;

    @Before
    public void setUp() {
        e1 = new Emprunteur();
    }

    @Test
    public void ajouterAuStock() {
        int stock = e1.listeMateriel().size();
        e1.ajouterAuStock(new UC());

        Assert.assertEquals("ajouterAuStock: fail", stock+1, e1.listeMateriel().size());
    }

    //J'ai ici modifié le test unitaire car mes stocks sont initialisés à la création de mes entreprises.
    //J'utilise aussi la méthode ajouterAuStock plutôt que la méthode générique add parce que ma variable stock est privée.
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
