#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALUMNO{
    int dni;
    char nomApe[41];
    int nota1;
    int nota2;
}; // <==

// Prototipo de funciones debajo del STRUCT

struct ALUMNO ingresarAlumno();

float promedio(int, int);

int main(){
    struct ALUMNO al; // <== "al" es una variable de tipo struct ALUMNO

    al = ingresarAlumno();

    printf("\n\nDNI: %d\t|| Nombre y Apellido: %s\t|| Promedio: %.2f\n", al.dni, al.nomApe, promedio(al.nota1, al.nota2));

    return 0;
}


struct ALUMNO ingresarAlumno(){

    struct ALUMNO a;

    printf("Ingrese DNI: ");
    scanf("%d", &a.dni);
    fflush(stdin);

    printf("\nIngrese nombre y apellido: ");
    gets(a.nomApe);

    printf("\nIngrese nota 1: ");
    scanf("%d", &a.nota1);


    printf("\nIngrese nota 2: ");
    scanf("%d", &a.nota2);

    return a;
}

float promedio(int a, int b){

    return (float)(a+b)/2;
}
