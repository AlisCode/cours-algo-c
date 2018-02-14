// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But : Implémenter une liste dans une liste chaînée

#include <stdio.h>
#include "liste.h"

int main() {

	liste l2 = {
		.value = 1,
		.next = NULL
	};

	liste l = {
		.value = 0,
		.next = &l2
	};

	
	afficher(&l);

	return 0;
}

void afficher(liste* l){
	while(l!=NULL)
    {
    	printf("%d\n",l->value);
    	l=l->next;
    }
}

liste* ajouter_fin(liste* l, int val) {

	liste new_l = {
		.value = val,
		.next = NULL	
	};

	while(l->next != NULL) {
		
	}

}
