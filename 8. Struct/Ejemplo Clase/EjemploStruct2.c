#include <stdio.h>
#include <string.h>
struct Fecha
{
    int dia;
    int mes;
    int anio;
};
struct Vacuna
{
    char nomVacuna[21];
    struct Fecha fechaApli;
};
struct Alumno
{
    int dni;
    char nomApe[31];
    struct Fecha fechaNacim;
    struct Vacuna vacunas[20];
};

int main()
{
    struct Alumno al;
    al=ingresarAlumno();
    if(al.fechaNacim.anio < 2000)
    //...
    printf("anio de su primer vacuna %d",al.vacunas[0].fechaApli.anio);


}




