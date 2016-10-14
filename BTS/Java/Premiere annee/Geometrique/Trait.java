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
public class Trait {
    
    private int departX;
    private int departY;
    private int arriveX;
    private int arriveY;
    private boolean pointille;
    private int epaisseur;
    
    Trait()
    {
        departX = 1;
        departY = 2;
        arriveX = 3;
        arriveY = 4;
        pointille = false;
        epaisseur = 2;
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
    
}
