#include <stdlib.h>
#include <stdio.h>

#include "arbre.h"

void insertion_recursive(noeud **racine, int valeur) {
    if (*racine) {
        if (valeur > (*racine)->valeur)
            insertion_recursive(&((*racine)->droit), valeur);
        else
            insertion_recursive(&((*racine)->gauche), valeur);
    } else {
        (*racine) = malloc(sizeof(noeud));
        (*racine)->valeur = valeur;
        (*racine)->gauche = NULL;
        (*racine)->droit = NULL;
    }
}


void parcours_grd(noeud *racine) {

    if (racine->gauche != NULL) {
        parcours_grd(racine->gauche);
    }
    printf("Noeud: %d\n", racine->valeur);
    if (racine->droit != NULL) {
        parcours_grd(racine->droit);
    }
}


void parcours_rgd(noeud *racine) {

    printf("Noeud: %d\n", racine->valeur);
    if (racine->gauche != NULL) {
        parcours_rgd(racine->gauche);
    }
    if (racine->droit != NULL) {
        parcours_rgd(racine->droit);
    }
}

int is_leaf(noeud *racine) {
    if (racine == NULL) {
        return 0;
    }
    if (racine->droit == NULL && racine->gauche == NULL) {
        return 1;
    }

    return 0;
}

noeud **rechercher(noeud **racine, int valeur) {
    if (*racine == NULL) {
        return NULL;
    }

    if (valeur == (*racine)->valeur) {
        return racine;
    }

    noeud *child = NULL;
    if (valeur > (*racine)->valeur) {
        child = (*racine)->droit;
    } else if (valeur < (*racine)->valeur) {
        child = (*racine)->gauche;
    }

    return rechercher(&child, valeur);
}


void suppression(noeud **racine, int valeur) {
    if (*racine == NULL) {
        // La racine est nulle
        return;
    }

    noeud **child = rechercher(racine, valeur);

    if (child == NULL) {
        // Le noeud n'existe pas.
        return;
    }

    if ((*racine)->gauche == *child || (*racine) == *child) {
        if (is_leaf(*child)) {
            // On doit supprimer l'élément à gauche, qui est une feuille
            (*racine)->gauche = NULL;
            free(*child);
        } else {
            // On doit supprimer l'élément à gauche, qui n'est pas une feuille
            int val = get_value((*child)->gauche, 0);
            (*child)->valeur = val;
            suppression(&(*child)->gauche, val);
        }
        return;
    } else if ((*racine)->droit == *child || (*racine) == *child) {
        if (is_leaf(*child)) {
            // On doit supprimer l'élément à droite, qui est une feuille
            (*racine)->droit = NULL;
            free(*child);
        } else {
            // On doit supprimer l'élément à droite, qui n'est pas une feuille
            int val = get_value((*child)->droit, 1);
            (*child)->valeur = val;
            suppression(&(*child)->droit, val);
        }
        return;
    }

    // Lance récursivement sur les autres éléments
    if (valeur <= (*racine)->valeur) {
        suppression(&(*racine)->gauche, valeur);
    } else {
        suppression(&(*racine)->droit, valeur);
    }
}

int get_value(noeud *racine, int go_left) {
    noeud *child = NULL;
    if (go_left == 1) {
        child = racine->gauche;
    } else {
        child = racine->droit;
    }

    if (child == NULL) {
        return racine->valeur;
    } else {
        return get_value(child, go_left);
    }
}