#include "gauss.h"
#include <math.h>
#include <stdio.h>

/**
 * Funkcja wykonuje eliminacjê Gaussa na macierzy mat i modyfikuje odpowiednio
 * wektor prawej strony b.
 * Zwraca 0, jeœli eliminacja zakoñczy siê sukcesem.
 * Zwraca 1, jeœli macierz jest osobliwa (dzielenie przez 0).
 */
int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r; // Zak³adamy, ¿e macierz mat jest kwadratowa (n x n)

    if (mat->c != n || b->r != n || b->c != 1) {
        // Niezgodnoœæ wymiarów
        return 1;
    }

    for (int k = 0; k < n - 1; ++k) {
        // Wybór elementu g³ównego (pivot) i zamiana wierszy
        int maxRow = k;
        for (int i = k + 1; i < n; ++i) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[maxRow][k])) {
                maxRow = i;
            }
        }

        // Zamiana wierszy w macierzy mat
        if (maxRow != k) {
            for (int j = 0; j < n; ++j) {
                double tmp = mat->data[k][j];
                mat->data[k][j] = mat->data[maxRow][j];
                mat->data[maxRow][j] = tmp;
            }
            // Zamiana elementów w wektorze b
            double tmp = b->data[k][0];
            b->data[k][0] = b->data[maxRow][0];
            b->data[maxRow][0] = tmp;
        }

        // Sprawdzenie, czy macierz jest osobliwa
        if (fabs(mat->data[k][k]) < 1e-12) {
            return 1; // Macierz osobliwa
        }

        // Eliminacja
        for (int i = k + 1; i < n; ++i) {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (int j = k; j < n; ++j) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    // Sprawdzenie ostatniego elementu diagonalnego
    if (fabs(mat->data[n - 1][n - 1]) < 1e-12) {
        return 1; // Macierz osobliwa
    }

    return 0; // Sukces
}
