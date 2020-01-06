#include <stdio.h>

main()
{
    float nro1, nro2, nro3, suma, resta, multi;

    printf("Ingrese 4 números: ");
    scanf("%f" "%f" "%f", &nro1, &nro2, &nro3);

    printf("\n");

    suma = (float)nro1 + nro2 + nro3;
    resta = (float)nro1 - nro2 - nro3;
    multi = (float)nro1 * nro2 * nro3;

    printf("La suma es: %.2f", suma);
    printf("\nLa resta es: %.2f", resta);
    printf("La multiplicación es: %.2f", multi);

    return 0;
}
