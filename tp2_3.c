#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main() {
    int mt[N][M];
    int *ptr = &mt[0][0];  // Inicializa un puntero al inicio del arreglo
    int i, j;

    srand(time(NULL));  // Establece la semilla del generador de números aleatorios

    printf("\n");

    for (i = 0; i < N; i++) {
        printf("|");
        for (j = 0; j < M; j++) {
            *(ptr + i * M + j) = 1 + rand() % 100;  // Accede al elemento (i,j) del arreglo utilizando aritmética de punteros
            printf("%d ", *(ptr + i * M + j));      // Imprime el valor del elemento (i,j) del arreglo
        }
        printf("|");
        printf("\n");
    }

    return 0;
}