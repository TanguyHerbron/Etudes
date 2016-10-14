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
public class BarreRonde extends Barre{
    
    private double rayon;

    public BarreRonde() {
        super();
        this.rayon = 3;
        System.out.println("Constructeur defaut BarreRonde");
    }

    public BarreRonde(double rayon, double densite, double longueur, String reference) {
        super(densite, longueur, reference);
        this.rayon = rayon;
        System.out.println("Constructeur parametre et super parametres BarreRonde");
    }

    public BarreRonde(BarreRonde autreBarre) {
        super(autreBarre);
        this.rayon = autreBarre.rayon;
        System.out.println("Constructeur copie BarreRonde");
    }
    
    double calculerMasse()
    {
        return longueur*densite*(2*Math.PI*rayon);
    }
    
}
