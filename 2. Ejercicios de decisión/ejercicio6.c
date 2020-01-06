#include <stdio.h>
#include <stdint.h>

int main()
{
    int dia1, mes1, year1, dia2, mes2, year2, fecha1, fecha2;

    printf("Ingrese una fecha (dia/mes/year): ");
    scanf("%d" "%d" "%d", &dia1,&mes1 ,&year1);

    printf("Ingrese otra fecha (dia/mes/year):");
    scanf("%d" "%d" "%d", &dia2, &mes2, &year2);

    fecha1 = (year1*10000)+(mes1*100)+(dia1);
    fecha2 = (year2*10000)+(mes2*100)+(dia2);

    if(fecha1 > fecha2){
        printf("La fecha mas reciente es: %d/%d/%d", dia1, mes1, year1);
    } else{
        printf("La fecha mas reciente es: %d/%d/%d", dia2, mes2, year2);
    }

    return 0;
}
