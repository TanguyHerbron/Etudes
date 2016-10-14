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
public class BarreRectangle extends Barre{
    
    private double hauteur;
    private double largeur;

    public BarreRectangle() {
        super();
        this.hauteur = 5;
        this.largeur = 4.2;
        System.out.println("Constructeur defaut BarreRectangle");
    }

    public BarreRectangle(double hauteur, double largeur, double densite, double longueur, String reference) {
        super(densite, longueur, reference);
        this.hauteur = hauteur;
        this.largeur = largeur;
        System.out.println("Constructeur parametres et super parametres BarreRectangle");
    }

    public BarreRectangle(BarreRectangle autreBarre) {
        super(autreBarre);
        this.hauteur = autreBarre.hauteur;
        this.largeur = autreBarre.largeur;
        System.out.println("Constructeur copie BarreRectangle");
    }
    
    double calculerMasse()
    {
        return longueur*densite*(hauteur*largeur);
    }
    
}
