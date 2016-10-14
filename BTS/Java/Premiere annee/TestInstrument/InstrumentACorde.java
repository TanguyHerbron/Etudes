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
public class InstrumentACorde extends InstrumentDeMusique{
    
    protected int nombreDeCorde;
    
    public InstrumentACorde()
    {
        super();        
        System.out.println("Constructeur defaut InstrumentACorde");
    }
    
    public InstrumentACorde(String nom, int nombreDeCorde)
    {
        super(nom);
        this.nombreDeCorde = nombreDeCorde;
    }
    
    public InstrumentACorde(InstrumentACorde monInstrument)
    {
        super(monInstrument);
        this.nombreDeCorde = monInstrument.nombreDeCorde;
    }
    
    public void afficher()
    {
        super.afficher();
        System.out.println("Corde(s) = " + nombreDeCorde);
    }

    @Override
    public String toString() {
        return super.toString() + "\n" + "InstrumentACorde{" + "nombreDeCorde=" + nombreDeCorde + '}';
    }

}
