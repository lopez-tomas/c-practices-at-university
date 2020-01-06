#include <stdio.h>
#include <stdlib.h>

int ingresarValor(int);
float porcentajeAB(int, int);

int main(){

    int nro1, nro2;
    float porcentaje;

    ingresarValor(nro1);
    ingresarValor(nro2);

    porcentaje = porcentajeAB(nro1, nro2);
    printf("El porcentaje de A sobre B es: %.2f", porcentaje);

    return 0;
}

int ingresarValor(int n){

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    system("cls");
    return n;
}

float porcentajeAB(int n1, int n2){
    float porcentaje;

    porcentaje =(float)(n1 / n2) * 100;

    return porcentaje;
}
