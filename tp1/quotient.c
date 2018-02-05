// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Déterminer les irrégularités et les périodes dans une fraction

int find_index(int tab[], int n, int val);

void calc_periode_et_irregularite(int n, int d, int periode[], int irregularite[]);

#include "stdio.h"

int main() {

    int periode[10] = {};
    int irregularite[10] = {};

    calc_periode_et_irregularite(1, 7, periode, irregularite);

    printf("periode:");
    for (int i = 0; i < 10; i++) {
        printf("%d", periode[i]);
    }

    printf("\nirreg:");
    for (int i = 0; i < 10; i++) {
        printf("%d", irregularite[i]);
    }

    return 0;
}

void calc_periode_et_irregularite(int n, int d, int periode[], int irregularite[]) {

    int quotients[10] = {};
    int restes[10] = {};

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
        if (index != 0) {

            int i_irreg = 0;
            int i_periode = 0;

            for (int i = 0; i < index; i++) {
                irregularite[i_irreg] = quotients[i];
                i_irreg++;
            }

            for (int i = index; i < nb_loop; i++) {
                periode[i_periode] = quotients[i];
                i_periode++;
            }

            return;
        }
    }

    printf("reached!");
    // Il n'existe pas de période.
    periode[0] = 0;

    // L'irregularité est la liste de nombres que l'on a dans le tableau "quotients"
    for (int i = 0; i < d; i++) {
        irregularite[i] = quotients[i];
    }
}

// Fonction permettant de trouver un nombre val dans un tableau tab de longueur n
// tab: le tableau dans lequel chercher
// n: la longueur du tableau
// val: la valeur à chercher
// retourne: 0 si la valeur n'est pas présente dans le tableau
// l'index à laquelle la valeur a été trouvée sinon
int find_index(int tab[], int n, int val) {
    for (int i = 0; i < n; i++) {
        printf("check if %d == %d\n", tab[i], val);
        if (tab[i] == val) {
            return i;
        }
    }

    return 0;
}