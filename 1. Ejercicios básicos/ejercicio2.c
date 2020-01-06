#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2, suma;
    float promedio;

    printf("Ingrese un numero= ");
    scanf("%d", &numero1);

    printf("Ingrese otro numero= ");
    scanf("%d", &numero2);

    suma = 2 * numero1 + (numero2 * numero2);
    promedio = (float)((numero1 * numero1 * numero1) + (numero2 * numero2 * numero2)) / 2;

    printf("El resultado de la suma es = %d", suma);
    printf("\nEl resultado de b es= %.2f", promedio);

    return 0;
}
