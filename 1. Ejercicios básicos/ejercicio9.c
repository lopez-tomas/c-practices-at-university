#include <stdio.h>
#include <conio.h>

main()
{
    int alumnos, aprobados, desaprobados, ausentes;
    float porcentajeApro, porcentajeDesapro, porcentajeAus;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &alumnos);

    printf("¿Cuantos aprobaron?");
    scanf("%d", &aprobados);

    printf("¿Cuantos desaprobaron?");
    scanf("%d", &desaprobados);

    ausentes = aprobados - desaprobados;

    porcentajeApro = (float)(aprobados * 100)/alumnos;
    porcentajeDesapro = (float)(desaprobados * 100)/alumnos;
    porcentajeAus = (float)(ausentes * 100)/ alumnos;

    printf("Porcentaje de alumnos aprobados: %.2f\n", porcentajeApro);
    printf("Porcentaje de alumnos desaprobados: %.2f\n", porcentajeDesapro);
    printf("Porcentaje de alumnos ausentes: %.2f", porcentajeAus);

    return 0;
}
