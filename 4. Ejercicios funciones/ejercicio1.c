#include <stdio.h>
int mcd(int, int);

int main(){
    int num1, num2, resto;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);

    printf("\nIngrese un numero: ");
    scanf("%d", &num2);

    resto = mcd(num1, num2);
    printf("\nEl resto es: %d", resto);

    return 0;
}

int mcd(int a, int b){
    int resto, resto2;

    resto = a % b;

    if(resto == 0){
        resto = b;
    }else{

        do{

        resto2 = b % resto;

        resto2 = resto;

        }while(resto != 0);
        resto = resto;
    }
    return resto;
}
