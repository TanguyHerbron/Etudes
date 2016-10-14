/* 
Gestion page avec googlemap
 */



$(function () {
    /***************** options de placement et de zoom **************/
    var mapOptions = {
        center: new google.maps.LatLng(48.004852, 0.199811),
        zoom: 15
    };
    /*****************  creation et affichage de la map **************/
    var map = new google.maps.Map(document.getElementById("map-canvas"),mapOptions);
    
    /*****************  gestion du click sur le bouton dont l'id est afficherLycee **************/    
    $("#afficherLycee").click(function () {        
        
        // creation du localisateur
        var geocoder = new google.maps.Geocoder();
        var address = "Place George Washington, 72000 le mans";
        
        // recentrage de la map par rapport a l'adresse
        // et placement d'un marqueur ouvert avec comme legende la dite adresse
        geocoder.geocode({'address': address, 'region': "FR"}, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK) {

                //formatage de la chaine latitude,longitude
                var latLong = results[0].geometry.location.lat().toFixed(6) + " , " +
                        +results[0].geometry.location.lng().toFixed(6);

                // centrage de la map sur l'adresse
                map.setCenter(results[0].geometry.location);

                // definition des parametres du marqueur
                // (on place le marqueur a l'adresse au niveau de la map)
                marker = new google.maps.Marker({
                    position: results[0].geometry.location,
                    map: map
                });
                
                // placement du marqueur
                marker.setPosition(results[0].geometry.location);

                // creation de l'inforbulle pour le marqueur
                var infowindow = new google.maps.InfoWindow({
                    content: "(1.10, 1.10)"
                });
                // initialisation de l'infobulle du marqueur
                // l'infobulle contiendra l'adresse
                infowindow.setContent("Ici, la connexion est très \"fluide\".");
                
                
                
                if (infowindow) {
                    infowindow.close();
                }

                // affichage de l'infobulle
                infowindow.open(map, marker);
            } 
            else // adresse introuvable
            {
                alert("pas trouve");
            }
        });
    });
    
    /*****************  gestion du click sur le bouton dont l'id est afficherMaison **************/    
    $("#afficherMaison").click(function () {        
        
        // creation du localisateur
        var geocoder = new google.maps.Geocoder();
        var address = "22 rue Jean de la Fontaine, 72000 le mans";
        
        // recentrage de la map par rapport a l'adresse
        // et placement d'un marqueur ouvert avec comme legende la dite adresse
        geocoder.geocode({'address': address, 'region': "FR"}, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK) {

                //formatage de la chaine latitude,longitude
                var latLong = results[0].geometry.location.lat().toFixed(6) + " , " +
                        +results[0].geometry.location.lng().toFixed(6);

                // centrage de la map sur l'adresse
                map.setCenter(results[0].geometry.location);

                // definition des parametres du marqueur
                // (on place le marqueur a l'adresse au niveau de la map)
                marker = new google.maps.Marker({
                    position: results[0].geometry.location,
                    map: map
                });
                
                // placement du marqueur
                marker.setPosition(results[0].geometry.location);

                // creation de l'inforbulle pour le marqueur
                var infowindow = new google.maps.InfoWindow({
                    content: "(1.10, 1.10)"
                });
                // initialisation de l'infobulle du marqueur
                // l'infobulle contiendra l'adresse
                infowindow.setContent("Ici, la connexion c'est... Du 512Ko/s.");
                
                
                
                if (infowindow) {
                    infowindow.close();
                }

                // affichage de l'infobulle
                infowindow.open(map, marker);
            } 
            else // adresse introuvable
            {
                alert("pas trouve");
            }
        });
    });
    
    /*****************  gestion du click sur le bouton dont l'id est soumettreAdresse **************/    
    $("#soumettreAdresse").click(function () {        
        
        // creation du localisateur
        var geocoder = new google.maps.Geocoder();
        var address = $("#adresse").val();
        
        // recentrage de la map par rapport a l'adresse
        // et placement d'un marqueur ouvert avec comme legende la dite adresse
        geocoder.geocode({'address': address, 'region': "FR"}, function (results, status) {
            if (status == google.maps.GeocoderStatus.OK) {

                //formatage de la chaine latitude,longitude
                var latLong = results[0].geometry.location.lat().toFixed(6) + " , " +
                        +results[0].geometry.location.lng().toFixed(6);

                // centrage de la map sur l'adresse
                map.setCenter(results[0].geometry.location);

                // definition des parametres du marqueur
                // (on place le marqueur a l'adresse au niveau de la map)
                marker = new google.maps.Marker({
                    position: results[0].geometry.location,
                    map: map
                });
                
                // placement du marqueur
                marker.setPosition(results[0].geometry.location);

                // creation de l'inforbulle pour le marqueur
                var infowindow = new google.maps.InfoWindow({
                    content: "(1.10, 1.10)"
                });
                // initialisation de l'infobulle du marqueur
                // l'infobulle contiendra l'adresse
                infowindow.setContent($("#adresse").val());
                
                
                
                if (infowindow) {
                    infowindow.close();
                }

                // affichage de l'infobulle
                infowindow.open(map, marker);
            } 
            else // adresse introuvable
            {
                alert("Nous n'avons pas pu trouver " + $("#adresse").val());
            }
        });
    });
});
