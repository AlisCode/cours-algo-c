#include <stdio.h>
#include "arbre.h"

int main() {

	noeud* racine = NULL;

	insertion_recursive(&racine, 15);
	insertion_recursive(&racine, 25);
	insertion_recursive(&racine, 10);
	insertion_recursive(&racine, 5);
	insertion_recursive(&racine, 12);
	insertion_recursive(&racine, 20);
	insertion_recursive(&racine, 33);
	insertion_recursive(&racine, 1);
	insertion_recursive(&racine, 11);
	insertion_recursive(&racine, 6);
	insertion_recursive(&racine, 13);
	insertion_recursive(&racine, 17);
	insertion_recursive(&racine, 22);

	//parcours_grd(racine);
	//parcours_rgd(racine);
	//suppression(&racine, 10);
	//parcours_grd(racine);
	
	return 0;
}
