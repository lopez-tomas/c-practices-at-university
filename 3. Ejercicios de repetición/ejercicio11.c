#include <stdio.h>

int main(){
    int nro, cont = 0, sum = 0;
    float promedio;

    printf("Ingrese un numero: ");
    scanf("%d", &nro);

    while(nro != 0){
        sum+=nro;
        cont++;

        printf("Ingrese un numero: ");
        scanf("%d", &nro);
    }

    if(cont > 0){
        promedio = (float)sum/cont;

        printf("Promedio: %.2f", promedio);
    }

    return 0;
}
