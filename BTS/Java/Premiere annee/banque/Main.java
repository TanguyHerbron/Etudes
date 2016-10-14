/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package banque;

import java.util.Scanner;

/**
 *
 * @author therbron
 */
public class Main {
    
    public static void main(String[] args) 
    {
        int choix;
        CompteBancaire monCompte = new CompteBancaire(-1000,150);
        
        do
        {
            System.out.println("Que voulez-vous faire ?");
            System.out.println("1 - Déposer de l'argent");
            System.out.println("2 - Retirer de l'argent");
            System.out.println("3 - Modifier l'autorisation de découvert");
            System.out.println("4 - Afficher le compte");
            System.out.println("5 - Quitter");

            Scanner sc = new Scanner(System.in);
            choix = sc.nextInt();
            
            switch(choix)
            {
                case 1:
                    System.out.println("Combien voulez-vous déposer ?");
                    monCompte.deposerArgent(sc.nextFloat());
                    break;
                case 2:
                    System.out.println("Combien voulez-vous retirer ?");
                    monCompte.retirerArgent(sc.nextFloat());
                    break;
                case 3:
                    System.out.println("Quel est le nouveau montant du découvert autorisé ?");
                    monCompte.changerDecouvert(sc.nextFloat());
                    break;
                case 4:
                    monCompte.afficherCompte();
                    break;
                case 5:
                    System.out.println("Au revoir.");
                    break;
                default:
                    System.out.println("Choix incorrecte.");
                    break;
            }            
        }while(choix != 5);
    }
    
}
