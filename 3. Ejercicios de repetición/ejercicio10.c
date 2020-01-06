#include <stdio.h>

int main(){
    int i, num, factorial = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("El factorial de %d es: %d\n", num, factorial);

    if(num < 0){
        printf("El factorial de %d es: 0", num);
    }else if(num == 0){
        printf("El factorial de %d es: 1", num);
    }else{
        for(i = 1 ; i <= num ; i++){
        factorial = factorial * i;
        }
    }

    return 0;
}
