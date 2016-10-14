/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Geometrique;

/**
 *
 * @author therbron
 */

public class Triangle {
    
    final private int longueurDuCote1;
    final private int longueurDuCote2;
    final private int longueurDuCote3;
    
    Triangle()
    {
        longueurDuCote1 = 5;
        longueurDuCote2 = 5;
        longueurDuCote3 = 5;
    }
    
    Triangle(int longueurDuCote1, int longueurDuCote2, int longueurDuCote3)
    {
        this.longueurDuCote1 = longueurDuCote1;
        this.longueurDuCote2 = longueurDuCote3;
        this.longueurDuCote3 = longueurDuCote3;
    }
}
