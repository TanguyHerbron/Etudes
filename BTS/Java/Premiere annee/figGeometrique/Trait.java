/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package figGeometrique;

/**
 *
 * @author therbron
 */
public class Trait {
    
    final private double departX;
    final private double departY;
    final private double arriveX;
    final private double arriveY;
    final private boolean pointille;
    final private double epaisseur;
    
    Trait()
    {
        departX = 1;
        departY = 2;
        arriveX = 3;
        arriveY = 4;
        pointille = false;
        epaisseur = 2;
    }
    
    Trait(Point p1, Point p2, boolean pointille, double epaisseur)
    {
        departX = p1.getX();
        departY = p1.getY();
        arriveX = p2.getX();
        arriveY = p2.getY();
        this.pointille = pointille;
        this.epaisseur = epaisseur;
    }
    
    Trait(int departX, int departY, int arriveX, int arriveY, boolean pointille, int epaisseur)
    {
        this.departX = departX;
        this.departY = departY;
        this.arriveX = arriveX;
        this.arriveY = arriveY;
        this.pointille = pointille;
        this.epaisseur = epaisseur;
    }
    
    public double calculerLongueur()
    {
        double longueur;
        longueur = Math.sqrt((arriveX - departX) * (arriveX - departX) + (arriveY - departY) * (arriveY - departY));
        return longueur;
    }
    
    public void afficherLongueur()
    {
        System.out.println("Longueur = " + calculerLongueur());
    }
}
