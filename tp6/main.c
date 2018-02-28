// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But : Implémenter le tri par tas et la structure de données "tas"

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {


	int tas[18] = {};
	entasser(tas, 3);
	entasser(tas, 5);
	entasser(tas, 6);
	entasser(tas, 2);
	entasser(tas, 8);
	entasser(tas, 9);
	entasser(tas, 11);
	entasser(tas, 7);
	entasser(tas, 4);
	entasser(tas, 10);
	entasser(tas, 12);
	entasser(tas, 15);
	entasser(tas, 20);
	entasser(tas, 1);
	entasser(tas, 19);
	entasser(tas, 13);
	entasser(tas, 17);

	afficher(tas);
	printf("------\n");
	detasser(tas);
	printf("------\n");
	afficher(tas);
	return 0;
}
