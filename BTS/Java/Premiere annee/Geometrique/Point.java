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

public class Point {
    
    private double x;
    private double y;
    
    Point()
    {
        x = 5;
        y = 5;
    }
    
    Point(double x, double y)
    {
        this.x = x;
        this.y = y;
    }
    
    void translater(double dx, double dy)
    {
        x += dx;
        y += dy;
    }
    
    double distance()
    {
        double dist;
        dist = Math.sqrt(x*x+y*y);
        return dist;
    }
    
    void afficher(String nomPoint)
    {
        System.out.println(nomPoint + " x=" + x + " y=" + y);
    }
}
