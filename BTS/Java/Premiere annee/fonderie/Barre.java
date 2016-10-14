/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fonderie;

/**
 *
 * @author therbron
 */
public class Barre {
    
    protected double densite;
    protected double longueur;
    protected String reference;
    
    Barre()
    {
        densite = 0.1f;
        longueur = 5;
        reference = "0001";
        System.out.println("Constructeur defaut Barre");
    }
    
    Barre(double densite, double longueur, String reference)
    {
        this.densite = densite;
        this.longueur = longueur;
        this.reference = reference;
        System.out.println("Constructeur parametre Barre");
    }
    
    Barre(Barre autreBarre)
    {
        densite = autreBarre.densite;
        longueur = autreBarre.longueur;
        reference = autreBarre.reference;
        System.out.println("Constructeur copie Barre");
    }
    
    void afficherReference()
    {
        System.out.println("Referenfe = " + reference);
    }
    
}
