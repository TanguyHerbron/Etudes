import entity.Agence;
import entity.Empruntable;
import entity.Emprunteur;
import material.CasqueAvecMicro;
import material.TELPortable;
import material.UC;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class AgenceTest {

    Agence a1;
    Agence a2;

    @Before
    public void setUp() {
        a1 = new Agence("Le Mans");
        a2 = new Agence("Paris");
    }

    @Test
    public void compareAgence() {
        Empruntable e1 = new UC();
        Empruntable e2 = new CasqueAvecMicro();
        Empruntable e3 = new TELPortable();

        e1.declarerDefectueux();

        a1.ajouterAuStock(e1);
        a2.ajouterAuStock(e2);
        a2.ajouterAuStock(e3);

        //Test si a1 a plus d'object défectueux que a2
        Assert.assertEquals("compareTo: fail", a1.compareTo(a2) == 1, true);
    }
}
