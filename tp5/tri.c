// Date 26/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But : Implémenter le tri par fusion/éclatement sur une liste chaînée

#include "liste.h"
#include "tri.h"

#include <stdio.h>
#include <stdlib.h>

// Eclate la liste L en deux liste liste1 et liste2 selon le principe de sous-listes vu en cours.
// Liste2 peut être nul.
// l: la liste à éclater (variable en entrée)
// liste1: Adresse de la liste 1 (variable en entrée/sortie)
// liste2: Adresse de la liste 2 (variable en entrée/sortie)
void eclatement(liste *l, liste **liste1, liste **liste2) {
    // Initialise une nouvelle liste
    liste *l1 = NULL;
    liste *l2 = NULL;
    liste *iter = l;

    // Gère le cas d'une liste nulle ou avec un seul élément.
    if (l == NULL || l->next == NULL) {
        *liste1 = l;
        *liste2 = NULL;
        return;
    }

    // Crée les variables pour l'algorithme d'éclatement
    int prev_added = 1;
    l1 = l;
    l2 = NULL;
    iter = l->next;

    // Sauvegarde la tête de liste
    liste *head_l1 = l1;
    liste *head_l2 = NULL;

    // On tourne tant qu'on a encore des variables dans la liste
    while (iter != NULL) {
        // En fonction de la dernière liste dans laquelle on a ajouté une valeur
        if (prev_added == 1) {
            // On ajoute un élément dans l1 si l'élément est supérieur à la dernière valeur de l1
            if (l1->value < iter->value) {
                l1->next = iter;
                l1 = l1->next;
            } else {
                // Sinon ...
                // On gère l'instanciation de l2, qui peut être nul sinon
                if (l2 == NULL) {
                    l2 = iter;
                    head_l2 = l2;
                } else {
                    // On ajoute la valeur dans l2
                    l2->next = iter;
                    l2 = l2->next;
                }
                // On change de liste pour ajouter la suite de la sous-liste
                prev_added = 2;
            }
        } else {
            // On ajoute un élément dans l1 si l'élément est supérieur à la dernière valeur de l2
            if (l2->value < iter->value) {
                l2->next = iter;
                l2 = l2->next;
            } else {
                // Sinon ...
                // Pas besoin de gérer l'instanciation de l1, qui ne peut pas être nul
                l1->next = iter;
                l1 = l1->next;

                // On change de liste pour ajouter la suite de la sous-liste
                prev_added = 1;
            }
        }

        // On avance dans la liste
        iter = iter->next;
    }

    // On rend le dernier élément de l1 nul pour éviter certains cas...
    l1->next = NULL;

    // Sort le contenu des listes éclatées dans les double-pointeurs qu'on a donné en entrée
    *liste1 = head_l1;
    *liste2 = head_l2;
}

// Fusionne les deux listes passées en argument dans une liste qui est retounée
// l1: la première partie de la liste à fusionner
// l2: la deuxième partie de la liste à fusionner
// retourne: la liste fusionnée (et triée)
liste *fusion(liste *l1, liste *l2) {
    // Gère le cas d'une liste vide
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }

    // La liste finale est le pointeur sur lequel on va itérer. On l'initialise à la plus petite valeur entre l1 et l2
    liste *final;
    if (l1->value < l2->value) {
        // Récursivement: lance la fonction de fusion sur les éléments d'après
        final = l1;
        final->next = fusion(l1->next, l2);
    } else {
        // Récursivement: lance la fonction de fusion sur les éléments d'après
        final = l2;
        final->next = fusion(l1, l2->next);
    }

    return final;
}

// Trie la liste dont l'adresse est passée en paramètre en utilisant l'algorithme de tri par éclatement/fusion
// l: Adresse de la liste à trier
void tri_fusion(liste **l) {
    liste *head = *l;
    liste *l1 = NULL;
    liste *l2 = NULL;

    // Gère le cas d'une liste nulle
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Continue tant qu'aucune des listes éclatées n'est nulle
    int continuer = 1;
    do {
        // On éclate la liste...
        eclatement(head, &l1, &l2);
        if (l1 == NULL || l2 == NULL) {
            continuer = 0;
        }
        // Et on la re-fusionne
        head = fusion(l1, l2);
    } while (continuer == 1);

    // On affecte la liste triée en entrée/sortie grâce au double-pointeur
    *l = head;
}
