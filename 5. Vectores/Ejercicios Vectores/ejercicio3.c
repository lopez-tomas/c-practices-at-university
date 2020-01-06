#include <stdio.h>
#include <stdlib.h>

#define tam 60

void inicializar(int[], int);
void ingresarTiempo(int[], int);
ingresarValor(int);

int main(){
    int vAutos[60];

    inicializar(vAutos[], tam);
    ingresarTiempo(vAutos, tam);

    return 0;
}

void inicializar(int v[], int c){
    int i;

    for(i = 0 ; i < c ; i++){
        v[i] = 0;
    }
}

void ingresarTiempo(int v[], int c){
    int posicion;
    float seg;

    posicion = ingPosicion(0, e);
}

