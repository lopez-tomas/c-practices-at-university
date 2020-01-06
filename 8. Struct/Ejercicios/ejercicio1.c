#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

struct FECHA{
    int dia;
    int mes;
    int year;
};

struct PERSONA{
    int numLeg;
    char apellido[16];
    char nombre[16];
    float altura;
    char sexo;
    struct FECHA fechaNacimiento;
};

struct PERSONA ingresarPersona(int);

int ingresarPersonas(struct PERSONA[], int);
void mostrarPersonas(struct PERSONA[], int);

int valLegajo(int, int);
float valAltura(int);
char valSexo(char, char);
int valFecha(int, int, char[]);

int main(){
    struct PERSONA personas[MAX];
    int algo;

    algo = ingresarPersonas(personas, MAX);
    mostrarPersonas(personas, algo);

    return 0;
}

struct PERSONA ingresarPersona(int nL){
    struct PERSONA p;

        p.numLeg = nL;

        printf("Ingrese su apellido: ");
        fflush(stdin);
        gets(p.apellido);

        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(p.nombre);

        p.altura = valAltura(0);

        p.sexo = valSexo('F', 'M');

        p.fechaNacimiento.dia = valFecha(1, 31, "Ingrese dia de nacimiento: ");
        p.fechaNacimiento.mes = valFecha(1, 12, "Ingrese mes de nacimiento: ");
        p.fechaNacimiento.year = valFecha(1950, 2010, "Ingrese año de nacimiento: ");

        printf("\n");

    return p;
}

int valLegajo(int desde, int hasta){
    int leg;

    printf("Ingrese legajo: ");
    scanf("%d", &leg);

    while(leg < desde && leg > hasta){
        printf("Ingrese legajo: ");
        scanf("%d", &leg);
    }

    return leg;
}

float valAltura(int desde){
    float a;

    printf("Ingrese su altura: ");
    scanf("%f", &a);

    while(a <= desde){
        printf("Ingrese legajo: ");
        scanf("%f", &a);
    }

    return a;
}

char valSexo(char f, char m){
    char s;

    do{

        printf("Ingrese su sexo (F | M): ");
        fflush(stdin);
        scanf("%c", &s);
        s = toupper(s);

    }while(s != f && s != m);

    return s;
}

int valFecha(int desde, int hasta, char cartel[]){
    int f;

    printf("%s\n", cartel);
    scanf("%d", &f);

    while(f < desde && f > hasta){
        printf("%s\n", cartel);
        scanf("%d", &f);
    }
    return f;
}

int ingresarPersonas(struct PERSONA v[], int ce){
    int i = 0;

    int numLeg = valLegajo(0, 10000);

    while(numLeg != 0){

        printf("Ingrese los datos de la persona %d\n", i+1);
        v[i] = ingresarPersona(numLeg);

        i++;

        numLeg = valLegajo(0, 10000);
    }

    return i;
}

void mostrarPersonas(struct PERSONA v[], int ce){
    int i;

    for(i = 0 ; i < ce ; i++){

        printf("Numero de legajo: %d\n", v[i].numLeg);
        printf("Nombre y apellido: %s %s\n", v[i].nombre, v[i].apellido);
        printf("Altura: %.2f\n", v[i].altura);
        printf("Sexo: %c\n", v[i].sexo);
        printf("Fecha de nacimiento: %d/%d/%d", v[i].fechaNacimiento.dia, v[i].fechaNacimiento.mes, v[i].fechaNacimiento.year);
    }

}
