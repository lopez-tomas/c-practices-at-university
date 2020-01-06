#include <stdio.h>
#include <string.h>

#define MAX 3

struct Alumno{
    int dni;
    char nomApe[31];
    int nota1;
    int nota2;
};

struct Alumno ingresarAlumno();
float promedio(int,int);

void ingresarAlumnos(struct Alumno[],int);
void mostrarAlumnos(struct Alumno[],int);

int main()
{
    struct Alumno alumnos[MAX];
    ingresarAlumnos(alumnos,MAX);
    mostrarAlumnos(alumnos,MAX);
    return 0;
}

struct Alumno ingresarAlumno(){
    struct Alumno a;
    scanf("%d",&a.dni);
    fflush(stdin);
    gets(a.nomApe);
    scanf("%d",&a.nota1);
    scanf("%d",&a.nota2);
    return a;
}

float promedio(int a,int b){
    return (float)(a+b)/2;
}

void ingresarAlumnos(struct Alumno v[],int ce){
    int i;
    for(i=0;i<ce;i++)
    {
        printf("Ingrese los datos del alumno %d\n",i+1);
        v[i]=ingresarAlumno();
    }
}

void mostrarAlumnos(struct Alumno v[],int ce){
    int i;
   for(i=0;i<ce;i++)
    {
        printf("%d %s %.2f\n",v[i].dni,v[i].nomApe,promedio(v[i].nota1,v[i].nota2));

    }
}









