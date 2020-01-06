#include <stdio.h>

int main(){
    int n, i, cont = 0;
    float promedio = 0, num;

    printf("Ingrese un numero entero: ");
    scanf("%d", &n);

    for(i=1 ; i<=n ; i++){
        printf("\nIngrese un numero: ");
        scanf("%f", &num);
        getchar();

        if(i <= n){
            cont++;
        }
        promedio = (float)(promedio + num)/cont;
    }

    printf("\nPromedio: %.2f\n", promedio);


    return 0;
}
