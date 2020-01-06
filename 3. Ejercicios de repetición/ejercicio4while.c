#include <stdio.h>

int main(){
    int dni;
    float nota1, nota2, promedio;

    printf("Ingrese un DNI: ");
    scanf("%d", &dni);

    while(dni != 0){
        printf("\nIngrese la 1er nota: ");
        scanf("%f", &nota1);

        printf("\n");

        printf("\nIngrese la 2da nota: ");
        scanf("%f", &nota2);

        promedio = (float)(nota1 + nota2)/2;

        printf("\nDNI: %d", dni);
        printf("\nPromedio: %.2f\n", promedio);

        printf("\nIngrese un DNI: ");
        scanf("%d", &dni);

    }


    return 0;
}
