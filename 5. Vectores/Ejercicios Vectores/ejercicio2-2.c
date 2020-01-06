#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define tam 10

void inicializar(int[], float[], int);
int ingresarDatos(int[], float[], int);
void mayorSueldo(int[], float[], int);
int ingVal(int, int, int);
float ingValf(int);

int main(){
    float vSueldos[tam];
    int vLegajos[tam], cant;

    inicializar(vLegajos, vSueldos, tam);

    cant = ingresarDatos(vLegajos, vSueldos, tam);

    if(cant != 0){
        mayorSueldo(vLegajos, vSueldos, tam);
    }else{
        printf("No hay trabajadores.");
    }

    return 0;
}

void inicializar(int vL[], float vS[], int e){
    int i;

    for(i = 0 ; i < e ; i++){
        vL[i] = 0;
        vS[i] = 0;
    }
}

int ingresarDatos(int vL[], float vS[], int e){
    int legajo, i;
    float sueldo;

    legajo = ingVal(1000, 9999, 0);

    i = 0;

    while(legajo != 0 && i < e){
        vL[i] = legajo;
        vS[i] = ingValf(0);

        i++;

        legajo = ingVal(1000, 9999, 0);
    }
    return i;
}

void mayorSueldo(int vL[], float vS[], int e){
    float m;
    int i;

    m = vS[0];

    for(i = 1 ; i < e ; i++){
        if(vS[i] > m){
            m = vS[i];
        }
    }

    for(i = 0 ; i < e ; i++){
        if(vS[i] == m){
            printf("%d", vL[i]);
        }
    }
}

int ingVal(int desde, int hasta, )
