#include <stdio.h>
#include <stdlib.h>
#define tam 6

void ordenamientoBurbujeo(int[], int);

int main(){
    int vector[6];

    printf("%d", vector[]);

    ordenamientoBurbujeo(vector[],tam);

    printf("%d", vector[]);

    return 0;
}

void ordenamientoBurbujeo(int vec[], int ce){
    int i, j, aux, cambio;

    i = 1;

    do{
        cambio = 0;

        for(j = 1 ; j < ce - i ; j++){
            if(vec[j] > vec[j+1]){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;

                cambio = 1;
            }
        }

        i++;
    }while(cambio == 1 && i < ce);
}
