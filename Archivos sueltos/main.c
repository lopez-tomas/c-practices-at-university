#include <stdio.h>
#include <stdlib.h>

/*
 Muestra la suma de dos números enteros positivos.
*/

int main()
{
    int numero1, numero2, numero3, suma;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

    printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    printf("Ingrese un ultimo numero: ");
    scanf("%d", &numero3);

    suma = numero1 + numero2 + numero3;

    printf("La suma de %d, %d, %d es %d\n", numero1, numero2, numero3, suma);
    getch();

    return 0;
}
