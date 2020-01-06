#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MED 150
#define ESP 25
#define DIA 31

typedef struct{
    int nroMatricula;
    char apeNom[36];
    int codEspecialidad;
}T_Medicos;

typedef struct{
    int codEspecialidad;
    float importe;
}T_Especialidades;

typedef struct{
    int nroHistoria;
    int nroMatricula;
    int dia;
}T_Consultas;

typedef struct{
    int nroMatricula;
    char apeNom[36];
    int cantRealizados;
}T_Informes;

int cargarVector(T_Medicos[],int);
void cargarVector2(T_Especialidades,int);

void generarArchivo();

int main(){
    T_Medicos vMedicos[MAX];
    T_Especialidades vEspecialidades[ESP];
    int cantMedicos, mConsultasXDiaXEspecialidad[ESP][DIA];

    cantMedicos = cargarVector(vMedicos, MAX);
    cargarVector2(vEspecialidades, ESP);
    inicializaMatriz(mConsultasXDiaXEspecialidad, ESP, DIA);

    generarArchivo(vMedicos, vEspecialidades, mConsultasXDiaXEspecialidad, MED, ESP, DIA);

    return 0;
}

int cargarVector(T_Medicos v[], int ce){
    FILE *pf;
    T_Medicos aux;
    int i=0;

    pf=fopen("Medicos.dat","rb");
    if(pf==NULL){
        printf("ERROR");
        exit(1);
    }
    fread(&aux, sizeof(T_Medicos),1,pf);
    while(!feof(pf) && i<ce){
        v[i] = aux;
        i++;
        fread(&aux, sizeof(T_Medicos),1,pf);
    }
    fclose(pf);
    return i;
}

void cargarVector2(T_Especialidades v[], int ce){
    FILE *pf;
    T_Especialidades aux;
    int i=0;

    pf=fopen("Especialidades.dat","rb");
    if(pf==NULL){
        printf("ERROR");
        exit(2);
    }
    fread(&aux, sizeof(T_Especialidades),1,pf);
    while(!feof(pf) && i<ce){
        v[i]=aux;
        i++;
        fread(&aux, sizeof(T_Especialidades),1,pf);
    }
}

void inicializaMatriz(int m[][DIA], int cf, int cc){
    int f, c;
    for(f=0;f<cf;f++){
        for(c=0;c<cc;c++){
            m[f][c]=0;
        }
    }
}

void generarArchivo(T_Medicos vM[], T_Especialidades vE[], int mCXDXE[][DIA], int cMed, int cEsp, cDias){
    FILE *consultas, *informes;
    T_Consultas consulta;
    T_Informes informe;
    int nroAnt, i=0;

    consultas = fopen("Consultas.dat","rb");
    if(consulta==NULL){
        printf("ERROR");
        exit(3);
    }
    informes = fopen("InfMedicos.dat","wb");
    if(informe==NULL){
        printf("ERROR");
        fclose(consultas);
        exit(4);
    }
    fread(&consulta, sizeof(T_Consultas),1,consultas);
    while(!feof(consultas)){
        nroAnt = consulta.nroHistoria;

        while(!feof(consultas) && nroAnt == consulta.nroHistoria){

            pos = buscar(vM, ce, consulta.nroMatricula);
            if(pos != -1){
                informe.nroMatricula = consulta.nroMatricula;
                strcpy(informe.apeNom, vM[pos].apeNom);
                informe.cantRealizados++;
                fwrite(&informe, sizeof(T_Informes),1,informes); // Punto 1


            }else{

            }
            fread(&consulta, sizeof(T_Consultas),1,consultas);
        }
    }
    fclose(consultas);
    fclose(informes);
}
