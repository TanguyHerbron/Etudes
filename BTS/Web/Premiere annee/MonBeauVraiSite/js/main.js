/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$(function ()
{
    //$.datepicker.regional["fr"];

    $("#ddn").datepicker({
        changeMonth: true,
        changeYear: true,
        yearRange: "-130:+0"
    });

    $("#cp").keyup(function () {
        if ($("#cp").val().length == 5)
        {
            $.ajax({
            url: 'php/getDepartement.php',
            data: $('#cp').serialize(),
            type: 'GET',
            dataType: 'json',
            success:
                    function (objetJson) {
                        $.each(objetJson, function (index, ville) {
                            $("#ville").append('<option value="' + ville.id + '">' + ville.nom + '</option>');
                        });
                    }

        });
        }
        

    });
});