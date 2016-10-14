/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$(function ()
{
    $("#inscription").click(function()
    {        
        if($("#mdp").val() !== $("#mdp2").val())
        {
            $("#mdp").css("border-radius", 5);
            $("#mdp").css("border-color", "#FF0000");
            $("#mdp2").css("border-radius", 5);
            $("#mdp2").css("border-color", "#FF0000");
            $("#erreur").css("visibility", "visible");
        }
    });
});

$(function()
{
    $("#os option").click(function ()
    {
        if($(this).text() === "Sélectionnez un SE")
        {
            $("#version").empty();
        }
        
        if($(this).val() === "win")
        {
            $("#version").empty();
            $("#version").append($("<option>", {value : "xp"}).text("XP"));
            $("#version").append($("<option>", {value : "vista"}).text("Vista"));
            $("#version").append($("<option>", {value : "seven"}).text("Seven"));
        }
        
        if($(this).val() === "lin")
        {
            $("#version").empty();
            $("#version").append($("<option>", {value : "deb"}).text("Debian"));
            $("#version").append($("<option>", {value : "ubu"}).text("Ubuntu"));
            $("#version").append($("<option>", {value : "fedo"}).text("Fedora"));
            $("#version").append($("<option>", {value : "suse"}).text("SuSE"));
            $("#version").append($("<option>", {value : "mint"}).text("Mint"));
        }
        
        if($(this).val() === "mac")
        {
            $("#version").empty();
            $("#version").append($("<option>", {value : "tiger"}).text("Tiger"));
            $("#version").append($("<option>", {value : "leo"}).text("Leopard"));
            $("#version").append($("<option>", {value : "snow"}).text("Snow leopard"));
            $("#version").append($("<option>", {value : "lion"}).text("Lion"));
        }
    });
});