#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define cam 30
#define con 50
#define chars 7
#define chars2 31

void inicializar(char[][chars], char[][chars2], int[], int[], int[], int[], int[] ,int, int);
             /*  vCodDom,       vNombres,       vImpXKM, vImpRXConductor, vKMXCam, vTonXCam, vNro, cCam, cCon */

void planillaCamion(char[][chars], int[], int);

int validarDato(int, int); // La uso para validar IMPORTE, CANT. DE KM && TONELADAS

void viajesXConductor(int[], char[][chars2], char[][chars], int[], int[], int[], int[], int, int);
                  /* vImpRXConductor, vNombres, vCodDom, vImpXKM, vKMXCam, vTonXCam, vNro, cCam, cCon */

int valNumero(int, int);
             /*1 & 50 */
int buscar(char[][chars], int, char[chars]);
        /* vCodigoDominio, cam && cod */

void mostrarA(int[], int[], int);
void ordenar(int[], int [], int);
          /* vNumero, vImporteRecaudadoXConductor && con */

void mostrarB(char[][chars], int[], int);
           /* vCodigoDominio, vKMXCamion && cam */

void mostrarC(char[][chars], int[], int);
           /* vCodigoDominio, vTonXCamion && cam */

int validarImporte(int);
int validarKMs(int);
int validarTons(int);

int main(){
  char vCodigoDominio[cam][chars];
  char vNombres[con][chars2];

  int vImporteXKM[cam];
  int vImporteRecaudadoXConductor[con];
  int vKMXCamion[cam];
  int vTonXCamion[cam];
  int vNumero[con];

  //int cantidad;

  inicializar(vCodigoDominio, vNombres, vImporteXKM, vImporteRecaudadoXConductor, vKMXCamion, vTonXCamion, vNumero, cam, con);

  planillaCamion(vCodigoDominio, vImporteXKM, cam);

  viajesXConductor(vImporteRecaudadoXConductor, vNombres, vCodigoDominio, vImporteXKM, vKMXCamion, vTonXCamion, vNumero, cam, con);
  //printf("\n%d\n", cantidad);

  printf("\nPunto a)\n");
  ordenar(vNumero, vImporteRecaudadoXConductor, con);
  mostrarA(vNumero, vImporteRecaudadoXConductor, con);
  printf("\n\n");

  printf("\nPunto b)\n");
  mostrarB(vCodigoDominio, vKMXCamion, cam);
  printf("\n\n");

  printf("\nPunto c)\n");
  mostrarC(vCodigoDominio, vTonXCamion, cam);
  printf("\n\n");

  return 0;
}

void inicializar(char vCodDom[][chars], char vNombres[][chars2], int vImpXKM[], int vImpRXCon[], int vKMXCam[], int vTonXCam[], int vNro[], int cCam, int cCon){
  int i;

  for(i = 0 ; i <= cCam ; i++){
    strcpy(vCodDom[i], "Nada");
    vImpXKM[i] = 0;
    vKMXCam[i] = 0;
    vTonXCam[i] = 0;
  }

  for(i = 0 ; i <= cCon ; i++){
    strcpy(vNombres[i], "Nada");
    vImpRXCon[i] = 0;
    vNro[i] = 0;
  }
}

void planillaCamion(char vCodDom[][chars], int vImpXKM[], int cCam){
  int i, imp;
  char cod[chars];

  i = 0;

  printf("Codigo de Dominio del camion: ");
  fflush(stdin);
  gets(cod);

  while(strcmpi(cod, "Nada") != 0 && i < cCam){

    imp = validarImporte(0);

    strcpy(vCodDom[i], cod);

    vImpXKM[i] = imp;

    i++;

    printf("\nCodigo de Dominio del camion: ");
    fflush(stdin);
    gets(cod);

  }
}

int validarDato(int desde, int cual){
  int dato;

  if(cual == 0){
    printf("\nImporte por KM: ");
    scanf("%d", &dato);

    while(dato <= desde){
      printf("\nImporte por KM: ");
      scanf("%d", &dato);
    }
  }else if(cual == 1){
    printf("\nCantidad de KM: ");
    scanf("%d", &dato);

    while(dato <= desde){
      printf("\nCantidad de KM: ");
      scanf("%d", &dato);
    }
  }else if(cual == 2){
    printf("Cantidad de Toneladas tranportadas: ");
    scanf("%d", &dato);

    while(dato <= desde){
      printf("Cantidad de Toneladas tranportadas: ");
      scanf("%d", &dato);
    }
  }

  return dato;
}

void viajesXConductor(int vImpRXCon[], char vNombres[][chars2], char vCodDom[][chars], int vImpXKM[], int vKMXCam[], int vTonXCam[], int vNro[], int cCam, int cCon){
  //int cantConductores = 0;
  int nro, pos, cantKM, valor, resultado, tons;
  char nombre[chars2];
  char cod[chars];

  nro = valNumero(1, 50);

  while(nro != 100){
    printf("\nNombre: ");
    fflush(stdin);
    gets(nombre);

    vNro[nro - 1] = nro;

    strcpy(vNombres[nro - 1], nombre);

    printf("\nCodigo de Dominio del camion: ");
    fflush(stdin);
    gets(cod);

    pos = buscar(vCodDom, cCam, cod);

    cantKM = validarKMs(0);

    resultado = vImpXKM[pos] * cantKM;
    vImpRXCon[nro - 1] = resultado;

    vKMXCam[pos] = cantKM;

    tons = validarTons(0);

    vTonXCam[pos] = tons;

    //cantConductores++;

    nro = valNumero(1, 50);
  }

  //return cantConductores;
}
int valNumero(int desde, int hasta){
  int nro;

  printf("\nNro. Conductor: ");
  scanf("%d", &nro);

  if(nro != 100){
    while(nro < desde && nro > hasta){
      printf("\nNro. Conductor: ");
      scanf("%d", &nro);
    }
  }

  return nro;
}
int buscar(char vCodDom[][chars], int cCam, char cod[chars]){
  int i, pos;

  i = 0;
  pos = -1;

  while(pos == -1 && i < cCam){
    if(strcmpi(vCodDom[i], cod) == 0){
      pos = i;
    }else{
      i++;
    }
  }
  return pos;
}

void ordenar(int vNro[], int vImpRXCon[], int cCon){
  int i, j, cambio;
  int auxNro;
  int auxImp;

  i = 1;

  do{
    cambio = 0;

    for(j = 0 ; j < cCon - i ; j++){
      if(vImpRXCon[j] < vImpRXCon[j + 1]){
        auxImp = vImpRXCon[j];
        vImpRXCon[j] = vImpRXCon[j + 1];
        vImpRXCon[j + 1] = auxImp;

        auxNro = vNro[j];
        vNro[j] = vNro[j + 1];
        vNro[j + 1] = auxNro;

        cambio = 1;
      }
    }

    i++;
  }while(cambio == 1 && i < cCon);
}
void mostrarA(int vNro[], int vImpRXCon[], int cCon){
  int i;

  printf("\nNro. Conductor\t Importe Recaudado\n");

  for(i = 0 ; i < cCon ; i++){
    printf("\t%d\t\t %d\n", vNro[i], vImpRXCon[i]);
  }
}

void mostrarB(char vCodDom[][chars], int vKMXCam[], int cCam){
  int i, m;

  m = vKMXCam[0];

  printf("\nCod. Camion\t Cant. KM\n");

  for(i = 0 ; i < cCam ; i++){
    if(vKMXCam[i] > m){
      m = vKMXCam[i];
    }
  }
  for(i = 0 ; i < cCam ; i++){
    if(vKMXCam[i] == m && vKMXCam[i] != 0){
      printf("%s\t\t %d\n", vCodDom[i], vKMXCam[i]);
    }
  }
  // printf("No hay ningun camion con mayor cantidad de KMs.\n");
}

void mostrarC(char vCodDom[][chars], int vTonXCam[], int cCam){
  int i;

  printf("\nCod. Camion\t Toneladas tranportadas\n");

  for(i = 0 ; i < cCam ; i++){
    printf("%s\t\t %d\n", vCodDom[i], vTonXCam[i]);
  }
}

int validarImporte(int desde){
  int imp;

  printf("\nImporte por KM: ");
  scanf("%d", &imp);

  while(imp <= desde){
    printf("\nImporte por KM: ");
    scanf("%d", &imp);
  }
  return imp;
}

int validarKMs(int desde){
  int km;

  printf("\nCantidad de KMs: ");
  scanf("%d", &km);

  while(km <= desde){
    printf("\nCantidad de KMs: ");
    scanf("%d", &km);
  }
  return km;
}

int validarTons(int desde){
  int tons;

  printf("\nCantidad de toneladas: ");
  scanf("%d", &tons);

  while(tons <= desde){
    printf("\nCantidad de toneladas: ");
    scanf("%d", &tons);
  }
  return tons;
}
