// Date 07/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Fournir un automate capable de déterminer si une phrase est correcte ou non 

#include <stdio.h>
#include <string.h>

typedef struct mots Mots;
struct mots {
	char libelle_mot[10];
	int type_mot;
};

int get_next_step(int old_state, int type_mot);
int analyse_phrase(char* phrase);
int get_type_mot(char* mot, Mots dico[], int length_dico); 


Mots dictionnaire[10]={ {"le",0},{"chat",2},{"souris"
,2},
{"mange",3},{"la",0},{"petite",1},
{".",5},{"bleu",1},{"dort",3},{"julie",4} };

int transitions[10][6] = {
	1, 8, 8, 8, 4, 8,
	8, 1, 2, 8, 8, 8,
	8, 2, 8, 3, 8, 8,
	5, 8, 8, 8, 7, 9,
	8, 8, 8, 3, 8, 8,
	8, 5, 6, 8, 8, 8,
	8, 6, 8, 8, 8, 9,
	8, 8, 8, 8, 8, 9,
	8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8,
};

int main(int argc, char* argv[]) {

	// Test avec une phrase correcte
	char test_phrase[100] = "le chat bleu dort .";	
	
	// Test avec une phrase incorrecte
	//char test_phrase[100] = "le chat dort bleu .";	


	int res = analyse_phrase(test_phrase);
	if(res == 1) {
		printf("La phrase est correcte!\n");
	}
	else {
		printf("La phrase est incorrecte!\n");
	}

	return 0;
}

int analyse_phrase(char phrase[100]) {

	int state = 0;
	char* splitted; 
	splitted = strtok(phrase, " ,;:");
	while(splitted != NULL) {
		// Faire quelque chose avec le mot contenu dans splitted
		int type = get_type_mot(splitted, dictionnaire, 10);
		state = get_next_step(state, type);
		splitted = strtok(NULL," ,;:");
		if (state == 8) {
			return 0;
		}
	}

	if(state == 9) {	
		return 1;	
	}
	
	return 0;
}
}

int get_next_step(int old_state, int type_mot) {
	return transitions[old_state][type_mot];	
}

int get_type_mot(char* mot, Mots dico[], int length_dico) {
	for(int i = 0 ; i < length_dico ; i++) {
		if(strcmp(mot,dico[i].libelle_mot) == 0) {
			return dico[i].type_mot;
		} 
	}
	return -1;	
}

