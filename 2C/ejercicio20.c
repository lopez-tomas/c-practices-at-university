#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct{
    int codL; // >0, no consecutivo
    int codP; // 1 al 24
    int codZG; // 1 al 9
}T_Encomiendas;

typedef struct{
    int conL; // >0, no consecutivo
    float peso; // >0
}T_Despaches;

int main(){
    T_Encomiendas vEncomiendas[MAX];
    int cant;

    cant = cargarVector(vEncomiendas, MAX);


}

void cargaVector(T_Encomiendas v[], int ce){
    FILE *pf;
    T_Encomiendas aux;
    int i=0;

    pf = fopen("GEOGRA","rb");
    if(pf==NULL){
        printf("No se pudo abrir el archivo.");
        exit(1);
    }
    fread(&aux, sizeof(T_Encomiendas),1,pf);
    while(!feof(pf) && i<ce){
        v[i]=aux;
        i++;

        fread(&aux, sizeof(T_Encomiendas),1,pf);
    }
    fclose(pf);
}

void buscarLocalidad()


