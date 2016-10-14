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
public class Guitare extends InstrumentACorde{
    
    private String modele;
    
    public Guitare()
    {
        super();
      
        System.out.println("Constructeur defaut Guitare");
    }
    
    public Guitare(String nom, int nombreDeCorde, String modele)
    {
        super(nom, nombreDeCorde);
        this.modele = modele;
    }
    
    public Guitare(Guitare maGuitare)
    {
        super(maGuitare);
        this.modele = maGuitare.modele;
    }
    
    public void afficher()
    {
        super.afficher();
        System.out.println("Modele = " + modele);
    }

    @Override
    public String toString() {
        return super.toString() + "\n" + "Guitare{" + "modele=" + modele + '}';
    }
    
}
