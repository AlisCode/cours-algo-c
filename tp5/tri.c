#include "liste.h"
#include "tri.h"

#include <stdio.h>
#include <stdlib.h>

void eclatement(liste* l, liste* l1, liste* l2) {
	int numero_liste = 1, i = 1, i1 = 1, i2 = 1;
	while(l->value != 0) {
		if(numero_liste % 2 == 1) {
			int val_l = valeur_case(l, i1); 
			i++;	
		}
	}
}

liste* fusion(liste* l1, liste* l2) {
	// Gère le cas d'une liste vide
	if(l1 == NULL) { return l2; }
	if(l2 == NULL) { return l1; }

	// La liste finale est le pointeur sur lequel on va itérer. On l'initialise à la plus petite valeur entre l1 et l2
	liste* final;
	if (l1->value < l2->value) { 
		final = l1;
		l1 = l1->next;
	}
	else { 
		final = l2; 
		l2 = l2->next;		
	}

	// On garde un pointeur sur le premier élément de la liste
	liste* head = final;

	// cf. algo cours
	while(l1 != NULL || l2 != NULL) {
		if(l2 == NULL || ((l1 != NULL && l2 != NULL) && (l1->value < l2->value)) ) {
			final->next = l1;
			l1 = l1->next;
		}
		else {
			final->next = l2;
			l2 = l2->next;
		}
		final = final->next;
	}

	// Quand on sort de la boucle, il reste une liste vide et une liste pleine. Il faut ajouter le contenu de cette liste encore pleine à la liste finale.
	if(l1 == NULL) {
		final->next = l2;
	}
	else {
		final->next = l1;
	} 

	// On retourne le pointeur vers le premier élément
	return head;
}

liste* tri_fusion(liste* l) {
}
