#include <stdlib.h>
#include <stdio.h>

#include "arbre.h"

int suppress_child_direction(noeud** racine, int go_left);

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

int is_leaf(noeud* racine) {
	if(racine->droit == NULL && racine->gauche == NULL) {
		return 1;	
	}

	return 0;
}

noeud** rechercher(noeud** racine, int valeur) {	
	if(*racine == NULL) {
		return NULL;
	}

	if(valeur == (*racine)->valeur) {
		return racine;
	} 

	noeud* child = NULL;
	if(valeur > (*racine)->valeur) {
		child = (*racine)->droit;
	}
	else if (valeur < (*racine)->valeur) {
		child = (*racine)->gauche;
	}
	
	return rechercher(&child, valeur);	
}


void suppression(noeud** racine, int valeur) {
	noeud** child = rechercher(racine, valeur); 
	
	if(child == NULL)
	{	
		// Le noeud n'existe pas.
		return;
	}	

	// On cherche la valeur parmis les enfants	
	if(child != NULL) {
		if(child->valeur == valeur && is_leaf(child) == 1) {
			// L'enfant est une feuille et doit être supprimé
			free(child);
			if(left == 1) { (*racine)->gauche = NULL; }
			else { (*racine)->droit = NULL; } 
		}
		else if(child->valeur == valeur) {
			// L'enfant n'est pas une feuille et doit être supprimé	
			suppression(&child, valeur);
		}
	}

	// On doit supprimer ce noeud (donc remplacer cette valeur par le bon élément)
	if((*racine)->valeur == valeur) {
		if((*racine)->gauche != NULL) {
			(*racine)->valeur = suppress_child_direction(&(*racine)->gauche, 1);
		}
		else {
			(*racine)->valeur = suppress_child_direction(&(*racine)->droit, 0);
		}
	} 
}

int suppress_child_direction(noeud** racine, int go_left) {
	noeud* child = NULL;
	if(go_left == 1) {
		child = (*racine)->gauche;
	}
	else {
		child = (*racine)->droit;
	}

	int val = 0;
	if(child == NULL) {
		return (*racine)->valeur;
	}
	else {
		val = suppress_child_direction(&child, go_left);
	}

	if(val == child->valeur) {
		free(child);
		if(go_left) {
			// Supprime le pointeur sur l'élément qui va à gauche comme il n'existe plus
			(*racine)->gauche = NULL;
		}
		else {
			(*racine)->droit = NULL;
		}
	}

	return val;
}
