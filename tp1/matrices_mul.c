// Date 05/02/2018
// Author <olivier.pinon@cpe.fr>
// Author <richard.raduly@cpe.fr>
// But :
// Multiplier deux matrices (de taille fixe, puis de façon générique)
// Afficher deux matrices

#include <stdio.h>

// Fonction multipliant deux matrices de taille 3x3, stocke le résultat dans res, tq. res = mat1 * mat2
void multiplication(int mat1[][3], int mat2[][3], int res[][3]);

// Fonction multipliant deux matrices de taille nxn, stocke le résultat dans res, tq. res = mat1 * mat2
void multiplication_generic(int n, int mat1[][n], int mat2[][n], int res[][n]);

// Affiche dans le flux de sortie standard une matrice donnée de taille nxn
void display_matrix(int n, int mat[][n]);

// Fonction principale
int main() {
    // Déclaration des deux matrices
    int mat1[3][3] = {1, 0, 1, 2, 0, 1, 3, 1, 2};
    int mat2[3][3] = {2, 2, 8, 1, 1, 0, 5, 3, 6};

    // Déclaration des matrices pour stocker le résultat
    int res[3][3] = {};
    int res_generic[3][3] = {};

    // Appelle la fonction de multiplication
    multiplication(mat1, mat2, res);

    // Appelle la fonction de multiplication générique
    multiplication_generic(3, mat2, mat1, res_generic);

    // Affiche la matrice de résultat 1
    printf("Matrice 1 : \n");
    display_matrix(3, res);

    // Affiche la matrice de résultat 2
    printf("Matrice 2 : \n");
    display_matrix(3, res_generic);

    // fin du programme
    return 0;

}

// Fonction multipliant deux matrices de taille 3x3, stocke le résultat dans res, tq. res = mat1 * mat2
// mat1: la matrice a
// mat2: la matrice b
// res: la matrice contenant le résultat
void multiplication(int mat1[][3], int mat2[][3], int res[][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            res[i][j] = sum;
        }
    }
}

// Fonction multipliant deux matrices de taille nxn, stocke le résultat dans res, tq. res = mat1 * mat2
// n: la taille de la matrice
// mat1: la matrice a
// mat2: la matrice b
// res: la matrice contenant le résultat
void multiplication_generic(int n, int mat1[][n], int mat2[][n], int res[][n]) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            res[i][j] = sum;
        }
    }
}

// Affiche dans le flux de sortie standard une matrice donnée de taille nxn
// n: la taille de la matrice
// mat: la matrice à afficher
void display_matrix(int n, int mat[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


