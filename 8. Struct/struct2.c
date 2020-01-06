#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO{ /* No hace falta repetir los tipos de datos, podemos agruparlos como en el main */
    int dni;
    char nomApe[41];
    struct FECHA fechaNacimiento;
    struct VACUNA vacunas[20]; // <== Vector de Struct
    int nota1;
    int nota2;
}; // <==

struct FECHA{
    int dia;
    int mes;
    int year;
};

struct VACUNA{
    char nomVac[21];
    struct FECHA fechaApli;
};

int main(){
    struct ALUMNO al;
    al = ingresarAlumno();

    if(al.fechaNacimiento.year < 2000)// <== Estructura anidada
    //...

    printf("Año de su primer vacuna: %d", al.vacunas[0].fechaApli.year);


    return 0;
}
