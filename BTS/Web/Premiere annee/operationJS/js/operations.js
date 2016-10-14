/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function multiplication()
{
    //recuperer la valeur de val1
    val1 = document.getElementById("val1").value;
    
    //recuperer la valeur de val2
    val2 = document.getElementById("val2").value;
    
    //multiplication des deux valeurs
    resultat = val1 * val2;
    
    //placer le resultat dans le champ résultat
    window.document.forms["operations"].resMulti.value = resultat; 
}

function addition()
{
    //recuperer la valeur de val3
    val3 = document.getElementById("val3").value;
    
    //recuperer la valeur de val4
    val4 = document.getElementById("val4").value;
    
    //addition des deux valeurs
    resultat0 = parseInt(val3) + parseInt(val4);
    
    //placer le resultat dans le champ résultat
    document.getElementById("resAddi").value = resultat0; 
}