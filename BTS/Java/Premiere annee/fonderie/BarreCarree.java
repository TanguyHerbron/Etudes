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
public class BarreCarree extends Barre{
    
    private double cote;

    public BarreCarree() {
        super();
        this.cote = 3.25;
        System.out.println("Constructeur defaut BarreCarre");
    }

    public BarreCarree(double cote, double densite, double longueur, String reference) {
        super(densite, longueur, reference);
        this.cote = cote;
        System.out.println("Constructeur parametre et super parametres BarreCarre");
    }

    public BarreCarree(BarreCarree autreBarre) {
        super(autreBarre);
        this.cote = autreBarre.cote;
        System.out.println("Constructeur copie BarreCarre");
    }
    
    double calculerMasse()
    {
        return longueur*densite*(cote*cote);
    }
    
}
