#include <stdio.h>
#include <stdlib.h>

#define tam 5

void inicializar(float[], int);

void ingresarDatos(float[], int);
void mayorSueldo(float[], int);

void mostrarVector(float[], int);

int ingValor(int, int);
float ingValorF(float);

int main(){
    float vSueldos[tam];
    int i;

    inicializar(vSueldos, tam);

    ingresarDatos(vSueldos, tam);

    mayorSueldo(vSueldos, tam);

    mostrarVector(vSueldos, tam);

    //printf("\n%d\n", mayorSueldo);

    return 0;
}

void inicializar(float v[], int e){
    int i;

    for(i = 0 ; i < e ; i++){
        v[i] = 0;
    }
}

void mostrarVector(float v[], int e){
    int i;

    printf("\nPosicion\tContenido\n");

    for(i = 0 ; i < e ; i++){
        printf("%d.\t \t%d\n",i, v[i]);
    }
}

void ingresarDatos(float v[], int e){
    int legajo;
    float sueldo;

    legajo = ingValor(0, e);

    while(legajo != 0){
        sueldo = ingValorF(0);

        v[legajo - 1] = sueldo;

        legajo = ingValor(0, e);
    }
}

void mayorSueldo(float v[], int e){
    int i, b;
    float m;

    m = v[0];
    b = 0;

    for(i = 0 ; i < e ; i++){
        if(v[i] != 0){
            if(b == 0){
                b = 1;
                m = v[i];
            }else if(v[i] > m){
                m = v[i];
            }
        }
    }

    if(b == 1){
        for(i = 0 ; i < e ; i++){
            if(v[i] == m){
                printf("%d" + 1, i);
            }
        }
    }
}

int ingValor(int desde, int hasta){
    int leg;

    do{
        printf("Ingrese legajo: ");
        scanf("%d", &leg);

        system("cls");
    }while(!(leg >= desde && leg <= hasta));

    return leg;
}

float ingValorF(float desde){
    float s;

    do{
        printf("Ingrese el sueldo: ");
        scanf("%f", &s);
    }while(s < desde);

    return s;
}

