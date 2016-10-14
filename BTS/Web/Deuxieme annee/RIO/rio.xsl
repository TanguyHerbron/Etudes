<?xml version="1.0" encoding="UTF-8"?>

<!--
    Document   : rio.xsl
    Created on : 6 septembre 2016, 14:55
    Author     : therbron
    Description:
        Purpose of transformation follows.
-->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>

    <!-- TODO customize transformation rules 
         syntax recommendation http://www.w3.org/TR/xslt 
    -->
    <xsl:template match="rio">
        <html>
            <head>
                <link rel="stylesheet" href="rioStylesheet.css"/>
                <title>Resultat RIO</title>
            </head>
            <body>
                <xsl:apply-templates />
            </body>
        </html>
    </xsl:template>
    
    <xsl:template match="tableau">
        <table>
            <tr class="entreeTableau">
                <th>Pays</th>
                <th>Or</th>
                <th>Argent</th>
                <th>Bronze</th>
                <th>Total</th>
            </tr>
            <xsl:apply-templates />
        </table>
    </xsl:template>
    
    <xsl:template match="pays">
        <tr>
            <xsl:choose>
                <xsl:when test="@nomDePays = 'USA'">
                    <td class="usa">
                        <img src="img/usa.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Grande-Bretagne'">
                    <td class="gb">
                        <img src="img/gb.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Chine'">
                    <td class="chine">
                        <img src="img/chine.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Russie'">
                    <td class="russie">
                        <img src="img/russie.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Allemagne'">
                    <td class="allemagne">
                        <img src="img/allemagne.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Japon'">
                    <td class="japon">
                        <img src="img/japon.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'France'">
                    <td class="france">
                        <img src="img/france.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Corée_du_Sud'">
                    <td class="cds">
                        <img src="img/coreedusud.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Italie'">
                    <td class="italie">
                        <img src="img/italie.png"></img>
                    </td>
                </xsl:when>
                <xsl:when test="@nomDePays = 'Australie'">
                    <td class="australie">
                        <img src="img/australie.png"></img>
                    </td>
                </xsl:when>
            </xsl:choose>
            <xsl:apply-templates>
                <!--<xsl:sort select="sum(medaille)" order="descending" data-type="number"/>-->
            </xsl:apply-templates>
        </tr>
    </xsl:template>
    <xsl:template match="medaille">
        <xsl:choose>
            <xsl:when test="@typeDeMedaille = 'Or'">
                <td class="gold">
                    <xsl:value-of select="."/>
                </td>
            </xsl:when>
            <xsl:when test="@typeDeMedaille = 'Argent'">
                <td class="silver">
                    <xsl:value-of select="."/>
                </td>
            </xsl:when>
            <xsl:otherwise>
                <td class="bronze">
                    <xsl:value-of select="."/>
                </td>
                <td class="total">
                    <xsl:value-of select="sum(../medaille)"/>
                </td>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
</xsl:stylesheet>
