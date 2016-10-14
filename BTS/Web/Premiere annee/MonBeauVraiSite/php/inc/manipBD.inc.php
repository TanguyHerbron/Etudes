<?php
require_once("config.inc.php");
function connexionBD() {

	try {
		$bdd = new PDO('mysql:host=' . SERVEURBD . ';dbname=' . NOMDELABASE, LOGIN, MOTDEPASSE);
	} catch (Exception $ex) {
		die('<br />Probleme de connexion serveur BD : ' . $ex->getMessage());
	}
	return $bdd;
}
