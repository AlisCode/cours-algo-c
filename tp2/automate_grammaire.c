// Date 07/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Fournir un automate capable de déterminer si une phrase est correcte ou non 

#include <stdio.h>

typedef struct mots mots;
struct mots{
	char libelle_mot[10];
	int type_mot;
};

mots dictionnaire[10]={ {"le",0},{"chat",2},{"souris"
,2},
{"mange",3},{"la",0},{"petite",1},
{".",5},{"bleu",1},{"dort",3},{"julie",4} };

int main() {

	

	return 0;
}

