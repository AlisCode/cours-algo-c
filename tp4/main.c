#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int main() {

        liste l2 = {
                .value = 2,
                .next = NULL
        };

        liste l = {
                .value = 1,
                .next = &l2
        };

        liste* list = &l;

	/*
        list = ajouter_fin(list, 4);
        list = ajouter_debut(list, 0);
        list = ajouter_position(list, 3, 3);
        afficher(list);

        int index = rechercher(list, 3);
        printf("index trouvé! : %d\n", index);

        index = rechercher(list, 5);
        printf("index non trouvé: %d\n", index);

        list = supprimer(list, 2);
        list = supprimer(list, 0);
        afficher(list);

        int tab[2] = { 5, 6 };
        list = remplir(list, tab, 2);
        afficher(list);
	*/

	vider(&list);

        return 0;
}
