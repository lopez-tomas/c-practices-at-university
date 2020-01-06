#include <stdio.h>

int esMultiplo(int, int);

int main(){
    int nro1, nro2, multiplo;

    printf("Ingrese un numero: ");
    scanf("%d", &nro1);

    printf("\nIngrese un numero: ");
    scanf("%d", &nro2);

    printf("\n");

    esMultiplo(nro1, nro2);

    return 0;
}

int esMultiplo(int n1, int n2){
    int resto, multiplo;

    resto = n1 % n2;

    if(resto == 0){
        multiplo = 1;
        printf("\n1");
    }else{
        multiplo = 0;
        printf("\n0");
    }

    return multiplo;

}

