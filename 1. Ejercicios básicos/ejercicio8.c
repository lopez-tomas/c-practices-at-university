#include <stdio.h>

main()
{
    float base, altura, area, perimetro;

    printf("Ingrese el valor de la base: ");
    scanf("%f", &base);

    printf("Ingrese el valor de la altura: ");
    scanf("%f", &altura);

    area = (float)(base * altura);
    perimetro = (float)2*(base + altura);

    printf("El valor del area es: %.2f", area);
    printf("\nEl valor del perímetro es: %.2f", perimetro);

    return 0;
}
