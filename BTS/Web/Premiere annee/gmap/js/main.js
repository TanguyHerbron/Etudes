/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$(function () {
    var map = new GMaps({
        div: '#carte',// "carte" est l'id de la div qui affichera la carte
        lat: -12.043333,
        lng: -77.028333
    });
    
    map.addControl({
        position: "top_right",
        content: "Géolocaliser",
        classes: "btn",
        
        events: {
          click: function(){
            GMaps.geolocate({
                success: function(position)
                {
                    map.setCenter(position.coords.latitude, position.coords.longitude);
                    map.addMarker({
                        lat: position.coords.latitude, 
                        lng: position.coords.longitude
                    });
                }
            });
          }
        }
    });
    
    $("#soumettreAdresse").click(function(){
        GMaps.geocode({
            address: $("#adresse").val(), callback: function(results, status)
            {
                if (status === 'OK') {
                    var latlng = results[0].geometry.location;
                    map.setCenter(latlng.lat(), latlng.lng());
                    map.addMarker({
                      lat: latlng.lat(),
                      lng: latlng.lng()
                    });
                  }
            }
        });
    });
});