#include <stdio.h>
#include <stdlib.h>
#define DIMENSION 10


void ingresarValores(int[], int);
void mostrarVector(int[], int);
void igualarVector(int[], int[], int);
void sumarVectores(int[], int[], int[], int);
void vectorOpuesto(int[], int[], int);

int main(){
    int vec_A[DIMENSION], vec_B[DIMENSION], vec_C[DIMENSION], vec_D[DIMENSION];
    int i;

    ingresarValores(vec_A, DIMENSION);
    igualarVector(vec_A, vec_B, DIMENSION);
    sumarVectores(vec_A, vec_B, vec_C, DIMENSION);
    vectorOpuesto(vec_A, vec_D, DIMENSION);

    mostrarVector(vec_A, DIMENSION);
    mostrarVector(vec_B, DIMENSION);
    mostrarVector(vec_C, DIMENSION);
    mostrarVector(vec_D, DIMENSION);

    return 0;
}

void ingresarValores(int vec[], int e){
    int i;
    printf("Ingrese los valores del vector: ");
    for(i = 0 ; i < e ; i++){
        fflush(stdin);
        scanf("%d", &vec[i]);
    }
    system("cls");
}

void mostrarVector(int vec[], int e){
    int i;

    printf("\nPosicion\tContenido\n");

    for(i = 0 ; i < e ; i++){
        printf("%d\t \t%d\n",i, vec[i]);
    }
}

void igualarVector(int vec[], int vec2[], int e){
    int i;

    for(i = 0 ; i < e ; i++){
        vec2[i] = vec[i];
    }

}

void sumarVectores(int vec[], int vec2[], int vec3[], int e){
    int i;

    for(i = 0 ; i < e ; i++){
        vec3[i] = vec[i] + vec2[i];
    }
}

void vectorOpuesto(int vec[], int vec2[], int e){
    int i;

    for(i = 0 ; i < e ; i++){
        vec2[i] = vec[e - 1 - i];
    }
}





