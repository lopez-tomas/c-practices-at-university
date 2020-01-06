#include <stdio.h>
#include <stdint.h>

int main()
{
    float nro1, nro2, resta, suma;

    printf("Ingrese dos numeros: ");
    scanf("%f" "%f", &nro1, &nro2);

    if(nro1 > nro2){
        resta = nro1 - nro2;
        printf("La resta es: %.2f", resta);
    } else{
        suma = nro1 + nro2;
        printf("La suma es: %.2f", suma);
    }

    return 0;
}
