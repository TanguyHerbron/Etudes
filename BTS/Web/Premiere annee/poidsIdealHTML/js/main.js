/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$(function(){
    $("#submit").click(function ()
    {
        if($("#donnees").css("display") === "block")
        {
            var poidsIdeal;
            
            $("#donnees").css("display", "none");
            $("#resultat").css("display", "block");
            
            $("#divResult").text("Bonjour " + $("#nom").val() + " " + $("#prenom").val());
            $("#divResult").append("<br/>");
            
            if($("#homme").prop("checked"))
            {
                poidsIdeal = 45.5 + 2.3 * (parseFloat($("#taille").val()) / 0.0254 - 60.0);
            }
            
            if($("#femme").prop("checked"))
            {
                poidsIdeal = 45.5 + 2.3 * (parseFloat($("#taille").val()) / 0.0254 - 60.0);
            }
            
            $("#divResult").append("Votre poids masse corporel est de : " + poidsIdeal);
            
        }
        else
        {
            $("#donnees").css("display", "block");
            $("#resultat").css("display", "none");
        }
    });
});