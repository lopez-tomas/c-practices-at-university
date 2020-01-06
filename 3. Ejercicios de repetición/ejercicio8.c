#include <stdio.h>

int main(){
    int i, num, cantMayores = 0;
    float promedio, sumMayores = 0, sumMenores = 0;

    printf("Ingrese 10 numeros enteros: ");

    for(i = 1 ; i <= 10 ; i++){
        scanf("%d", &num);
        getchar();

        if(num >= 100){
            cantMayores++;
            sumMayores+=num;
        }

        if(num <= -10){
            sumMenores+=num;
        }
    }

    promedio = (float)(sumMayores * 100) / cantMayores;

    printf("\nPromedio de los > 100: %.2f\n", promedio);
    printf("\nSumatoria de los < -10: %.2f", sumMenores);


    return 0;
}
