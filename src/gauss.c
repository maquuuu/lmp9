#include "gauss.h"
#include <math.h>
#include <stdio.h>

int eliminate(Matrix *mat, Matrix *b){

int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->r; 

		return 0;
}
    if (mat->c != n || b->r != n || b->c != 1) {
       
        return 1;
    }
    for (int k = 0; k < n - 1; ++k) {
        
        int maxRow = k;
        for (int i = k + 1; i < n; ++i) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[maxRow][k])) {
                maxRow = i;
            }
        }
      
        if (maxRow != k) {
            for (int j = 0; j < n; ++j) {
                double tmp = mat->data[k][j];
                mat->data[k][j] = mat->data[maxRow][j];
                mat->data[maxRow][j] = tmp;
            }
          
            double tmp = b->data[k][0];
            b->data[k][0] = b->data[maxRow][0];
            b->data[maxRow][0] = tmp;
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
