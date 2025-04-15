# include "helpers.h"


void mat_mult(const float *A, int A_rows, int A_cols, const float *B, int B_cols, float *C) {

    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            C[i * B_cols + j] = 0.0f;
        }
    }


    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            for (int k = 0; k < A_cols; k++) {
                C[i * B_cols + j] += A[i * A_cols + k] * B[k * B_cols + j];
            }
        }
    }
}


void mat_transpose(const float *A, int rows, int cols, float *A_T) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A_T[j * rows + i] = A[i * cols + j];
        }
    }
}



int invert_3x3(const float A[3][3], float a_inv[3][3]) {
  
    float det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
                A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
                A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    if (det == 0.0f) {
  
        return -1;
    }

    float inv_det = 1.0f / det;

    
    a_inv[0][0] =  (A[1][1] * A[2][2] - A[1][2] * A[2][1]) * inv_det;
    a_inv[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]) * inv_det;
    a_inv[0][2] =  (A[0][1] * A[1][2] - A[0][2] * A[1][1]) * inv_det;

    a_inv[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]) * inv_det;
    a_inv[1][1] =  (A[0][0] * A[2][2] - A[0][2] * A[2][0]) * inv_det;
    a_inv[1][2] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]) * inv_det;

    a_inv[2][0] =  (A[1][0] * A[2][1] - A[1][1] * A[2][0]) * inv_det;
    a_inv[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]) * inv_det;
    a_inv[2][2] =  (A[0][0] * A[1][1] - A[0][1] * A[1][0]) * inv_det;

    return 0; 
}

void vec_subtract(const float *a, const float *b, float *c, int dim) {
    for (int i = 0; i < dim; i++) {
        c[i] = a[i] - b[i];
    }
}

