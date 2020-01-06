#include <stdio.h>
#define PRECIOXMETRO 10.50

main()
{
    float pedido, precio;

    printf("Metros que necesita: ");
    scanf("%f", &pedido);

    precio = (float)(pedido * PRECIOXMETRO);

    printf("Precio= %.2f", precio);

    return 0;
}
