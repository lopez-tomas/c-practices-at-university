#include <stdio.h>
#define MES 12

main()
{
    int year, meses, averiguarMeses, mesesTotales;

    printf("Ingrese una cierta cantidad de a�os: ");
    scanf("%i", &year);

    printf("Ingrese una cierta cantidad de meses: ");
    scanf("%i", &meses);

    averiguarMeses = year * MES;
    mesesTotales = averiguarMeses + meses;

    printf("Tu edad en meses ser�a: %i", mesesTotales);

    return 0;
}
