/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$(function ()
{
    // génération de la liste déroulante au chargement de la page

    $.ajax({
        url: 'getUsers.php',
        type: 'GET',
        dataType: 'json',
        success: // si la requete fonctionne, mise à jour de la liste des departements
                function (objetJson) {
                    $.each(objetJson, function (index, ligne) {
                        // index sera id_departement et value sera le nom du departement
                        $("#liste-userAdresse").append('<option value="' + ligne.id + '">' + ligne.nom + ' ' + ligne.prenom + '</option>');
                        $("#liste-userPrenom").append('<option value="' + ligne.id + '">' + ligne.nom + ' ' + ligne.prenom + '</option>');
                    });
                }
    });

});