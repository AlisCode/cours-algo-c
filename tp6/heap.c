#include "heap.h"

#include <stdio.h>

//permet d'entasser un élèment dans le tas 
//entrée - int - val :  la valeur à rajouter au tas
//entrée / sortie  - int - tas[] : le tas à modifier 
void entasser(int tas[], int val) 
{
	// Insère la racine si elle n'existe pas
	if(tas[0] == 0) { 
		tas[0]++; 
		tas[1] = val; 
		return;
	}

	int index = ++tas[0];
	tas[index] = val;
	
	while(index/2 != 0 && tas[index/2] > tas[index]) {
		permuter(tas,index,index/2);
		index /= 2;
	} 
}

//permet de détasser un élèment du tas
// entrée / sortie- int tas[] : le tas
void detasser(int tas[]) {
	int nb_elements = tas[0];
	int i;
	for(i = 0 ; i < nb_elements; i++) {
		printf("Retiré: %d\n", tas[1]);
		int index_retire = tas[0]--;
		tas[1] = tas[index_retire];
		tas[index_retire] = 0;
		int index = 1;
		while(index+2 <= tas[0] && tas[index]>tas[index+1] && tas[index]>tas[index+2]) {
			int new_index = 0;
			if(tas[index+1] < tas[index+2]) {
				new_index = index+1;
			} else {
				new_index = index+2;
			}
			permuter(tas, index, new_index);
			index = new_index;
		}
	}
} 

// permet de permuter deux élèments du tas
// entrée/sortie - int tas[] : le  tas en question 
// entrée - int index_a : l'élèment 1 
// entrée - int index_b : l'élèment 2 
void permuter(int tas[], int index_a, int index_b) {
	int temp_val = tas[index_a];
	tas[index_a] = tas[index_b];
	tas[index_b] = temp_val;
}

//permet d'afficher le tas
//entrée - int tas[] : le tas à afficher 
void afficher(int tas[]) {
	if(tas[0] == 0 ){
		printf("Le tas est vide \n");
	}
	int i;
	for(i=1;i<=tas[0];i++){
		printf("%d\n",tas[i]);
	}
}
