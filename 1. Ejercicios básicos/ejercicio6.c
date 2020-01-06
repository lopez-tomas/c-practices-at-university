#include <stdio.h>
#include <conio.h>

main()
{
    int n1, n2, n3, n4;
    float promedio;

    printf("Ingrese cuatro notas:\n ");
    scanf("%d" "%d" "%d" "%d", &n1, &n2, &n3, &n4);

    promedio = (float)(n1+n2+n3+n4)/4;

    printf("El promedio de las notas es %.2f", promedio);
    return 0;
}
