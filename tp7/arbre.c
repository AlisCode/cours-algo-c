#include <stdlib.h>
#include <stdio.h>

#include "arbre.h"

void insertion_recursive(noeud** racine, int valeur) {
	if(*racine) {
		if( valeur > (*racine)->valeur)
			insertion_recursive(&((*racine)->droit),valeur);
		else 
			insertion_recursive(&((*racine)->gauche),valeur);
	}
	else 
	{
		(*racine) = malloc(sizeof(noeud));
		(*racine)->valeur = valeur;
		(*racine)->gauche = NULL;
		(*racine)->droit = NULL;
	}
}


void parcours_grd(noeud* racine) {

	if(racine->gauche != NULL) {
		parcours_grd(racine->gauche);
	} 
	printf("Noeud: %d\n", racine->valeur);
	if(racine->droit != NULL) {
		parcours_grd(racine->droit);
	}
}


void parcours_rgd(noeud* racine) {

	printf("Noeud: %d\n", racine->valeur);
	if(racine->gauche != NULL) {
		parcours_rgd(racine->gauche);
	}
	if(racine->droit != NULL) {
		parcours_rgd(racine->droit);
	}
}
