// Date 07/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Fournir un automate capable de déterminer si une phrase est correcte ou non 

#include <stdio.h>
#include <string.h>

// Structure mot pour notre dictionnaire
typedef struct mots Mots;
struct mots {
	char libelle_mot[10];
	int type_mot;
};

// Fonctions utilitaires
int get_next_step(int old_state, int type_mot);
int analyse_phrase(char* phrase);
int get_type_mot(char* mot, Mots dico[], int length_dico); 

// Dictionnaire de mot
Mots dictionnaire[10]={ 
	{"le",0},
	{"chat",2},
	{"souris",2},
	{"mange",3},
	{"la",0},
	{"petite",1},
	{".",5},
	{"bleu",1},
	{"dort",3},
	{"julie",4} 
};

// Matrice de transitions
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

// Fonction principale
int main(int argc, char* argv[]) {

	// Test avec une phrase correcte
	//char test_phrase[100] = "le chat bleu dort .";	
	
	// Test avec une phrase incorrecte
	char test_phrase[100] = "le chat dort bleu .";	

	// Lance l'analyse de la phrase
	int res = analyse_phrase(test_phrase);
	
	// si la phrase est correcte
	if(res == 1) {
		printf("La phrase est correcte!\n");
	}
	// Sinon ...
	else {
		printf("La phrase est incorrecte!\n");
	}

	return 0;
}

// Fonction permettant d'analyser la phrase en utilisant l'automate
// phrase: tableau de char contenant la phrase à tester
// retourne: 1 si la phrase est correcte
// 0 sinon
int analyse_phrase(char phrase[100]) {

	// L'état actuel
	int state = 0;
	
	// String stockant le token
	char* splitted; 
	
	// Split la phrase en utilisant les charactères "separateurs"
	splitted = strtok(phrase, " ,;:");
	while(splitted != NULL) {
		// Récupère le type du mot (token) en le cherchant dans le dictionnaire
		int type = get_type_mot(splitted, dictionnaire, 10);

		// Trouve le nouvel état en fonction de l'ancien et du type de mot
		state = get_next_step(state, type);
		
		// L'état 8 est l'état mort, si on l'atteint, la phrase n'est pas correcte.
		if (state == 8) {
			return 0;
		}
		splitted = strtok(NULL," ,;:");
	}

	// On a fini de traîter la phrase. L'état est soit 8, auquel cas on est déjà sortis, soit 9, auquel cas la phrase est juste.
	if(state == 9) {	
		return 1;	
	}

	// Ce bout de code n'est jamais sensé être atteint, mais au cas où, on retourne 0. 
	// C'est du C, on sait jamais ....	
	return 0;
}

// Retourne la nouvel état en fonction de l'ancien état et du type de mot, en utilisant le tableau de transitions
// old_state: l'ancien état
// type_mot: le type de mot actuel (0 = article, 1 = adjectif, etc... cf. tableau dictionnaire & énoncé) 
// retourne: le nouvel état
int get_next_step(int old_state, int type_mot) {
	return transitions[old_state][type_mot];	
}

// Obtient le type de mot en fouillant le dictionnaire.
// mot: le mot que l'on recherche
// dico: le dictionnaire que l'on recherche
// length_dico: la taille du dictionnaire
// retourne: le type du mot trouvé dans le dictionnaire
// -1 si le mot n'a pas été trouvé dans le dictionnaire
int get_type_mot(char* mot, Mots dico[], int length_dico) {
	for(int i = 0 ; i < length_dico ; i++) {
		if(strcmp(mot,dico[i].libelle_mot) == 0) {
			return dico[i].type_mot;
		} 
	}
	return -1;	
}

