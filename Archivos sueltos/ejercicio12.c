#include <stdio.h>

#define DOLAR 43.58
#define EURO 48.92

main()
{
    float peso, dolar, euro;

    printf("Cuantos pesos desea cambiar? ");
    scanf("%f", &peso);

    dolar = peso/DOLAR;
    euro = peso/EURO;

    printf("Su cambio en dolares es: %.2f\n", dolar);
    printf("Su cambio en euroes es: %2.f", euro);

}
