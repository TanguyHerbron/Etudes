<?php

require_once './manipBD.inc.php';

function getVille($codepostal){
    $bdd = connexionBD();
    
    $requete = $bdd->prepare("select ville_nom, ville_id from villes where ville_code_postal like :codepostal order by ville_nom;");
    $requete->bindParam(":codepostal", $codepostal);
    $requete->execute() or die(print_r($requete->errorInfo()));
    
    $tab_nom_ville = array();
    
    while($tab = $requete->fetch())
    {
        array_push ($tab_nom_ville, array('ville_nom'=> utf8_encode($tab['nom']), 'ville_id'=>$tab['id']));
    }
    
    $requete->closeCursor();
    
    echo json_encode($tab_nom_ville);
}