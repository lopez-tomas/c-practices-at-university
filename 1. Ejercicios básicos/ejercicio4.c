#include <stdio.h>

main()
{
    int yearNac, mesNac, diaNac, nacimiento, yearAct, mesAct, diaAct, fechaAct, edad;

    printf("Ingrese su fecha de nacimiento (anio/mes/dia): ");
    scanf("%d" "%d" "%d", &yearNac, &mesNac, &diaNac);

    printf("Ingrese la fecha actual (año/mes/dia):");
    scanf("%d" "%d" "%d", &yearAct, &mesAct, &diaAct);

    nacimiento = (yearNac*10000)+(mesNac*100)+(diaNac);
    fechaAct = (yearAct*10000)+(mesAct*100)+(diaAct);

    edad = (fechaAct - nacimiento)/10000;

    printf("Tu edad: %d", edad);

    return 0;
}
