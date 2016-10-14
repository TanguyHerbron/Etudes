/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jhms;

import java.util.Scanner;

/**
 *
 * @author therbron
 */
public class Jhms {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int seconde;
        int minute;
        int heure;
        int jour;
        
        System.out.print("Nombre de secondes :");
        Scanner sc = new Scanner(System.in);
        seconde = sc.nextInt();
        
        minute = seconde / 60;
        seconde %= 60;
        
        heure = minute / 60;
        minute %= 60;
        
        jour = heure / 24;
        heure %= 24;        
        
        System.out.println("Il y a " + jour + " jour(s), " + heure + " heur(s), " + minute + " minute(s) et " + seconde + " seconde(s).");
    }
    
}
