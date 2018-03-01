// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But : Implémenter la tour de Hanoï de manière récursive

#include <stdio.h>

void hanoi(int disc, int depart, int arrivee, int intermediaire);

int main(int argc, char** argv) {
	int disc = 4;
	printf("Nombre de disque : %d\n", disc);
	hanoi(disc, 1, 2, 3);

	return 0;
}

void hanoi(int disc, int depart, int arrivee, int intermediaire) {
	if(disc != 0 ) {
		hanoi(disc-1,depart, intermediaire, arrivee);
		printf("Déplacer le disque du plot %d vers le plot %d\n", depart, arrivee);
		hanoi(disc-1, intermediaire, arrivee, depart);
	}
}
