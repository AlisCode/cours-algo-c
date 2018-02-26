// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But : Implémenter une liste dans une liste chaînée

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

//affiche les élèments de la liste 
//l : pointeur vers la liste

void afficher(liste* l){

	// Si la liste est vide, on l'affiche	
	if(l == NULL) { printf("La liste est vide!\n"); }	
	
	// Parcours la liste en affichant la valeur à chaque fois
	while(l != NULL)
	{
    		printf("%d\n",l->value);
    		l=l->next;
    	}
}

// ajoute un élèment à la fin de la liste
// l : pointeur vers la liste
// val : la valeur à ajouter à la fin 
// retourne le pointeur vers la liste mise à jour 
liste* ajouter_fin(liste* l, int val) {	

	// Sauvegarde la tête de la liste
	liste* head = l;

	// Crée le nouvel élément que l'on va ajouter
	liste* new_l = malloc(sizeof(liste));
	new_l->value = val;
	new_l->next = NULL;

	if(l == NULL) {
		return new_l;
	}

	// On se déplace jusqu'à la fin de la liste
	while(l->next != NULL) {
		l = l->next;	
	}

	// Ajout du dernier élément
	l->next = new_l;

	return head;
}

//ajoute un élèment au début de la liste 
//l : pointeur vers la liste
// val : la valeur à ajouter au début
// retourne vers la nouvelle liste 
liste* ajouter_debut(liste* l, int val) {

	// Crée la nouvelle liste
	liste* new_l = malloc(sizeof(liste));
	new_l->value = val;
	
	// Le next de la nouvelle liste est l'élément liste que l'on a donné en entrée
	new_l->next = l;

	return new_l;	
}

// ajoute un élèment à une position de la liste
// l : pointeur vers la liste
// val : la valeur à ajouter
// position : la position à la quelle il faut ajouter l'élèment
// retourne : la liste mise à jour

liste* ajouter_position(liste* l, int val, unsigned int position) {

	// sauvegarde la tête de liste pour la retourner à la fin
	liste* head = l;

	// parcours la liste pour se retrouver au bon index
	unsigned int i = 0;	
	for(i = 0 ; i < position - 1 ; i++) {
		l = l->next;
	}
	
	// crée le nouvel élément new_elem
	liste* new_elem = malloc(sizeof(liste));
	new_elem->value = val;
	new_elem->next = l->next;

	// Ajoute new_elem dans la liste
	l->next = new_elem;	

	return head;
}

// rempli la liste avec des valeurs 
// l : pointeur vers la liste
// tab : le tableau de valeurs à ajouter
// nb : la longeur du tableau 
// retourne la liste rempli avec les valeurs 
liste* remplir(liste* l, int tab[], unsigned int nb) {
	
	// Ajoute à la fin chaque élément du tableau. NB: ceci est très peu performant et pourrait être mieux implémenté.	
	unsigned int i = 0;
	for(i = 0 ; i < nb ; i++) {
		l = ajouter_fin(l, tab[i]); 
	}	

	return l;
}

// recherche une valeur dans le tableau 
// l : pointeur vers la liste
// val : la valeur à rechercher 
// retourne :  l'index de la valeur
// retourne : -1 si aucune valeur trouvé
int rechercher(liste* l, int val) {
	int i = 0;
	// Parcours la liste
	while(l != NULL) {
		// si on a la valeur que l'on cherche, on retourne l'index
		if ( l->value == val) { return i; }
		l = l->next;
		i++;
	}

	// si on est toujours dans cette fonction maintenant, cela veut dire qu'il n'existe pas d'élement ayant la valeur recherchée...
	return -1;
}

int valeur_case(liste* l, int index) {
	int i = 0;
	while(l != NULL) {
		if(i == index) { return l->value; }
		l = l->next;
		i++;
	}
	
	// Si on a pas pu aller à l'index, c'est qu'il n'y a pas assez de cases dans le tableau ...
	return 0;
}

// Change la valeur de la case de la liste l à l'index index pour qu'elle soit égale à val.
// Autrement dit, l[index] = val;
// l: pointeur sur la liste à modifier
// index: l'index de la liste qu'on souhaite modifier
// val: la nouvelle valeur de la case
void changer_valeur_case(liste* l, int index, int val) {
	int i = 0;
	while(l != NULL) {
		if(i == index) { 
			l->value = val; 
			return;
		}
		l = l->next;
		i++;
	}
}

//supprime une valeur dans la liste 
// l : pointeur vers la liste
// val : la valeur à supprimer
// retourne la liste mise à jour
liste* supprimer(liste* l, int val) {

	// Sauvegarde la tête de liste pour la retourner à la fin
	liste* head = l;
	
	// Cas particulier du premier élément de la liste 
	if(head->value == val) {
		return head->next;
	}

	// Sauvegarde l'élément précédent
	liste* prev = head;
	while(l != NULL) {
		if( l->value == val) {
			// Retire l'élément de la liste
			prev->next = l->next;
			return head;	
		}

		prev = l;
		l = l->next;
	} 	

	// Retourne le premier élément de la liste
	return head;
} 

// vider la liste 
// l : pointeur vers la liste
void vider(liste** l) {
	
	liste* current = *l;
	liste* next;

	while (current != NULL) 
	{
	    next = current->next;
	    free(current);
	    current = next;
	}

	*l = NULL;
}
