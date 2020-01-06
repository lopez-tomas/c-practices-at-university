#include <stdio.h>

int ingresarValidar(int);
int factorial(int);
int esMultiplo(int, int);

int main(){

    int nro, c3 = 0, c5 = 0, c3y5 = 0, factoreo;

    nro = ingresarValidar(0);

    while(nro != 0){

        factoreo = factorial(nro);
        printf("El factorial de %d es: %d", nro, factoreo);

        if(esMultiplo(nro, 3)){
            c3++;
        }
        if(esMultiplo(nro, 5)){
            c5++;
        }
        if(esMultiplo(nro, 15)){
            c3y5++;
        }

        nro = ingresarValidar(0);

    }

    printf("\nMultiplos de 3: %d", c3);
    printf("\nMultiplos de 5: %d", c5);
    printf("\nMultiplos de 3 y 5: %d", c3y5);

    return 0;
}

int factorial(int n){
    int i, factorial = 1;

    if(n >= 1){
        for(i = 1 ; i <= n ; i++){
            factorial = factorial * i;
        }
    }else{
        factorial = 0;
    }

    return factorial;
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

int ingresarValidar(int desde){
    int num;

    do{
        printf("\nIngrese un numero: ");
        scanf("%d", num);

    }while(num < desde);

    return num;
}

