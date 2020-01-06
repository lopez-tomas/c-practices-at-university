#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define tam 80

void inicializar(int[], float[], int);
float ingAlumnos(int[], float[], int);
void mostrarVector(int[], float[], int);
void ordenar(int[], float[], int);


int valDNI(int, int, int);
int valNota(int, int);
int valNota2(int, int);
float promedio(int, int);
float porcPromo(int, int);

int main(){
  int vAlumnos[tam];
  float vPromedio[tam];
  float porcentajePromocionados;

  inicializar(vAlumnos, vPromedio, tam);
  porcentajePromocionados = ingAlumnos(vAlumnos, vPromedio, tam);

  printf("\nPorcentaje de Alumnos Promocionados: %.2f\n", &porcentajePromocionados);
  printf("\n");
  mostrarVector(vAlumnos, vPromedio, tam);

  return 0;
}

void inicializar(int vA[], float vProm[], int ce){
  int i;

  for(i = 0 ; i <= ce ; i++){
    vA[i] = 'N';
    vProm[i] = 0;
  }
}

float ingAlumnos(int vA[], float vProm[], int ce){
  int dni, nota1, nota2, i = 0 , alumnosPromocionados = 0, totalAlumnos = 0;
  float prom, porcPromocionados;

  dni = valDNI(30000000, 99999999, 0);

  while(dni != 0 && i < ce){

    vA[i] = dni;

    nota1 = valNota(1, 10);
    nota2 = valNota2(1, 10);

    printf("\n");

    prom = promedio(nota1, nota2);

    vProm[i] = prom;

    if(nota1 >= 7 && nota2 >= 7){
      alumnosPromocionados++;
    }

    totalAlumnos++;

    i++;
    dni = valDNI(30000000, 99999999, 0);

    porcPromocionados = porcPromo(alumnosPromocionados, totalAlumnos);
  }
  return porcPromocionados;
}

void mostrarVector(int vA[], float vProm[], int ce){
  int i;

  printf("DNI\t\t Promedio\n");

  ordenar(vA, vProm, ce);

  for(i = 0 ; i < ce ; i++){
    if(vA[i] != 0 && vProm[i] != 0){
      printf("%d\t %.2f\n", vA[i], vProm[i]);
    }
  }
}

void ordenar(int vA[], float vProm[], int ce){
  int i, j, aux, cambio;
  float auxF;

  i = 1;

  do{
    cambio = 0;

    for(j = 0 ; j < ce - i ; j++){
      if(vProm[j] < vProm[j+1]){
        auxF = vProm[j];
        vProm[j] = vProm[j+1];
        vProm[j+1] = auxF;

        aux = vA[j];
        vA[j] = vA[j+1];
        vA[j+1] = aux;

        cambio = 1;
      }
    }

    i++;

  }while(cambio == 1 && i < ce);
}

int valDNI(int desde, int hasta, int cero){
  int dni;

  printf("Ingrese su DNI: ");
  scanf("%d", &dni);

  while(dni < desde && dni > hasta && dni < cero){
    printf("\nIngrese su DNI: ");
    scanf("%d", &dni);
  }
  return dni;
}

int valNota(int desde, int hasta){
  int n;

  printf("\nIngrese nota del primer parcial: ");
  scanf("%d", &n);

  while(n < desde && n > hasta){
    printf("\nIngrese nota del primer parcial: ");
    scanf("%d", &n);
  }
  return n;
}

int valNota2(int desde, int hasta){
  int n;

  printf("\nIngrese nota del segundo parcial: ");
  scanf("%d", &n);

  while(n < desde && n > hasta){
    printf("\nIngrese nota del segundo parcial: ");
    scanf("%d", &n);
  }
  return n;
}

float promedio(int n1, int n2){
  float p;

  return p = (float)(n1 + n2)/2;
}

float porcPromo(int aP, int tA){
  float d, p;

  d = (float)(aP / tA);
  p = (float)(d*100);

  return p;
}
