#include <stdio.h>
#include <stdlib.h>
#include <time.h>  //Agrego esta funcion para generar una semilla random cada vez que ejecute el programa

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
void pcVieja(compu vector[]);
void pcVeloz(compu vector[]);

int main() {
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int i;
    compu vector[5];

    srand(time(NULL));
    /*Con esto cada vez que se ejecute el programa dara un resultado distinto, ya que cambiamos la semilla
     */
    // relleno el vector

    for (i = 0; i < 5; i++) {
        vector[i].velocidad = rand() % 3 + 1;
        vector[i].anio = rand() % 8 + 2015;
        vector[i].cantidad = rand() % 8 + 1;
        vector[i].tipo_cpu = tipos[rand() % 6];
    }

    lista(vector);
    pcVieja(vector);
    pcVeloz(vector);
    return 0;
}

void lista(compu pc[]) {
    printf("Las computadoras enlistadas son: \n");
    int i;
    for (i = 0; i < 5; i++) {
        printf("Velocidad de procesamiento: %d \n", pc[i].velocidad);
        printf("Anio de fabricacion: %d \n", pc[i].anio);
        printf("Cantidad de nucleos: %d \n", pc[i].cantidad);
        printf("Tipo de procesador%s\n", pc[i].tipo_cpu);
        printf("\n\n");
    }
}

void pcVieja(compu pc[]) {
    int i, menor, indice;
    for (i = 0; i < 5; i++) {
        if (i == 0) {
            menor = pc[0].anio;
            indice = i;
        } else {
            if (menor > pc[i].anio) {
                menor = pc[i].anio;
                indice = i;
            }
        }
    }

    printf("El computador mas viejo es: \n");
    printf("Velocidad de procesamiento: %d \n", pc[indice].velocidad);
    printf("Anio de fabricacion: %d \n", pc[indice].anio);
    printf("Cantidad de nucleos: %d \n", pc[indice].cantidad);
    printf("Tipo de procesador: %s\n", pc[indice].tipo_cpu);
    printf("\n\n");
}

void pcVeloz(compu pc[]) {
    int i, veloz, indice;
    for (i = 0; i < 5; i++) {
        if (i == 0) {
            veloz = pc[0].velocidad;
            indice = i;
        } else {
            if (veloz < pc[i].velocidad) {
                veloz = pc[i].velocidad;
                indice = i;
            }
        }
    }

    printf("El computador mas veloz es: \n");
    printf("Velocidad de procesamiento: %d \n", pc[indice].velocidad);
    printf("Anio de fabricacion: %d \n", pc[indice].anio);
    printf("Cantidad de nucleos: %d \n", pc[indice].cantidad);
    printf("Tipo de procesador: %s\n", pc[indice].tipo_cpu);
    printf("\n\n");
}
