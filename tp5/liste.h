#ifndef LISTE_H
#define LISTE_H

typedef struct _liste liste;

struct _liste {
    int value;
    liste *next;
};

void afficher(liste *l);

liste *ajouter_fin(liste *l, int val);

liste *ajouter_debut(liste *l, int val);

liste *ajouter_position(liste *l, int val, unsigned int position);

liste *remplir(liste *l, int tab[], unsigned int nb);

int rechercher(liste *l, int entier);

liste *supprimer(liste *l, int entier);

void vider(liste **l);

#endif
