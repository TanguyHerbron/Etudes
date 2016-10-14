/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestInstrument;

/**
 *
 * @author therbron
 */
public class InstrumentDeMusique {
    protected String nom;
    
    public InstrumentDeMusique()
    {
        nom = "Guitarette";
        System.out.println("Constructeur defaut InstrumentDeMusique");
    }
    
    public InstrumentDeMusique(String nom)
    {
        this.nom = nom;
    }
    
    public InstrumentDeMusique(InstrumentDeMusique monInstrument)
    {
        this.nom = monInstrument.nom;
    }
    
    public void afficher()
    {
        System.out.println("Nom = " + nom);
    }

    @Override
    public String toString() {
        return "InstrumentDeMusique{" + "nom=" + nom + '}';
    }    
    
}
