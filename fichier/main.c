#include <stdio.h>
#include <stdlib.h>

void read_dico(char* dico[], int nb_mots);

int main() {

	FILE* fichier = fopen("dico.txt", "r");
	
	if(fichier != NULL) 
	{
		int nb_mots = 0;
		fscanf(fichier, "%d\n", &nb_mots);

		char* dico[nb_mots];
		for(int i = 0; i < nb_mots; i++) {
			char new_val[10];
			fscanf(fichier, "%s\n", new_val); 
			dico[i] = new_val;
		}

		fclose(fichier);
		read_dico(dico, nb_mots);
		printf("Il y a %d mots", nb_mots);	
	}

	return 0;
}

void read_dico(char* dico[], int nb_mots) {
	for(int i = 0 ; i < nb_mots; i++) {
		printf("%s\n", dico[i]);
	}
} 
