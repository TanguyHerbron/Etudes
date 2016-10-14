/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


$(function () {
   
    
    /*  gestion bordure */
    $("#couleurBordure").change(function () {
        var coul = $("#couleurBordure").val();
        $("#divTest").css("border-color", coul);
    });

    $("#largeurBordure").change(function () {
        var lar = $("#largeurBordure").val();
		var larpx = lar + "px";
        $("#divTest").css("border-width", larpx);
    });

    $("#styleBordure").change(function (){
       var style = $("#styleBordure").val();
        $("#divTest").css("border-style", style);
    });

    $("#courbeBordure").change(function (){
        var courbe = $("#courbeBordure").val();
        var courbepx = courbe + "px";
        $("#divTest").css("border-radius", courbepx);
    });
    
    /*  gestion ombre avec bouton*/
    $("#miseAJour").click(function ()
    {
        var ombre = $("#ombreDecalH").val() + "px " + $("#ombreDecalV").val() + "px " + $("#ombreDistFlou").val() + "px " + $("#ombreTaille").val() + "px " + $("#ombreCouleur").val();
        $("#divTest").css("box-shadow", ombre);
    });
    
    /* gestion ombre dynamique */
    $("#ombreDecalH").change(function ()
    {
        var ombre = $("#ombreDecalH").val() + "px " + $("#ombreDecalV").val() + "px " + $("#ombreDistFlou").val() + "px " + $("#ombreTaille").val() + "px " + $("#ombreCouleur").val();
        $("#divTest").css("box-shadow", ombre);
    });
    
    $("#ombreDecalV").change(function ()
    {
        var ombre = $("#ombreDecalH").val() + "px " + $("#ombreDecalV").val() + "px " + $("#ombreDistFlou").val() + "px " + $("#ombreTaille").val() + "px " + $("#ombreCouleur").val();
        $("#divTest").css("box-shadow", ombre);
    });
    
    $("#ombreDistFlou").change(function ()
    {
        var ombre = $("#ombreDecalH").val() + "px " + $("#ombreDecalV").val() + "px " + $("#ombreDistFlou").val() + "px " + $("#ombreTaille").val() + "px " + $("#ombreCouleur").val();
        $("#divTest").css("box-shadow", ombre);
    });
    
    $("#ombreTaille").change(function ()
    {
        var ombre = $("#ombreDecalH").val() + "px " + $("#ombreDecalV").val() + "px " + $("#ombreDistFlou").val() + "px " + $("#ombreTaille").val() + "px " + $("#ombreCouleur").val();
        $("#divTest").css("box-shadow", ombre);
    });
    
    $("#ombreCouleur").change(function ()
    {
        var ombre = $("#ombreDecalH").val() + "px " + $("#ombreDecalV").val() + "px " + $("#ombreDistFlou").val() + "px " + $("#ombreTaille").val() + "px " + $("#ombreCouleur").val();
        $("#divTest").css("box-shadow", ombre);
    });
    
    /* gestion des parametres du div*/
    $("#tailleDiv").change(function (){
        $("#divTest").css("width", $("#tailleDiv").val() + "px");
        $("#divTest").text($("#textDiv").val());
    });
    
    $("#textDiv").change(function (){
        $("#divTest").text($("#textDiv").val());
    });
});
