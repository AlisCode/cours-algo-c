#include <stdio.h>
#include <stdlib.h>

#include "liste.h"
#include "tri.h"

int main() {

	liste* l1 = NULL; 
	liste* l2 = NULL;
	liste* l3 = NULL;
	liste* l4 = NULL;

	// Cas de test normal
	l2 = ajouter_fin(l2, 3);
	l2 = ajouter_fin(l2, 5);
	l2 = ajouter_fin(l2, 6);
	l2 = ajouter_fin(l2, 7);
	l1 = ajouter_fin(l1, 2);
	l1 = ajouter_fin(l1, 8);
	l1 = ajouter_fin(l1, 9);
	l1 = ajouter_fin(l1, 11);


	// Cas de test avec liste nulle
	l3 = ajouter_fin(l3,1);
	l3 = ajouter_fin(l3,5);
	l3 = ajouter_fin(l3,6);
	l3 = ajouter_fin(l3,8);

	afficher(l1);
	printf("-------\n");
	afficher(l2);
	printf("-------\n");

	liste* test_fusion = fusion(l1,l2);
	afficher(test_fusion);

	printf("-------\n");


	liste* test_liste_nulle = fusion(l4,l3);
	afficher(test_liste_nulle);

	vider(&l1);
	vider(&l2);
	vider(&l3);
	vider(&l4);


	return 0;
}
