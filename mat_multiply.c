#include <stdio.h>
#include <stdlib.h>
#include "mat_multiply.h"

void get_matrix_dimensions_from_user(char* prompt, int* num_rows, int* num_cols){
    /*
    Display the given prompt to the user, then read two integers from the
    user storing the result in num_rows and num_cols
    @prompt: The prompt to show to the user
    @num_rows: the address of where to store the first number entered by the user
    @num_cols: the address of where to store the second number entered by the user
    @returns: nothing
    @modifies: num_rows, num_cols
    */
    printf("%s", prompt);
    scanf(" %d %d", num_rows, num_cols);
}

int** make_empty_matrix(int row_dim, int col_dim) {
    /*
    Dynamically create a row_dim X col_dim matrix
    A matrix here is an array of array of integers
    You do not need to initialize the values of the numbers in
    the matrix but you can if you want
    @row_dim: the number of rows the matrix should have
    @col_dum: the number of columns the matrix should have
    @returns: a row_dim X col_dim matrix of integers
    @modifies: nothing
    */
   int** matrix = (int**)calloc(col_dim, sizeof(int*));
   for(int i = 0; i<col_dim; i++){
            (matrix)[i] = (int*)calloc(row_dim, sizeof(int));
   }
   return matrix;

}

void fill_matrix_from_user_input(int** matrix, int row_dim, int col_dim) {
    /*
    Fill in the row_dim X col_dim matrix with values entered by the user
    The user will enter in row_dim rows that each have col_dim elements in it.
    For example if row_dim = 3 and col_dim = 4 the user could enter something like
    11 25 43 45
    10 45 63 17
    -8 25 -9 24

    These values should be stored into matrix
    @matrix: the matrix to be filled in
    @row_dim: the number of rows matrix has
    @col_dum: the number of columns matrix has
    @returns: nothing
    @modifies: matrix
    */
    for(int j=0; j<row_dim; j++){
        for(int i=0; i<col_dim; i++){
            scanf(" %d", &matrix[i][j]);
        }
    }
}

int** matrix_multiply(int** matrix_a, int num_rows_a, int num_cols_a,
											int** matrix_b, int num_rows_b, int num_cols_b,
											int* out_num_rows_c, int* out_num_cols_c) {
    /*
    Multiply matrix_a and matrix_b together, returning the resulting matrix
    Set out_num_rows_c to be the number of rows in the resulting matrix
    Set out_num_cols_c to be the number of cols in the resulting matrix
    @matrix_a: the A in C = A X B
    @num_rows_a: the number of rows in matrix a
    @num_cols_a: the number of columns in matrix a
    @matrix_b: the B in C = A X B
    @num_rows_b: the number of rows in matrix b
    @num_cols_b: the number of columns in matrix b
    @out_num_rows_c: where to store the number of rows of the resulting matrix
    @out_num_cols_c: where to store the number of columns of the resulting matrix
    @returns: matrix_a X matrix_b
    @modifies: out_num_rows_c, out_num_cols_c
    */
    if(num_rows_a == num_cols_a){
        }
        
    int n, o, p;
    for(n=0; n<num_rows_a; n++){
        for(o=0; o<num_cols_b; o++){
            for(p=0; p<num_rows_b; p++){        
            }
        }
    } 

    *out_num_cols_c = o;
    *out_num_rows_c = n;

    int* sum = (int*)calloc((*out_num_rows_c) * (*out_num_cols_c),sizeof(int));

    int l, m, k;
    int count1 = 0;
    for(k=0; k<num_rows_a; k++){
        for(l=0; l<num_cols_b; l++){
            for(m=0; m<num_rows_b; m++){
                (sum)[count1] += (matrix_a)[m][k] * (matrix_b)[l][m];
            }
        count1++;
        }
    }    

    int** matrix_c = make_empty_matrix((*out_num_rows_c), (*out_num_cols_c));

    int count2 = 0;
    for(int i=0; i< *out_num_rows_c; i++){
        for(int j=0; j< *out_num_cols_c; j++){
            (matrix_c)[j][i] = (sum)[count2];
        count2++;
        }
    }

    return matrix_c;
}

void print_matrix(int** matrix, int row_dim, int col_dim) {
    /*
    Print matrix to the screen
    @matrix: the matrix to be printed
    @row_dim: the number of rows in matrix
    @col_dim: the number of columns in matrix
    @returns: nothing
    @modifies: nothing
    */
    for(int j=0; j<row_dim; j++){
        for(int i=0; i<col_dim; i++){
            printf("%d ", (matrix)[i][j]);
        }
        printf("\n");
    }

}

void delete_matrix(int** *matrix, int row_dim, int col_dim) {
    /*
    Delete matrix AND set it to NULL.
    @matrix: the address of the matrix to be deleted
    @row_dim: the number of rows in matrix
    @col_dim: the number of columns in matrix
    @returns: nothing
    @modifies: matrix
    */
   
   for(int i=0; i<col_dim; i++){
        free((*matrix)[i]);
        if(i==row_dim){
        }
   }
        free((*matrix));
        *matrix = NULL;
}
