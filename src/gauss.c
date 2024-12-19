#include "gauss.h"
#include <math.h>
#include <stdio.h>

int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r;

    for (int k = 0; k < n - 1; k++) {
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[maxRow][k])) {
                maxRow = i;
            }
        }

        if (maxRow != k) {
            for (int j = 0; j < n; j++) {
                double temp = mat->data[k][j];
                mat->data[k][j] = mat->data[maxRow][j];
                mat->data[maxRow][j] = temp;
            }
            double temp = b->data[k][0];
            b->data[k][0] = b->data[maxRow][0];
            b->data[maxRow][0] = temp;
        }

        for (int i = k + 1; i < n; i++) {
            if (mat->data[k][k] == 0.0) {
                return 1;
            }
            double factor = mat->data[i][k] / mat->data[k][k];
            mat->data[i][k] = 0.0;
            for (int j = k + 1; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    for (int i = 0; i < n; i++) {
        if (mat->data[i][i] == 0.0) {
            return 1;
        }
    }
