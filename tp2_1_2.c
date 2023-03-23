#include <stdio.h>
#include <stdlib.h>

#define N 20

int main() {
    int i;
    double *vt;
    vt = malloc(sizeof(int) * 20);
    if (vt == NULL) {
        printf("Error");
        exit(-1);
    }

    for (i = 0; i < N; i++) {
        vt[i] = 1 + rand() % 100;
    }
    for (i = 0; i < N; i++) {
        printf("%i ", *(vt + i));
    }

    return 0;
}