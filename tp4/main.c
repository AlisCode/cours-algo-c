#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int main() {

        liste* list = malloc(sizeof(liste));
	list->value = 1;
	list->next = NULL;

	list = ajouter_fin(list,2);
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

	vider(&list);
	afficher(list);


        return 0;
}
