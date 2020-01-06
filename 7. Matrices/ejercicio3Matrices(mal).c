#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cam 30
#define con 50

#define chars 7
#define chars2 31

void inicializar(char[][chars], char[][chars2], int[], int[], int[], int[], int[], int, int);
              /* vCamion, vConductor, vImportePorKM, vKMXConductor,vTonXCamion, vKMXCamion, vTonXCamion, cam, con */

void planillaCamion(char[][chars], int[], int);
                 /* vCamion, vImportePorKM && cam */

int validarDatos(int, int);

void viajesXConductor(char[][chars], char[][chars2], int[], int[], int[], int[], int[], int, int);
                  /* vConductor, vKMXConductor, vTonXConductor, vKMXCamion, vTonXCamion, con && cam */

int valConductor(int, int, int);
int buscar(char[][chars], int, char[chars]);

void mostrarA(char[][chars2], int[], int);



int main(){
  /* Para el ingreso POR CAMIÓN */
  char vCamion[cam][chars]; // Guardo Código de Dominio
  int vImportePorKM[cam]; // Guardo Importe a cobrar por KM

  /* Para el ingreso de CADA VIAJE REALIZADO POR UN CONDUCTOR */
  char vConductor[con][chars2]; // Guardo Nombre de Conductor
  int vKMXConductor[con]; // Guardo Kilometros para cada Conductor
  int vImporteRecaudado[con]; // Guardo Importe recaudado para cada Conductor
  int vKMXCamion[cam]; // Guardo Kiometros para cada Camión
  int vTonXCamion[cam]; // Guardo Toneladas para cada Camión

  int cantidad;

  inicializar(vCamion, vConductor, vImportePorKM, vKMXConductor, vImporteRecaudado, vKMXCamion, vTonXCamion, cam, con);

  planillaCamion(vCamion, vImportePorKM, cam);

  printf("\n\n");

  viajesXConductor(vCamion, vConductor, vImportePorKM, vKMXConductor, vImporteRecaudado, vKMXCamion, vTonXCamion, con, cam);
  printf("\nCantidad de Conductores: %d", cantidad);

  printf("\nPunto a)\n");
  mostrarA(vConductor, vImporteRecaudado, con);
  printf("\n\n");

  return 0;
}

void inicializar(char vCam[][chars], char vCon[][chars2], int vImpXKM[], int vKMXCon[], int vImpR[], int vKMXCam[], int vTXCam[], int cCam, int cCon){

  int i;

  for(i = 0 ; i < cCam ; i++){
    //strcpy(vCam[i][chars], "N");
    vImpXKM[i] = 0;
    vKMXCam[i] = 0;
    vTXCam[i] = 0;
  }

  for(i = 0 ; i < cCon ; i++){
    //strcpy(vCon[i][chars2], "N");
    vKMXCon[i] = 0;
    vImpR[i] = 0;
  }
}

void planillaCamion(char vCam[][chars], int vImpXKM[], int cCam){
  char cod[chars];
  int imp, i;

  i = 0;

  printf("Ingrese el Código de Dominio del Camión: ");
  fflush(stdin);
  gets(cod);

  while(strcmpi(cod, "N") != 0 && i < cCam){

    imp = validarDatos(0, 0);

    strcpy(vCam[i], cod);
    vImpXKM[i] = imp;

    printf("Ingrese el Código de Dominio del Camión: ");
    fflush(stdin);
    gets(cod);

    i++;
  }
}

int validarDatos(int desde, int cual){
  int dato;

  if(cual == 0){
    printf("Ingrese el Importe a cobrar por KM: ");
    scanf("%d", &dato);

    while(dato < desde){
      printf("Ingrese el Importe a cobrar por KM: ");
      scanf("%d", &dato);
    }
  }else if(cual == 1){
    printf("Ingrese la cantidad de KM: ");
    scanf("%d", &dato);

    while(dato < desde){
      printf("Ingrese la cantidad de KM: ");
      scanf("%d", &dato);
    }
  }else if(cual == 2){
    printf("Ingrese la cantidad de Toneladas: ");
    scanf("%d", &dato);

    while(dato < desde){
      printf("Ingrese la cantidad de Toneladas: ");
      scanf("%d", &dato);
    }
  }

  return dato;
}

void viajesXConductor(char vCam[][chars], char vCon[][chars2], int ImpXKM[], int vKMXCon[], int vImpR[], int vKMXCam[], int vTXCam[], int cCon, int cCam){
  //int cantConductores = 0;
  int nroConductor, cantKM, toneladas, busqueda;
  char nombre[chars2];
  char cod[chars];

  nroConductor = valConductor(1, 50, 100);

  while(nroConductor != 100) {

    printf("\nIngrese el nombre del conductor: ");
    fflush(stdin);
    gets(nombre);

    printf("\nIngrese el código del camión: ");
    fflush(stdin);
    gets(cod);

    cantKM = validarDatos(0, 1);
    toneladas = validarDatos(0 , 2);

    strcpy(vCon[nroConductor - 1][chars2], nombre);

    busqueda = buscar(vCam, cCam, cod);

    vImpR[nroConductor - 1] = toneladas * busqueda; // Punto a)
    vKMXCam[busqueda - 1] = cantKM; // Punto b)
    vTXCam[busqueda - 1] = toneladas; // Punto c)

    //cantConductores++;

    nroConductor = valConductor(1, 50, 100);

  }

  //return cantConductores;
}
int valConductor(int desde, int hasta, int pos){
  int nro;

  printf("Ingrese el Nro. de Conductor: ");
  scanf("%d", &nro);

  while(nro < desde && nro > desde){
    printf("Ingrese el Nro. de Conductor: ");
    scanf("%d", &nro);
  }

  if(nro == pos){
    nro = pos;
  }

  return nro;
}
int buscar(char vCam[][chars], int cCam, char cod[]){
  int i, pos;

  i = 0;
  pos = -1;

  while(pos == -1 && i < cCam){
    if(strcmpi(vCam[i], cod) == 0){
      pos = i;
    }else{
      i++;
    }
  }

  return pos;
}

void mostrarA(char vCon[][chars2], int vImpR[], int cCon){
  int i;

  printf("\nNro. de Conductor\t Importe Recaudado\n");

  for(i = 0 ; i < cCon ; i++){
    printf("%d\t %d\n", i+1, vImpR[i]);
  }
}
