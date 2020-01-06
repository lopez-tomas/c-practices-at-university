#include <stdio.h>

int main(){
    int cantAlum, i, dni, aprob, cantDesaprobados = 0, cantAprobados = 0;
    float nota, porcAprobados;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &cantAlum);

    for(i=1 ; i<=cantAlum ; i++){

        printf("\nIngrese un DNI: ");
        scanf("%d", &dni);

        printf("\nIngrese la nota: ");
        scanf("%f", &nota);

        if(nota >= 7){
            aprob = 1;
            printf("\nDNI: %d", dni);
            printf("\nAPROBADO\n");

            if(i <= cantAlum){
                cantAprobados++;
            }

        } else{
            aprob = 0;
            printf("\nDNI: %d", dni);
            printf("\nDESAPROBADO\n");

            if(i <= cantAlum){
            cantDesaprobados++;
            }
        }

        porcAprobados = (float)(cantAprobados * 100)/cantAlum;

    }

    printf("\nPorcentaje de aprobados: %.2f\n", porcAprobados);
    printf("Cantidad de desaprobados: %d\n", cantDesaprobados);


    return 0;
}
