// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Résoudre l'énigme en affichant les différentes lignes 

#include <stdio.h>

// Compte le nombre de fois qu'on 'change de valeurs' dans le tableau
// tab: le tableau de valeurs
// n: la longueur du tableau
// retourne: le nombre de fois qu'on change de valeurs
int count_value_change(int tab[], int n);

// Calcule la nouvelle ligne grâce à l'ancienne. Stocke la nouvelle ligne dans le tableau new_line dont la longueur new_n doit être spécifiée
// tab: la ligne de départ
// n: la longueur de la ligne de départ
// new_line: la ligne d'arrivée
// new_n: la longueur de la ligne d'arrivée
void compute_new_line(int tab[], int n, int new_line[], int new_n);

int main() {
	
	int tab[8] = {1,1,1,3,1,1,1,4};

	int count = count_value_change(tab, 8);
	printf("count : %d\n", count);
	return 0;
}

int count_value_change(int tab[], int n) {

	int old_val = tab[0];
	int count = 1;
	for(int i = 0 ; i < n ; i++) {
		if(tab[i] != old_val) {
			count++;
		}	
		old_val = tab[i];
	}

	return count;
}

void compute_new_line(int tab[], int n, int new_line[], int new_n) {
	
	int old_val = tab[0];
	int count_val = 0;
	for(int i = 0 ; i < n ; i++) {
		
	} 
}

