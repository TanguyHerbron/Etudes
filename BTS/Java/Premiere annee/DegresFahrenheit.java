/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package degres;

import java.util.Scanner;

/**
 *
 * @author therbron
 */
public class Degres {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int fahrenheit;
        System.out.print("Température en Fahrenheit :");
        Scanner sc = new Scanner(System.in);
        fahrenheit = sc.nextInt();
        System.out.println(fahrenheit + " en celcius donne " + (5.0/9.0)*(fahrenheit - 32));
    }
    
}
