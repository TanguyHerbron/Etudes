/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package porteacode;

import java.util.Scanner;

/**
 *
 * @author therbron
 */
public class PorteACode {

    /**
     * @param args the command line arguments
     */
    static int essais;
    
    public static void main(String[] args) 
    {
        // TODO code application logic here
        int[] monCode = {8, 4, 5, 4};
        int[] leCodeEntre = new int[4];
        
        while(essais < 3)
        {
            System.out.print("Saisissez le code :");
            Scanner sc = new Scanner(System.in);

            for(int i = 0; i < monCode.length; i++)
            {
                leCodeEntre[i] = sc.nextInt();
                checkCode(monCode[i], leCodeEntre[i]);
            }

            System.out.println("Code correct");
        }
        System.out.println("Nombre d'essais autorisés dépassé.");
        System.exit(0);

    }
    
    public static void checkCode(int chiffreCorrect, int chiffreEntre)
    {
        if(chiffreCorrect != chiffreEntre)
        {
            System.out.println("Code incorrect");
            essais++;
            PorteACode.main(null);
        }
    }
    
}
