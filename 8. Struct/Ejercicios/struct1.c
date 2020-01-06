#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct FechaNacimiento{
  int dia;
  int mes;
  int year;
};

struct FechaIngreso{
  int dia;
  int mes;
  int year;
};

struct FechaAprobacion{
  int dia;
  int mes;
  int year;
};

struct Materias{
  int codMateria;
  struct FechaAprobacion fechaAprobacion;
  int notaAprob;
};

struct Alumno{
  int dni;
  char nomApe[51];
  cha sexo;
  struct FechaNacimiento fechaNacimiento;
  int codCarrera;
  struct FechaIngreso ingreso;
  int materiasAprob;
  struct Materias materias;
  int activo;
};

struct Alumno ingresarAlumno(int);

int ingresarAlumnos(struct Alumno[], int);
void mostrarAlumnos(struct Alumno[], int);

int main(){
  int cant;
  struct Alumno alumnos[MAX];

  cant = ingresarAlumnos(alumnos, MAX);

  return 0;
}

int ingresarAlumnos(struct Alumno a[], int ce){
  int i = 0;

  int alumno = valDNI(0, 10000000, 99999999);

  while(activo != 0){

      printf("Ingrese los datos del alumno %d\n", i+1);
      a[i] = ingresarAlumno(alumno);

      i++;

      alumno = valDNI(0, 10000000, 99999999);
  }

  return i;
}

int valDNI(int cero, int desde, int hasta){
  int dni;

  printf("Ingrese su DNI: ");
  scanf("%d", &dni);

  if(dni != cero){
    while(dni < desde && dni > hasta){
      printf("Ingrese su DNI: ");
      scanf("%d", &dni);
    }
  }

  return dni;
}

struct PERSONA ingresarAlumno(int nroDNI){
    struct PERSONA p;

        p.dni = nroDNI;

        printf("Ingrese su nombre apellido: ");
        fflush(stdin);
        gets(p.nomApe);

        p.sexo = valSexo('F', 'M');

        p.fechaNacimiento.dia = valFecha(1, 31, "Ingrese dia de nacimiento: ");
        p.fechaNacimiento.mes = valFecha(1, 12, "Ingrese mes de nacimiento: ");
        p.fechaNacimiento.year = valFecha(1950, 2010, "Ingrese a�o de nacimiento: ");

        p.codCarrera = valCodigo(0, "Ingrese el código de su carrera: ");

        p.fechaIngreso.dia = valFecha(1, 31, "Ingrese dia de ingreso: ");
        p.fechaIngreso.mes = valFecha(1, 12, "Ingrese mes de ingreso: ");
        p.fechaIngreso.year = valFecha(1950, 2010, "Ingrese anio de ingreso: ");

        p.materiasAprob = valMaterias(0);

        p.Materias.codMateria = valCodigo(0, "Ingrese el código de la materia: ");

        p.Materias.fechaAprobacion.dia = valFecha(1, 31, "Ingrese dia de aprobación: ");
        p.Materias.fechaAprobacion.mes = valFecha(1, 12, "Ingrese mes de aprobación: ");
        p.Materias.fechaAprobacion.year = valFecha(1950, 2010, "Ingrese anio de aprobación: ");

        p.Materias.notaAprob = valCodigo(0, "Ingrese la nota de la materia: ");

        p.activo = alumnoAct(0, 1);

        printf("\n");

    return p;
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

int valFecha(int, int, char msj[]){
  
}

int valCodigo(int desde, char msj[]){
  int cod;

  printf("%s", msj);
  scanf("%d", &cod );

  while(cod <= desde){
    printf("%s", msj);
    scanf("%d", &cod );
  }

  return cod;
}

int valMaterias(int desde){
  int cant;

  printf("Cantidad de materias aprobadas: ");
  scanf("%d", &cant );

  while(cod < desde){
    printf("Cantidad de materias aprobadas: ");
    scanf("%d", &cant );
  }

  return cant;
}

int alumnoAct(int desde, int hasta){
  int act;

  printf("¿El alumno se encuentra activo? (0 = NO | 1 = SI): ");
  scanf("%d", &act );

  while(act < desde & act > hasta){
    printf("¿El alumno se encuentra activo? (0 = NO | 1 = SI): ");
    scanf("%d", &act );
  }

  return act;
}
