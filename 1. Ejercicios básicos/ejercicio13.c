#include <stdio.h>
#include <math.h>

#define PRESENSAMBLADORA 37
#define PRESPINTURA 42
#define PRESELECTIRA 21

main()
{
    float presupuesto, ensambladora, pintura, electrica;

    printf("Presupuesto = ");
    scanf("%f", &presupuesto);

    ensambladora = (float)(PRESENSAMBLADORA * presupuesto)/100;
    pintura = (float)(PRESPINTURA * presupuesto)/100;
    electrica = (float)(PRESELECTIRA * presupuesto)/100;

    printf("Presupuesto de Ensambladora = %.2f\n", ensambladora);
    printf("Presupuesto de Pintura = %.2f\n", pintura);
    printf("Presupuesto de Electrica = %.2f", electrica);

    return 0;
}
