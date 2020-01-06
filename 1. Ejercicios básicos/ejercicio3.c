#include <stdio.h>
#include <math.h>

main()
{
    int numero, suma, nro1, modulo1, nro2, modulo2, nro3, modulo3, nro4;

    printf("Ingrese un número de 4 cifras positivo: ");
    scanf("%i", &numero);

    nro1 = numero/1000;
    modulo1 = numero%1000;

    nro2 = modulo1/100;
    modulo2 = modulo1%100;

    nro3 = modulo2/10;
    modulo3 = modulo2%10;

    nro4 = modulo3/1;

    suma = nro1 + nro2 + nro3 + nro4;

    printf("La suma de cada número que compone %i es: %i", numero, suma);

    return 0;
}
