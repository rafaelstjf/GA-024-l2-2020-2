#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrizes.h"
#include "estruturas.h"
#define N 3
int* cria_array(int (*mat)[N]){
    int* arr = (int*)malloc((N*N)*sizeof(int));
    unsigned int index = 0;
    for(unsigned int i = 0; i < N; i++){
        for(unsigned int j = 0; j < N; j++){
            index = i*N + j;
            arr[index] = mat[i][j];
        }
    }
    return arr;
}
float* cria_array_float(int (*mat)[N]){
    float* arr = (float*)malloc((N*N)*sizeof(float));
    unsigned int index = 0;
    for(unsigned int i = 0; i < N; i++){
        for(unsigned int j = 0; j < N; j++){
            index = i*N + j;
            arr[index] = mat[i][j]*1.0;
        }
    }
    return arr;
}
int main(){
    int matriz[N][N] = {
        {1, 1, 10},
        {1, 4, 2},
        {10, 5, 2}
    };
    int* arr = cria_array(matriz);
    float* arr_f = cria_array_float(matriz);
    if(matriz_identidade(arr, N) > 0)
        printf("Eh matriz identidade!\n");
    else
        printf("Nao eh Matriz identidade!\n");
    if(triangular_superior(arr, N))
        printf("Eh matriz triangular superior!\n");
    else
        printf("Nao eh Matriz triangular superior!\n");
    if(tridiagonal(arr, N))
        printf("Eh matriz tridiagonal!\n");
    else
        printf("Nao eh Matriz tridiagonal!\n");
    printf("Produto da diagonal: %f\n", produto_diagonal(arr_f, N));
    printf("Soma dos elementos inferiores: %f\n", soma_inferior(arr_f, N));
    return 0;

}
