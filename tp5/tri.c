#include "liste.h"
#include "tri.h"

#include <stdio.h>
#include <stdlib.h>

void eclatement(liste *l, liste **liste1, liste **liste2)
{
	// Initialise une nouvelle liste
	liste* final = NULL;
	liste* l1 = NULL;
	liste* l2 = NULL;

	int prev = 0;
	final = l;  
	while(final->next) {
		do {
			prev = final->value;
			l1 = ajouter_fin(l1,final->value);
	    		if(final->next) {
	   			final = final->next;
	  		}
	  	} while(final->value > prev);
		do {
			prev = final->value;
			l2 = ajouter_fin(l2,final->value);
	    		if(final->next) {
	   			final = final->next;
	  		}
	  	} while(final->value > prev);
	}
	
	// Sort le contenu des listes éclatées dans les double-pointeurs qu'on a donné en entrée
	*liste1 = l1;
	*liste2 = l2;
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

	int flag_ovf_l1 = 0;
	int flag_ovf_l2 = 0;

	// cf. algo cours
	while(l1 != NULL || l2 != NULL) {
		while(flag_ovf_l1 != 1 || flag_ovf_l2 != 1)
		{
			if(flag_ovf_l2 == 1) {
				final->next = l1;
				if(l1->next == NULL || l1->value < l1->next->value) { flag_ovf_l1 = 1; }
				l1 = l1->next;
			}
			else if(flag_ovf_l1 == 1) {
				final->next = l2;
				if(l2->next == NULL || l2->value < l2->next->value) { flag_ovf_l2 = 1; }
				l2 = l2->next;
			}
			else {
				if(l1->value < l2->value) {
					final->next = l1;
					if(l1->next == NULL || l1->value < l1->next->value) { flag_ovf_l1 = 1; }
					l1 = l1->next;
				}	
				else {
					final->next = l2;
					if(l2->next == NULL || l2->value < l2->next->value) { flag_ovf_l2 = 1; }
					l2 = l2->next;
				}
			}
			final = final->next;
		}
		flag_ovf_l1 = 0;
		flag_ovf_l2 = 0;
		if(l1 == NULL)
			flag_ovf_l1 = 1;
		if(l2 == NULL)
			flag_ovf_l2 = 1;
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
	liste* final = NULL;
	liste* head = final;
	liste* l1 = NULL;
	liste* l2 = NULL;
	do {
		eclatement(l,&l1, &l2);
		puts("eclatement");
		afficher(l1);
		puts("--suite--");
		afficher(l2);
		puts("ok_eclatement\n");
		liste* new = fusion(l1,l2);
		afficher(new);
		puts("ok_fusion");
		final->next = new; 
		puts("ok_end_loop");
	} while(l1 != NULL && l2 != NULL);

	return head;
}
