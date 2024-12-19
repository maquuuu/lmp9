#include "gauss.h"
#include <math.h>
#include <stdio.h>

void swapRows(Matrix *mat, int row1, int row2) {
    for (int j = 0; j < mat->c; ++j) {
        double tmp = mat->data[row1][j];
        mat->data[row1][j] = mat->data[row2][j];
        mat->data[row2][j] = tmp;
    }
}

void swapB(Matrix *b, int row1, int row2) {
    double tmp = b->data[row1][0];
    b->data[row1][0] = b->data[row2][0];
    b->data[row2][0] = tmp;
}

int findMaxPivot(Matrix *mat, int col, int startRow) {
    int maxRow = startRow;
    for (int i = startRow + 1; i < mat->r; ++i) {
        if (fabs(mat->data[i][col]) > fabs(mat->data[maxRow][col])) {
            maxRow = i;
        }
    }
    return maxRow;
}

int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r;

int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r; 

		return 0;
}
    if (mat->c != n || b->r != n || b->c != 1) {

        return 1; 

    }
    for (int k = 0; k < n - 1; ++k) {

     
        int maxRow = findMaxPivot(mat, k, k);

     
        if (maxRow != k) {
            swapRows(mat, k, maxRow);
            swapB(b, k, maxRow);
        }

      

        if (fabs(mat->data[k][k]) < 1e-12) {
            return 1; 
        }

        for (int i = k + 1; i < n; ++i) {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (int j = k; j < n; ++j) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    if (fabs(mat->data[n - 1][n - 1]) < 1e-12) {
        return 1;
    }
    return 0; 
}

