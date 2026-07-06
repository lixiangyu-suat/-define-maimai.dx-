#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;


Matrix* matrix_create(int rows, int cols) {
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    if (!m) return NULL;
    m->rows = rows;
    m->cols = cols;
    m->data = (int*)malloc(rows * cols * sizeof(int));
    if (!m->data) {
        free(m);
        return NULL; //malloc失败
    }
    return m;
}


void matrix_destroy(Matrix *m){
    if (m){
        free(m->data);
        free(m);
    }
}


#define MAT_AT(m, i, j) ((m)->data[(i) * (m)->cols + (j)])


bool matrix_read(Matrix *m){
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j){
            if (scanf("%d", &MAT_AT(m, i, j)) != 1)
                return false;
        }
    }
    return true;
}


void matrix_print(const Matrix *m, const char *name) {
    printf("%s : (row %d, col %d)\n\n", name, m->rows, m->cols);
    for (int i = 0; i < m->rows; ++i){
        for (int j = 0; j < m->cols; ++j){
            printf(" %d", MAT_AT(m, i, j));
        }
        printf("\n");
    }
    printf("\n");
}


Matrix* matrix_multiply(const Matrix *A, const Matrix *B) {
    if (A->cols != B->rows) {
        printf("Dimension mismatch: A.cols(%d) != B.rows(%d)\n", A->cols, B->rows);
        return NULL;
    }

    Matrix *C = matrix_create(A->rows, B->cols);
    if (!C) return NULL;

    int *c_ptr = C->data;
    for (int i = 0; i < A->rows; ++i){
        for (int j = 0; j < B->cols; ++j){
            int sum = 0;
            for (int k = 0; k < A->cols; ++k){
                sum += MAT_AT(A, i, k) * MAT_AT(B, k, j);
            }
            *c_ptr++ = sum;
        }
    }
    return C;
}


int main() {
    int ar, ac, br, bc;
    if (scanf("%d %d %d %d", &ar, &ac, &br, &bc) != 4){
        fprintf(stderr, "Failed to read dimensions.\n");
        return 1;
    }

    Matrix *A = matrix_create(ar, ac);
    Matrix *B = matrix_create(br, bc);
    if (!A || !B) {
        fprintf(stderr, "Memory allacation failed.\n");
        matrix_destroy(A);
        matrix_destroy(B);
        return 1;
    }

    if (!matrix_read(A) || !matrix_read(B)) {
        fprintf(stderr, "Failed to read matrix data.\n");
        matrix_destroy(A);
        matrix_destroy(B);
        return 1;
    }

    Matrix *C = matrix_multiply(A, B);
    if (!C) {
        matrix_destroy(A);
        matrix_destroy(B);
        return 1;
    }

    matrix_print(A, "matrix_a");
    matrix_print(B, "matrix_b");
    matrix_print(C, "matrix_c");

    matrix_destroy(A);
    matrix_destroy(B);
    matrix_destroy(C);
    return 0;
}
