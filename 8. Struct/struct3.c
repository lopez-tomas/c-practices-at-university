#include <stdio.h>
#include <stdlib.h>

#define MAX 80

struct ALUMNO{ /* No hace falta repetir los tipos de datos, podemos agruparlos como en el main */
    int dni;
    char nomApe[41];
    int nota1;
    int nota2;
}; // <==

void ingresarAlumnos(struct ALUMNO[], int);
void mostrarAlumnos(struct ALUMNO[], int);

struct ALUMNO ingresarAlumno();

float promedio(int, int);

int main(){

    struct ALUMNO alumnos[MAX];

    struct ALUMNO al; // <== "al" es una variable de tipo struct ALUMNO

    al = ingresarAlumno();

    printf("\n\nDNI: %d\t|| Nombre y Apellido: %s\t|| Promedio: %.2f\n", al.dni, al.nomApe, promedio(al.nota1, al.nota2));

    ingresarAlumnos(alumnos, MAX);
    mostrarAlumnos(alumnos, MAX);

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

void ingresarAlumnos(struct Alumnos v[], int ce){
    int i;

    for(i = 0 ; i < ce ; i++){
        printf("Ingrese lo datos del alumno %d\n", i);

        v[i] = ingresarAlumno();
    }
}

void mostrarAlumnos(struct Alumnos v[], int ce){
    int i;

    for(i = 0 ; i < ce ; i++){
        printf("DNI: %d\t Nombre: %s\t Promeido: %.2f\n", v[i].dni, v[i].nomApe, promedio(v[i].nota1, v[i].nota2));
    }
}

