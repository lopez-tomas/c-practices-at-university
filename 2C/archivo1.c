#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int dni;
    char nomApe[81];
    int n1;
    int n2;
    float nProm;
}T_Alumno;

void infoAlumnos();

int main(){
    T_Alumno Alumnos;

    infoAlumnos();

    return 0;
}

void infoAlumnos(){
    FILE *pf;
    T_Alumno alumno;

    pf = fopen("ALUMNOS.dat", "wb");
    if(pf==NULL){
        printf("NO SE PUDO CREAR EL ARCHIVO.");
        exit(1);
    }

    fwrite(&alumno, sizeof(T_Alumno),1,pf);

    printf("Ingrese el DNI: ");
    scanf("%d", &alumno.dni);

    while(alumno.dni != 0){
        printf("\nNombre y apellido: ");
        fflush(stdin);
        gets(alumno.nomApe);

        printf("\nNota 1: ");
        scanf("%d", alumno.n1);

        printf("\nNota 2: ");
        scanf("%d", alumno.n2);

        alumno.nProm = (alumno.n1+alumno.n2)/2;

        printf("\nIngrese el DNI: ");
        scanf("%d", &alumno.dni);

        fwrite(&alumno, sizeof(T_Alumno),1,pf);
    }
    fclose(pf);
}
