#include <stdio.h>
#include "arbre.h"

int main() {

    noeud *racine = NULL;

    insertion_recursive(&racine, 15);
    insertion_recursive(&racine, 25);
    insertion_recursive(&racine, 10);
    insertion_recursive(&racine, 5);
    insertion_recursive(&racine, 12);
    insertion_recursive(&racine, 20);
    insertion_recursive(&racine, 33);
    insertion_recursive(&racine, 1);
    insertion_recursive(&racine, 11);
    insertion_recursive(&racine, 6);
    insertion_recursive(&racine, 13);
    insertion_recursive(&racine, 17);
    insertion_recursive(&racine, 22);


    printf("Parcours GRD:\n");
    parcours_grd(racine);

    printf("Parcours RGD:\n");
    parcours_rgd(racine);


    printf("Suppression de certains éléments (1,10 et 15) :\n");
    // Un élément
    suppression(&racine, 10);

    // Une feuille
    suppression(&racine, 1);

    // Suppression de la racine
    suppression(&racine, 15);


    //printf("Nouveau parcours GRD :\n");
    parcours_grd(racine);

    return 0;
}
