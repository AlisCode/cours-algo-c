// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Résoudre l'énigme en affichant les différentes lignes 

#include <stdio.h>
#include <string.h>

// Fonctions utilitaire
unsigned int count_value_change(int tab[], int n);

void compute_new_line(int tab[], int n, int new_line[]);

unsigned int solve_enigme(int tab[], int n);

void display_line(int tab[], int n);

// Fonction principale
int main() {

    int tab[10] = {3, 4};
    unsigned int size = 2;
    display_line(tab, size);
    for (int i = 0; i < 4; i++) {
        size = solve_enigme(tab, size);
    }

    return 0;
}

// Compte le nombre de fois qu'on change de valeur dans une ligne
// tab: la ligne qu'on traite
// n: le nombre de valeur
// Retourne: le nombre de changements
unsigned int count_value_change(int tab[], int n) {

    int old_val = tab[0];
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (tab[i] != old_val) {
            count++;
        }
        old_val = tab[i];
    }

    return count;
}

// Résouds l'enigme pour la ligne donnée
// tab: la ligne à résoudre
// n: la longueur de la ligne
// retourne: La longueur de la nouvelle ligne
unsigned int solve_enigme(int tab[], int n) {
    unsigned int count = count_value_change(tab, n) * 2;
    int new_line[10] = {};
    compute_new_line(tab, n, new_line);
    display_line(new_line, count);
    memcpy(tab, new_line, sizeof(int) * count);
    return count;
}

// calcule la nouvelle ligne à partir de l'ancienne et la stocke dans new_line
// tab: l'ancienne ligne
// n: la longueur de l'ancienne ligne
// new_line: la nouvelle ligne (cette mémoire est modifiée)
void compute_new_line(int tab[], int n, int new_line[]) {

    int old_val = tab[0];
    int count_val = 0;
    int index_new_line = 0;

    for (int i = 1; i <= n; i++) {
        count_val++;

        // Si on change de valeurs
        if (tab[i] != old_val) {
            new_line[index_new_line++] = count_val;
            new_line[index_new_line++] = old_val;
            count_val = 0;
        }
        old_val = tab[i];
    }
}

// Affiche le tableau passé en entrée
// tab: le tableau à afficher
// n: la longueur du tableau
void display_line(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

