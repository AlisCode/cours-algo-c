// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Déterminer les irrégularités et les périodes dans une fraction

#include "stdio.h"

// CONSTANTES
#define SIZE_PERIODE 100

#define SIZE_IRREG 100

// Fonctions utilitaires (cf. doc ci-dessous)
int find_index(int tab[], int n, int val);

void calc_periode_et_irregularite(int n, int d, int periode[], int irregularite[]);

void display_tab(int tab[], int n, char *nom);

void init_tab(int tab[], int n);

void do_for(int n, int d);

// Fonction principale
int main() {

    do_for(1, 7);
    printf("\n\n");
    do_for(123, 456);
    printf("\n\n");
    do_for(1, 5);
    printf("\n\n");
    return 0;
}

// Fonction lançant la fonction de calcul de la fraction et gérant l'affichage pour garder le main aussi clair que possible
// n: le numérateur
// d: le dénominateur
void do_for(int n, int d) {
    // Crée les deux tableaux (pour irrégularité et période)
    int irregularite[SIZE_IRREG];
    int periode[SIZE_IRREG];

    // Initialise les deux tableaux
    init_tab(periode, SIZE_PERIODE);
    init_tab(irregularite, SIZE_IRREG);

    // Lance la fonction de calcul
    calc_periode_et_irregularite(n, d, periode, irregularite);

    // Affiche le résultat
    float res = (float) n / (float) d;
    printf("%d / %d = %f\n", n, d, res);
    display_tab(periode, SIZE_PERIODE, "periode");
    printf("\n");
    display_tab(irregularite, SIZE_IRREG, "irregularite");
}

// Effectue le calcul pour la période et l'irrégularité
// n: le numérateur
// d: le dénominateur
// periode: le tableau contenant les valeurs de la période (mémoire modifiée)
// irregularite: le tableau contenant les valeurs de l'irregularite (mémoire modifiée)
void calc_periode_et_irregularite(int n, int d, int periode[], int irregularite[]) {

    int quotients[SIZE_PERIODE] = {};
    int restes[SIZE_PERIODE] = {};

    quotients[0] = n / d;
    restes[0] = n % d;

    for (int nb_loop = 1; nb_loop < d; nb_loop++) {

        // Calcule le quotient et le reste (division entière)
        quotients[nb_loop] = (restes[nb_loop - 1] * 10) / d;
        restes[nb_loop] = (restes[nb_loop - 1] * 10) % d;

        // On vérifie si on a déjà vu ce reste ou pas
        int index = find_index(restes, nb_loop, restes[nb_loop]);
        // Si on a trouvé le reste dans notre tableau, il existe une irrégularité (toutes les valeurs du tableau "quotients" dont l'index est < à index)
        // le reste du tableau "quotients" (d'index à nb_loop) est la période
        if (index != -1) {

            int i_irreg = 0;
            int i_periode = 0;

            for (int i = 1; i <= index; i++) {
                irregularite[i_irreg] = quotients[i];
                i_irreg++;
            }

            for (int i = index + 1; i <= nb_loop; i++) {
                periode[i_periode] = quotients[i];
                i_periode++;
            }

            return;
        }
    }

    // Il n'existe pas de période. On laisse donc le tableau tel quel.
    // L'irregularité est la liste de nombres que l'on a dans le tableau "quotients"
    for (int i = 0; i < d; i++) {
        irregularite[i] = quotients[i];
    }
}

// Fonction permettant de trouver un nombre val dans un tableau tab de longueur n
// tab: le tableau dans lequel chercher
// n: la longueur du tableau
// val: la valeur à chercher
// retourne: -1 si la valeur n'est pas présente dans le tableau
// l'index à laquelle la valeur a été trouvée sinon
int find_index(int tab[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (tab[i] == val) {
            return i;
        }
    }

    return -1;
}

// Affiche le tableau, ou à défaut, le fait qu'il n'y ait aucune valeur dans le tableau (si toutes les valeurs sont égales à -1)
// tab: le tableau à afficher
// n: la longueur du tableau
// nom: le "nom" du tableau ("periode" ou "irregularite")
void display_tab(int tab[], int n, char *nom) {
    int count = 0;
    printf("%s:", nom);
    for (int i = 0; i < n; i++) {
        if (tab[i] != -1) {
            printf("%d", tab[i]);
            count++;
        }
    }

    if (count == 0) {
        printf("pas de %s", nom);
    }
}

// Initialise le tableau donné en paramètre, en mettant toutes ses valeurs à -1
// tab: le tableau à initialiser
// n: la longueur du tableau
void init_tab(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = -1;
    }
}