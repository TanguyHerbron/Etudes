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
public class Afficheur {
    
    int longueur;
    int hauteur;
    int eclairement;
    Curseur monCurseur;
    char display[][];
    
    Afficheur()
    {
        longueur = 16;
        hauteur = 2;
        eclairement = 1;
        monCurseur = new Curseur();
        display = new char[longueur][hauteur];
    }
    
    Afficheur(int longueur, int hauteur)
    {
        this.longueur = longueur;
        this.hauteur = hauteur;
        eclairement = 1;
        monCurseur = new Curseur();
    }
    
    void modifierEclairage(int eclairement)
    {
        this.eclairement = eclairement;
    }
    
    void afficherMessage(String monMessage)
    {
        System.out.print(monMessage);
    }
    
    void afficherCaractere(char car)
    {
        
    }
}
