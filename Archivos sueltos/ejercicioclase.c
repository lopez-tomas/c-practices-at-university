#include <stdio.h>

int main(){
    int i, num, cantNeg = 0, sumPos = 0;

    printf("Ingrese 10 números: ");

    for(i = 1; i <= 10; i++){
        scanf("%d", &num);

        if(num < 0){
            cantNeg++;
        } else{
            sumPos += num;
        }
    }

    printf("Cantidad de Números Negativos: %d\n", cantNeg);
    printf("Sumatoria de Números Positivos: %d\n", sumPos);

    return 0;
}
