#include <stdio.h>
#define ARENA 0.5

main()
{

    float largo, alto, metrosCuadrados, arenaNecesaria;

    printf("Ingrese el largo de la pared: ");
    scanf("%f", &largo);
    printf("Ingrese el alto de la pared: ");
    scanf("%f", &alto);

    metrosCuadrados = (float)(largo * alto);

    arenaNecesaria = (float)(metrosCuadrados * ARENA);

    printf("La cantidad de arena necesaria es: %.2f", arenaNecesaria);

    return 0;
}
