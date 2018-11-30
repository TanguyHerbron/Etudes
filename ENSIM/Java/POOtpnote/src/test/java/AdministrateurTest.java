// Vos imports

import entity.*;
import material.Clavier;
import material.Ecran;
import material.Souris;
import material.UC;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class AdministrateurTest {
    Entreprise e;
    Agence a1, a2;
    Empruntable e1, e2, e3, e4, e5, e6;
    Employe admin, emp1, emp2, emp3, emp4;

    @Before
    public void setUp() throws Exception {

        e = new Entreprise("Super Entreprise de l'ENSIM");
        a1 = new Agence("Agence du Sud");
        a2 = new Agence("Agence du Nord");

        e.getAgences().add(a1);
        e.getAgences().add(a2);

        e1 = new UC(true);
        e2 = new Ecran();
        e3 = new Souris();
        e4 = new Clavier();
        e5 = new Clavier();
        e6 = new Ecran();

        /*
        e.ajouterAuStock(e1);
        e.ajouterAuStock(e2);
        e.ajouterAuStock(e3);
        e.ajouterAuStock(e4);
        e.ajouterAuStock(e5);
        e.ajouterAuStock(e6);
        */


        admin = new Administrateur(a1, e);
        emp1 = new Employe(a1, e);
        emp2 = new Employe(a1, e);
        emp3 = new Employe(a2, e);
        emp4 = new Employe(a2, e);

        a1.getEmployes().add(admin);
        a1.getEmployes().add(emp1);
        a1.getEmployes().add(emp2);

        a2.getEmployes().add(emp3);
        a2.getEmployes().add(emp4);
        /*
        e5.declarerDefectueux();
        e6.declarerDefectueux();
        */
    }

    @Test
    public void attribuerMateriel() {

        int stockActuel = admin.listeMateriel().size();
        ((Administrateur) admin).attribuerMateriel(new Ecran(), admin);

        Assert.assertEquals("attribuerMateriel: fail", stockActuel + 1, admin.listeMateriel().size());
    }


    //TODO Détailler modification par rapport au stock entreprise/administrateur (passage d'un stockage chez l'admin à un stockage dans l'entreprise)
    @Test
    public void recupererMateriel() {
        int stockActuel = admin.listeMateriel().size();
        emp1.listeMateriel().add(e1);
        ((Administrateur) admin).recupererMateriel(e1, emp1);

        Assert.assertEquals("recupererMateriel: fail", stockActuel + 1, ((Administrateur) admin).stockEntreprise().size());
    }

    @Test
    public void stockEntreprise() {
        e.listeMateriel().add(e1);
        int stockEntreprise = ((Administrateur) admin).stockEntreprise().size();
        Assert.assertEquals("stock entreprise: fail", 1, stockEntreprise);
    }

    @Test
    public void stockAgence() {
        a1.listeMateriel().add(e1);
        int stockAgence = ((Administrateur) admin).stockAgence().size();
        Assert.assertEquals("stock agence de l'admin: fail", 1, stockAgence);
    }

    @Test
    public void transfererMateriel_envoyeurNaPasObjetTransfere() {
        int stockEmp2 = emp2.listeMateriel().size();
        ((Administrateur) admin).transfererMateriel(emp1, e2, emp2);
        Assert.assertEquals("transfererMateriel (envoyeur n'a pas l'objet transféré): fail", stockEmp2, emp2.listeMateriel().size());
    }

    @Test
    public void transfererMateriel_envoyeurAObjectMaisReserveAgence() {
        int stockEmp2 = emp2.listeMateriel().size();
        a1.listeMateriel().add(e1);

        ((Administrateur) admin).transfererMateriel(a1, e1, emp2);
        Assert.assertEquals("transfererMateriel (envoyeur a l'objet mais transfert réservé agences): fail", stockEmp2, emp2.listeMateriel().size());
    }

    @Test
    public void transfererMateriel_OK() {
        int stockEmp2 = emp2.listeMateriel().size();
        emp1.listeMateriel().add(e2);
        ((Administrateur) admin).transfererMateriel(emp1, e2, emp2);
        Assert.assertEquals("transfererMateriel (transfert OK): fail", stockEmp2 + 1, emp2.listeMateriel().size());
    }


    @Test
    public void supprimerMaterielDefectueuxEntreprise_sansMaterielDefectueux() {
        e.listeMateriel().add(e4);
        e.listeMateriel().add(e5);

        int stockE = e.listeMateriel().size();
        ((Administrateur) admin).supprimerMaterielDefectueuxEntreprise();
        Assert.assertEquals("supprimerMaterielDefectueuxEntreprise_sansMaterielDefectueux: fail", stockE, e.listeMateriel().size());
    }

    @Test
    public void supprimerMaterielDefectueuxEntreprise_avecMaterielDefectueux() {
        e.listeMateriel().add(e4);
        e.listeMateriel().add(e5);
        e5.declarerDefectueux();

        int stockE = e.listeMateriel().size();
        ((Administrateur) admin).supprimerMaterielDefectueuxEntreprise();
        Assert.assertEquals("supprimerMaterielDefectueuxEntreprise_avecMaterielDefectueux: fail", stockE - 1, e.listeMateriel().size());
        for (Empruntable e : e.listeMateriel()) {
            Assert.assertEquals("supprimerMaterielDefectueuxEntreprise_avecMaterielDefectueux: fail car il reste un Empruntable defectueux", false, e.isDefectueux());
        }
    }

    @Test
    public void supprimerMaterielDefectueuxAgence_sansMaterielDefectueux() {
        a1.listeMateriel().add(e4);
        a1.listeMateriel().add(e5);

        int stockA1 = a1.listeMateriel().size();
        ((Administrateur) admin).supprimerMaterielDefectueuxAgence();
        Assert.assertEquals("supprimerMaterielDefectueuxAgence_sansMaterielDefectueux: fail", stockA1, a1.listeMateriel().size());
    }

    @Test
    public void supprimerMaterielDefectueuxAgence_avecMaterielDefectueux() {
        a1.listeMateriel().add(e4);
        a1.listeMateriel().add(e5);
        e5.declarerDefectueux();

        int stockA1 = a1.listeMateriel().size();
        ((Administrateur) admin).supprimerMaterielDefectueuxAgence();
        Assert.assertEquals("supprimerMaterielDefectueuxAgence_avecMaterielDefectueux: fail", stockA1 - 1, a1.listeMateriel().size());
        for (Empruntable e : a1.listeMateriel()) {
            Assert.assertEquals("supprimerMaterielDefectueuxAgence_avecMaterielDefectueux: fail car il reste un Empruntable defectueux", false, e.isDefectueux());
        }
    }

    @Test
    public void achatMateriel()
    {
        int stockA1 = e.listeMateriel().size();
        ((Administrateur) admin).achatDeMateriel(e1);

        Assert.assertEquals("achatDeMateriel: fail", stockA1 + 1, e.listeMateriel().size());
    }
}
