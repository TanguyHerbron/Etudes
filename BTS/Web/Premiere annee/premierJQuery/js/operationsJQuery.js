/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$(function ()
{
    $("#egalMulti").click(function ()
    {
        val1=$("#val1").val();
        val2=$("#val2").val();
        
        resultat=val1*val2;
        
        $("#resMulti").val(resultat);
    });
    
    $("#egalAddi").click(function ()
    {
        val3=$("#val3").val();
        val4=$("#val4").val();
        resultat=parseInt(val3) + parseInt(val4);
        $("#resAddi").val(resultat);
    });
});