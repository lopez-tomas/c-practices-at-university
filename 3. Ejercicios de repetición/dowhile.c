#include <stdio.h>

int main(){
    int i, suma = 0;
    float nota, promedio;

    for(i = 1 ; i <= 5 ; i++){
        do{
            printf("Ingrese un numero: ");
            scanf("%f", &nota);

        }while(nota < 1 || nota > 10);

        suma+=nota;
    }

    promedio = (float)suma/5;
    printf("Promedio: %.2f", promedio);

    return 0;
}
