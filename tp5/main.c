// Date 26/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But : Implémenter le tri par fusion/éclatement sur une liste chaînée
// Fichier de test.

#include <stdio.h>
#include <stdlib.h>

#include "liste.h"
#include "tri.h"

int main() {

    // Création des listes
    liste *l1 = NULL;
    liste *l2 = NULL;
    liste *l3 = NULL;
    liste *l4 = NULL;
    liste *l5 = NULL;
    liste *l6 = NULL;
    liste *l7 = NULL;
    liste *l8 = NULL;

    // Cas de test fusion normal
    l2 = ajouter_fin(l2, 3);
    l2 = ajouter_fin(l2, 5);
    l2 = ajouter_fin(l2, 6);
    l2 = ajouter_fin(l2, 7);
    l1 = ajouter_fin(l1, 2);
    l1 = ajouter_fin(l1, 8);
    l1 = ajouter_fin(l1, 9);
    l1 = ajouter_fin(l1, 11);

    // Cas de test fusion avec liste nulle
    l3 = ajouter_fin(l3, 1);
    l3 = ajouter_fin(l3, 5);
    l3 = ajouter_fin(l3, 6);
    l3 = ajouter_fin(l3, 8);

    // Test de fusion de deux listes
    printf("PREMIER TEST: FUSION DE L1 et L2\n");
    liste *test_fusion = fusion(l1, l2);
    afficher(test_fusion);

    // Test de fusion avec une liste nulle ("robustesse")
    printf("--------\n");
    printf("SECOND TEST: FUSION AVEC LISTE NULLE\n");

    liste *test_liste_nulle = fusion(l4, l3);
    afficher(test_liste_nulle);

    // Test d'éclatement d'une liste
    l5 = ajouter_fin(l5, 3);
    l5 = ajouter_fin(l5, 5);
    l5 = ajouter_fin(l5, 6);
    l5 = ajouter_fin(l5, 2);
    l5 = ajouter_fin(l5, 8);
    l5 = ajouter_fin(l5, 9);
    l5 = ajouter_fin(l5, 11);
    l5 = ajouter_fin(l5, 7);
    l5 = ajouter_fin(l5, 4);
    l5 = ajouter_fin(l5, 10);
    l5 = ajouter_fin(l5, 12);
    l5 = ajouter_fin(l5, 15);
    l5 = ajouter_fin(l5, 20);
    l5 = ajouter_fin(l5, 1);
    l5 = ajouter_fin(l5, 19);
    l5 = ajouter_fin(l5, 13);
    l5 = ajouter_fin(l5, 17);

    printf("-------\n");
    printf("TEST D'ECLATEMENT DES LISTES\n");

    eclatement(l5, &l6, &l7);
    afficher(l6);
    printf("-------\n");
    afficher(l7);

    // Test du tri fusion
    l8 = ajouter_fin(l8, 3);
    l8 = ajouter_fin(l8, 5);
    l8 = ajouter_fin(l8, 6);
    l8 = ajouter_fin(l8, 2);
    l8 = ajouter_fin(l8, 8);
    l8 = ajouter_fin(l8, 9);
    l8 = ajouter_fin(l8, 11);
    l8 = ajouter_fin(l8, 7);
    l8 = ajouter_fin(l8, 4);
    l8 = ajouter_fin(l8, 10);
    l8 = ajouter_fin(l8, 12);
    l8 = ajouter_fin(l8, 15);
    l8 = ajouter_fin(l8, 20);
    l8 = ajouter_fin(l8, 1);
    l8 = ajouter_fin(l8, 19);
    l8 = ajouter_fin(l8, 13);
    l8 = ajouter_fin(l8, 17);

    printf("--------\n");
    printf("TRIAGE DE LA LISTE:\n");
    printf("--------\n");

    tri_fusion(&l8);
    afficher(l8);

    // Libère la mémoire utilisée
    vider(&l1);
    vider(&l2);
    vider(&l3);
    vider(&l4);
    vider(&l5);
    vider(&l6);
    vider(&l7);
    vider(&l8);

    return 0;
}
