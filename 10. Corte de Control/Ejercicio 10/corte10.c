#include <stdio.h>
#include <stdlib.h>

#define MAX 5000
#define CANT 30

struct Articulos{
  int numArt;
  int precioUni; // Mayor a 0
};

struct Vendedores{
  char nombre[31];
  int numProv; // 1 al 24
};

struct Ventas{
  char region[4];
  char nombre[31];
  int mes;
  int numArt;
  int unidadesVendidas; // Mayor a 0
};

int llenarVector(struct Articulos[], int);
int llenarVector2(struct Vendedores[], int);
void inicializar(int[], int);

void procesarVentas(struct Articulos[], struct Vendedores[], int, int, int[]);

int main(){
  struct Articulos vecA[MAX];
  struct Vendedores vecP[CANT]
  int region[CANT];
  int cantArt, cantVendedores;

  cantArt = llenarVector(vecA, MAX);
  cantVendedores = llenarVector2(vecP, CANT);

  inicializar(region, CANT);

  procesarVentas(vecA, vecP, cantArt, cantVendedores, region);

  return 0;
}

int llenarVector(struct Articulos v[], int tam){
  int i;
  struct Articulos art;

  FILE *aArt = fopen("ARTICULO", "rb");
  if(aArt == NULL){
    printf("ERROR");
    exit(1);
  }else{
    fread(&art, sizeof(struct Articulos), 1, aArt);
    while(!feof(aArt) && i < tam){

      v[i] = art;
      i++;

      fread(&art, sizeof(struct Articulos), 1, aArt);
    }
    fclose(aArt);
  }

  return i;
}

int llenarVector2(struct Vendedores v[], int tam){
  int i;
  struct Vendedores ven;

  FILE *aVen = fopen("PROVIN", "rb");
  if(aVen == NULL){
    printf("ERROR");
    exit(2);
  }else{
    fread(&ven, sizeof(struct Vendedores), 1, aVen);
    while(!feof(aVen) && i < tam){

      v[i] = ven;
      i++;

      fread(&ven, sizeof(struct Vendedores), 1, aVen);
    }
    fclose(aVen);
  }

  return i;
}

void inicializar(int vR[], int ce){
    int i;

    for(i = 0 ; i < ce ; i++){
        vR[i] = 0;
    }
}

void procesarVentas(struct Articulos v[], struct Vendedores v[], int cA, int cV, int v[]){
    struct Articulos art;
    struct Vendedores ven;

    float precio;
    int unidades;

    *FILE aArt, aVen;

    aArt = fopen("ARTICULO", "rb");
    if(aArt == NULL){
        printf("ERROR");
        exit(3);
    }else{
        aVend = fopen("PROVIN", "rb");
        if(aVend == NULL){
            printf("ERROR");
            fclose(aArt);
            exit(4);
        }else{
            fread(&art, sizeof(struct Articulos), 1, aArt);
            while(!feof(aArt) && i < cA){

            }
        }
    }
}
