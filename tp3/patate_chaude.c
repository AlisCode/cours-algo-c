// Date 12/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Implémentation du "jeu de la patate chaude"
// Implémentation d'un système primitif de Liste (statique)
// Nota: on utilise ici des pointeurs alors qu'on ne devrait pas !
// Pour retirer les pointeurs, il faut que les fonctions qui utilisent les pointeurs retournent des ListeJoueur à la place de void

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Structure Joueur
typedef struct joueur Joueur;
struct joueur {
    char name[10];
    unsigned int id_prev;
    unsigned int id_next;
};

// Structure ListeJoueur
typedef struct liste_joueur ListeJoueur;
struct liste_joueur {
    unsigned int size;
    Joueur joueurs[SIZE];
    unsigned int id_first;
    unsigned int curr_id;
};

// Fonctions utilitaires
void ajouter_joueur(ListeJoueur* liste, Joueur j);
void supprimer_joueur(ListeJoueur* liste, int id);
void display_joueur(Joueur j);
void display_list(ListeJoueur liste);
ListeJoueur create_liste_joueur();
void patate_turn(ListeJoueur* liste);
void do_patate_turn(ListeJoueur* liste);

// Crée la liste de joueurs
// Retourne: la liste de joueur créée
ListeJoueur create_liste_joueur() {

    ListeJoueur liste = {
        .size = SIZE,
        .id_first = 0,
        .curr_id = 0,    
    };

    return liste;
}

// Supprime le joueur avec l'ID passé en paramètre
// liste: Pointeur sur la liste qu'on souhaite modifier
// id: id du joueur qu'on souhaite retirer
void supprimer_joueur(ListeJoueur* liste, int id) {
    Joueur j = liste->joueurs[id-1];
    unsigned int id_prev = j.id_prev-1;
    unsigned int id_next = j.id_next-1;
    
    if(liste->id_first == id) {
        liste->id_first = j.id_next;
    }

    liste->joueurs[id_prev].id_next = j.id_next;
    liste->joueurs[id_next].id_prev = j.id_prev;
}

// Ajoute le joueur j dans la liste passée en paramètre
// liste: Pointeur sur la liste qu'on souhaite modifier
// j: joueur que l'on souhaite ajouter dans la liste
void ajouter_joueur(ListeJoueur* liste, Joueur j) {
    liste->joueurs[liste->curr_id++] = j;
}

// Affiche la liste de joueurs passée en paramètres
// liste: Liste de joueurs à afficher
void display_list(ListeJoueur liste) {
    unsigned int i = liste.id_first;
    do {
        display_joueur(liste.joueurs[i-1]);
        i = liste.joueurs[i-1].id_next;
    }while(i != liste.id_first);
}

// Affiche le joueur passé en paramètres
// j: le joueur à afficher
void display_joueur(Joueur j) {
    printf("%d -> %s -> %d\n", j.id_prev, j.name, j.id_next);
}

// Fonction principale
int main() {

    // Seed le RNG avec la variable de temps actuelle
    srand(time(NULL));

    // Crée la liste de joueur (hardcodée)
    ListeJoueur liste = create_liste_joueur();
    Joueur j1 = {"Joueur1",4,2};
    Joueur j2 = {"Joueur2",1,5};
    Joueur j3 = {"Joueur3",5,4};
    Joueur j4 = {"Joueur4",3,1};
    Joueur j5 = {"Joueur5",2,3};

    ajouter_joueur(&liste, j1);
    ajouter_joueur(&liste, j2);
    ajouter_joueur(&liste, j3);
    ajouter_joueur(&liste, j4);
    ajouter_joueur(&liste, j5);
    liste.id_first = 1;

    // Fait le jeu de façon à laisser un gagnant.
    for(int i = 1 ; i < SIZE ; i++) {
        do_patate_turn(&liste);
    }

    // Affiche le gagnant !
    printf("Gagnant: %s\n", liste.joueurs[liste.id_first-1].name);

    return 0;
}

// Effectue un tour de jeu de la patate chaude
// liste: Pointeur sur la liste qu'on souhaite modifier
void patate_turn(ListeJoueur* liste) {
    unsigned int ttl_patate = rand() % 100;
    unsigned int curr_id = liste->id_first;
    for(int i = 0 ; i < ttl_patate ; i++) {
        curr_id = liste->joueurs[curr_id-1].id_next;
    }

    supprimer_joueur(liste, curr_id);
}

// Lance le tour de jeu de la patate chaude et affiche la nouvelle liste avec un séparateur 
// liste: Pointeur sur la liste qu'on souhaite modifier
void do_patate_turn(ListeJoueur* liste) {
    
    patate_turn(liste);
    display_list(*liste);
    printf("-----------\n");
}