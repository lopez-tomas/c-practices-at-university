#include <stdio.h>
#include <string.h>

struct Alumno
{
    int dni;
    char nomApe[31];
    int nota1;
    int nota2;
};
struct Alumno ingresarAlumno();
float promedio(int,int);

int main()
{
    struct Alumno al;
    al=ingresarAlumno();
    printf("%d %s %.2f\n",al.dni,al.nomApe,promedio(al.nota1,al.nota2));
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










