# Projet

Il s'agit d'un projet en JAVA comportant les technologies suivantes :
- Spring
- JPA
- H2
- Hibernate
- Spring Data
- Thymeleaf

# Compte rendu

**Question 4** 

| Notion                   | Définition    |
| -------------------------|------------------|
| Spring                |  Serveur Web           | 
| JPA                |  Persistance XML implenté par hibernate           | 
| Hibernate                |  Lien vers une BDD           | 
| H2                |  Moteur de BDD           | 
| DevTools                |  Outil de développement Sping Boot, simplification du développement           | 
| Thymeleaf                |  Modèle Java pour serveur pour une infrastructure standard et Web           | 

**Question 13**
```
public String greeting(@RequestParam(name="nameGET",required=false , defaultValue="World")String nameGET, Model model)
```
La partie paramètre de l'URL correspond au "@RequestParam" qui porte le nom "nameGET" qui signifie que si on ajoute "?nameGET=oui" la string nameGET en paramètre sera égale à "oui".

Le fichier HTML à afficher est défini grâce à la String que l'on retourne.

**Question 17**

Après la modification du JDBC URL, nous voyons la table Article dans la base de données in-memory.

**Question 18**

La table est créée à partir de la classe Article.java. La table est créée automatiquement grâce à H2.

**Question 20**

Oui, il est possible de voir l'intagralité du contenu de data.sql car il s'agit d'ajout à la base de données.

**Question 23**

Cette annotation permet à Spring de résoudre et injecter des beans collaboratives dans notre bean.

