<?xml version="1.0" encoding="UTF-8"?>

<!--
    Document   : bibliotheque.xsl
    Created on : 6 septembre 2016, 11:33
    Author     : therbron
    Description:
        Purpose of transformation follows.
-->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>

    <!-- TODO customize transformation rules 
         syntax recommendation http://www.w3.org/TR/xslt 
    -->
    <xsl:template match="bibliotheque">
        <html>
            <head>
                <title>Bibliotheque</title>
            </head>
            <body>
                <xsl:apply-templates />
            </body>
        </html>
    </xsl:template>
    
    <!--Allee-->
    
    <xsl:template match="allee">
        <h1> Allee <xsl:value-of select="@numero"/></h1>
        <hr/>
        <xsl:apply-templates />
        
    </xsl:template>
    
    <!--rayon-->
    
    <xsl:template match="rayon">
        <h2> Rayon <xsl:value-of select="@numero"/></h2>
        <br/>
        <table border="1">
            <tr>
                <th>Categorie de l'ouvrage</th>
                <th>Titre</th>
                <th>Auteur</th>
                <th>Numero</th>
            </tr>
        <xsl:apply-templates />
        </table>
        
    </xsl:template>
    <!--ouvrage-->
    
    <xsl:template match="ouvrage">
        <tr>
            <td>
                <xsl:value-of select="@type"/>
            </td>
            <xsl:apply-templates />
        </tr>
        
    </xsl:template>
    <!--titre-->
    
    <xsl:template match="titre">
        <td>
            <xsl:value-of select="."/>
        </td>
        <xsl:if test="not(../auteur)">
            <td>NO</td>
            <xsl:if test="not(../numero)">
                <td>NO</td>
            </xsl:if>
        </xsl:if>
    </xsl:template>
    <!--auteur-->
    
    <xsl:template match="auteur">
        <td>
            <xsl:value-of select="."/>
        </td>
    </xsl:template>
    <!--numero-->
    
    <xsl:template match="numero">
        <td>
            <xsl:value-of select="."/>
        </td>
        
    </xsl:template>
    

</xsl:stylesheet>
