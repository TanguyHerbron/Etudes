/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$(function () {
    $("#verifNaissance").click(function (){
        dateDeNaissance = $("#dateNaissance").val();
        var exp=new RegExp("^[0-9]{2}\/[0-9]{2}\/[0-9]{4}$", "g");
        if (exp.test(dateDeNaissance))
        {
            alert("Syntaxe correct");
        }
        else
        {
            alert("Syntaxe incorrect");
        }
    });
});