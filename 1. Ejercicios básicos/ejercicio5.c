#include <stdio.h>
#define MES 12

main()
{
    int year, meses, averiguarMeses, mesesTotales;

    printf("Ingrese una cierta cantidad de años: ");
    scanf("%i", &year);

    printf("Ingrese una cierta cantidad de meses: ");
    scanf("%i", &meses);

    averiguarMeses = year * MES;
    mesesTotales = averiguarMeses + meses;

    printf("Tu edad en meses sería: %i", mesesTotales);

    return 0;
}
