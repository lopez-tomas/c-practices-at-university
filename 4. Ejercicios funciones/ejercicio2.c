#include <stdio.h>

int factorial(int);

int main(){
    int num, factoreo;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &num);

    factoreo = factorial(num);
    printf("\nEl factorial de %d es: %d", num, factoreo);

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
