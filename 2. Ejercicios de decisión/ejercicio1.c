#include <stdio.h>

int main()
{
    int nro1, nro2;

    printf("Ingrese dos numeros: ");
    scanf("%d" "%d", &nro1, &nro2);

    if(nro1 > nro2){
       printf("El menor de ellos es: %d", nro2);

    } else if(nro1 == nro2){
        printf("Los numeros son iguales.");

    } else{
        printf("El menor de ellos es: %d", nro1);
    }

    return 0;
}
