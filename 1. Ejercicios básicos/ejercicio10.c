#include <stdio.h>
#include <conio.h>
#include <math.h>

main()
{
    float cat1, cat2, hip;

    printf("Ingrese el valor de los catetos: ");
    scanf("%f" "%f", &cat1, &cat2);

    //hip = sqrt(pow(cat1,2) + pow(cat2,2))
    hip = (float)sqrt(pow(cat1,2) + pow(cat2,2));

    printf("El valor de la hipotenusa es: %f", hip);

    return 0;
}
