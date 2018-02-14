// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But : Implémenter une liste dans une liste chaînée

#include <stdio.h>

typedef struct _liste liste;

struct _liste {
	int value;
	liste* next;
};

void afficher(liste* l);
liste* ajouter_fin(liste* l, int val);
liste* ajouter_debut(liste* l, int val);
liste* ajouter_position(liste* l, int val, unsigned int position);
liste* remplir(liste* l, int tab[], unsigned int nb);
int rechercher(liste* l, int entier);
liste* supprier(liste* l, int entier);

int main() {
	
	printf("Implémentation d'une liste!\n");
	return 0;
}

