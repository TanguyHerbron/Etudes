/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package borneparking;

/**
 *
 * @author therbron
 */
public class Curseur {
    
    int positionX;
    int positionY;
    
    Curseur()
    {
        positionX = 0;
        positionY = 0;
    }
    
    void deplacerCurseur(int dx, int dy)
    {
        positionX += dx;
        positionY += dy;
    }
    
    void afficherCurseur()
    {
        System.out.print("|");
    }
}
