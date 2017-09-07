#!/usr/bin/python
import math #Importer le module math pour la racine carree

#value = input("Jusqu'a quel nombre voulez-vous chercher un nombre premier ?")

value = 100000

tab = range(0, value)

for i in range(2, int(math.ceil(math.sqrt(value)))):
	if tab[i] != -1:
		for j in range(i+1, value):
			if tab[j] > 1:
				#print tab[i] % tab[j]
				if tab[j] % tab[i] == 0:
					tab[j] = -1

for i in range(0, value):
	if tab[i] != -1:
		print tab[i]
