#include <stdio.h>
#include <math.h>

#define PI 3.14159

main()
{
    float radio, diametro, perimetro, superficie;

    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);

    diametro =(float) radio * 2;
    perimetro = (float) PI * diametro;
    superficie = (float) PI * (radio * radio);

    printf("El diametro es: %.2f\n", diametro);
    printf("El perimetro es: %.2f\n", perimetro);
    printf("La superficie es: %.2f", superficie);

}
