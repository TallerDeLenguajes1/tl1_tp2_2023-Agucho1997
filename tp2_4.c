#include <stdio.h>
#include <stdlib.h>

/*
c) Escribe una función que presente la lista de las PC, cada una con sus características.
d) Escribe una función que presente la PC más vieja.
e) Escribe una función que presente la PC que tiene mayor velocidad.
*/

typedef struct {
    int velocidad;   // entre 1 y 3 GHz
    int anio;        // entre 2015 y 2023
    int cantidad;    // entre 1 y 8
    char *tipo_cpu;  // valores del arreglo tipos
} compu;

void lista(compu vector[]);

int main() {
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int i;
    compu vector[5];

    // relleno el vector

    for (i = 0; i < 5; i++) {
        vector[i].velocidad = rand() % 3 + 1;
        vector[i].anio = rand() % 8 + 2015;
        vector[i].cantidad = rand() % 8 + 1;
        vector[i].tipo_cpu = tipos[rand() % 6];
    }

    lista(vector);
    return 0;
}

void lista(compu pc[]) {
    printf("Las computadoras enlistadas son: \n");
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d \n", pc[i].velocidad);
        printf("%d \n", pc[i].anio);
        printf("%d \n", pc[i].cantidad);
        printf("%s\n", pc[i].tipo_cpu);
        printf("\n\n");
    }
}
