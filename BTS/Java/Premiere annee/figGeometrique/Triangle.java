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

public class Triangle {
    
     private double longueurDuCote1;
     private double longueurDuCote2;
     private double longueurDuCote3;
    
    Triangle()
    {
        longueurDuCote1 = 5;
        longueurDuCote2 = 5;
        longueurDuCote3 = 5;
    }
    
    Triangle(int longueurDuCote1, int longueurDuCote2, int longueurDuCote3)
    {
        this.longueurDuCote1 = longueurDuCote1;
        this.longueurDuCote2 = longueurDuCote2;
        this.longueurDuCote3 = longueurDuCote3;
    }
    
    public double calculerAire()
    {
        double aire;
        double demiPerimetre;
        demiPerimetre =  (longueurDuCote1 + longueurDuCote2 + longueurDuCote3)/2;
        System.out.println(demiPerimetre);
        aire = Math.sqrt(demiPerimetre * (demiPerimetre - longueurDuCote1) * (demiPerimetre - longueurDuCote2) * (demiPerimetre - longueurDuCote3));               
        return aire;
    }
    
    public void afficherAire()
    {
        System.out.println("Aire = " + calculerAire());
    }

    @Override
    public String toString() {
        return "Triangle{" + "longueurDuCote1=" + longueurDuCote1 + ", longueurDuCote2=" + longueurDuCote2 + ", longueurDuCote3=" + longueurDuCote3 + '}';
    }
    
    
}
