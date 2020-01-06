#include <stdio.h>

int main()
{
    int cantAlum, dni, i;
    float nota1, nota2, promedio;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &cantAlum);
    getchar();

    for(i=1 ; i<=cantAlum ; i++){
        printf("\nIngrese su DNI: ");
        scanf("%d", &dni);
        getchar();

        printf("\nIngrese 1er nota: ");
        scanf("%f", &nota1);
        getchar();

        printf("Ingrese 2da nota: ");
        scanf("%f", &nota2);
        getchar();

        promedio = (float)(nota1 + nota2)/2;

        printf("\nDNI %d: %d\n", i, dni);
        printf("Promedio: %.2f\n", promedio);
        printf("\n");
    }

    printf("\nGracias por utilizar el sistema.\n");

    return 0;
}
