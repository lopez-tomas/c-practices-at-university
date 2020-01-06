#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50
#define tam 26
#define chars 21

void inicializar(char[][chars], int[], int[], int[], int, int, int[]);
int fletesEmpresas(char[][chars], int[], int);
int ingCodZ(int, int);
int ingCodF(int, int);

void entregasSemana(char[][chars], int[], int[], int[], int, int, int);

float ingPeso(int);

int buscar(char[][chars], int, int);

void mostrarCantEntregasXSem(int[], int);

void mostrarCodZonaMayorCargaAcum(float[], int);

void mostrarListado(char[][chars], float[], int);

void ordenar(char[][chars], float[], int);

int main(){
    char vFletes[tam][chars];

    int vCantidadEntregasXZona[tam2];

    float vCargaAcumXZona[tam2];

    float vCargaXFlete[tam], cant, vCantidadFletesXZona[tam2];

    inicializar(vFletes, vCantidadEntregasXZona, vCargaAcumXZona, vCargaXFlete, tam, tam2);

    cant = fletesEmpresa(vFletes, vCantidadFletexXZona, tam, tam2);

    entregasSemana(vFletes, vCantidadEntegasXZona, vCargaAcumXZona, vCargaXFlete, cant, tam, tam2);

    mostrarCantEntregasXSem(vCantidadEntregasXZona, tam2);

    mostrarCodZonaMayorCargaAcum(vCargaAcumXZona, tam2);

    mostrarListado(vFletes, vCargaXFlete, tam);

    return 0;
}

void inicializar(char vF[][chars], int CEXZ[], float vAX[], float CXF[], int ce, int ce2, int VFXZ[]){
    int i;

    for(i = 0 ; i <= ce ; i++){
        strcpy(vF[i],"N");
        vCXF[i] = 0;
    }
    for(i = 0 ; i <= ce2 ; i++){
        vCAXZ[i] = 0;
        vCEXZ[i] = 0;
    }
}

int fletesEmpresa(char vF[][chars], int ce){
    int codZ, codF;
    char nom[chars];
    int cantFletesTotal = 0;

    codZ= ingCodZ(1, 6);

    while(codZ != 0){
        cantFletes = 0;
        printf("Nombre: ");
        gets(nom);

        codF = ingCodF(1, 50);
        strcpy(vF[codF - 1], nom);

        cantFletesTotal++;
        codZ= ingCodZ(1, 6);
    }

    return cantFletesTotal;
}

int ingCodZ(int desde, int hasta){
    int z;

    printf("Zona: ");
    scanf("%d", &z);

    while(z < desde && z > hasta){

        printf("Zona: ");
        scanf("%d", &z);
    }
    return z;
}

int ingCodF(int dede, int hasta){
    int c;

    printf("Codigo de vehiculo: ");
    scanf("%d", &c);

    while(c < desde && c > hasta){
        printf("Codigo de vehiculo: ");
        scanf("%d", &c);
    }
}

void entregasSemana(char vF[][chars], int vCEXZ[], float vCAXZ[], float vCXF[], int ce, int tam, int tam2){
    int codF, contEntrega, pos;
    float peso;

    codF = ingCod(0, 50);

    while(codF != 0){
        contEntrega = 0;

        peso = ingPeso(0);

        pos = buscar(vF, codF, tam);

        vCEXZ[pos] += 1;

        vCAXZ[codF - 1] += peso;

        vCXF[pos] += peso;

        codF = ingCodF(0, 50);
    }
}

float ingPeso(int desde){
    float p;

    printf("Peso: ");
    scanf("%f", &p);

    while(p < desde){
        printf("Peso: ");
        scanf("%f", &p);
    }
    return p;
}

int buscar(vF[][chars], int cod, int ce){
    int i, pos;

    i = 0;
    pos = -1;

    while(i < ce && pos == -1){
        if(strcmpi(vF[i], cod) == 0){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void ordenar(char vF[][chars], float vCXF[], int ce){
    int i, j;
    char auxChar[chars];

    float auxF;

    i = 1;

    do{

    }
}
