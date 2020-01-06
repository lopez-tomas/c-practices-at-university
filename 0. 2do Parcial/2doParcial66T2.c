#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIA 8
#define SEC 5

typedef struct{
    int codS;
    float costoLoc;
}T_Sectores;

typedef struct{
    char nombre[32];
    int diaRecital; // 1 al 8
    int sector;
    int cantLocalidades;
}T_Ventas;

typedef struct{
    int codS;
    int cantLocalidadesVendidas;
}T_TotalSectores;

int main(){
    T_Sectores vSectores[SEC];
    int mPersonasXDia[SEC][DIA];


    return 0;
}

void cargarVector(T_Sectores v[], int ce){
    FILE *pf;
    T_Sectores aux;
    int i=0;

    pf=fopen("Sectores.dat", "rb");
    if(pf==NULL){
        printf("ERROR");
        exit(1);
    }
    fread(&aux, sizeof(T_Sectores),1,pf);
    while(!feof(pf) && i<ce){
        v[i]=aux;
        i++;
        fread(&aux, sizeof(T_Sectores),1,pf);
    }
    fclose(pf);
}

void inicializarM(int m[][DIA], int cf, int cc){
    int f,c;

    for(f=0;f<cf;f++){
        for(c=0;c<cc;c++){
            m[f][c]=0;
        }
    }
}

void ventas(T_Sectores v[], int ce){
    FILE *ventas, *totalSec;
    T_Ventas venta;
    T_TotalSectores sec;
    char nombre[32];

    ventas=fopen("VentaLocalidades.dat","rb");
    if(ventas==NULL){
        printf("ERROR");
        exit(2);
    }
    totalSec=fopen("TotalSectores.dat","wb");
    if(totalSec==NULL){
        printf("ERROR");
        fclose(ventas);
        exit(3);
    }

    fread(&venta, sizeof(T_Ventas),1,ventas);
    while(!feof(ventas)){
        strcpy(nombre, venta.nombre);

    }
}
