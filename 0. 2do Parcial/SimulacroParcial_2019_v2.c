#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 150

typedef struct{
    int codT;
    char nombreT[51];
    int cantV;
    float precio;
}T_Tours;

typedef struct{
    int dia, mes, year;
}Fecha;

typedef struct{
    int agencia;
    int codT;
    int trimestre;
    int cantV;
    int Fecha;
}T_Ventas;

int cargarVector(T_Tours[], int);
void inicializaMatriz(float[][4], int, int);

int buscar(T_Tours[], int, int);
int actualizarVector(T_Tours[], float[][4], int, int);

void grabarArchivo(T_Tours[], int);

void puntoE(T_Tours[], float[][4], int);

int main(){
    T_Tours vTours[MAX];
    int cantTours, cantVentas;
    float mImpXTrimestres[cantTours][4];

    cantTours = cargarVector(vTours, MAX); // Punto a
    inicializaMatriz(mImpXTrimestres, cantTours, 4);

    cantVentas = actualizarVector(vTours, mImpXTrimestres, cantTours, 4); // Punto b y d

    cargarVector2()

    grabarArchivo(vTours, cantTours); // Punto c

    puntoE(vTours, mImpXTrimestres, cantTours); // Punto e

    puntoF() // Punto f

    return 0;
}

int cargarVector(T_Tours v[], int ce){ // Punto a
    int i=0;
    FILE *pf;
    T_Tours aux;

    pf = fopen("TOURS", "rb");
    if(pf==NULL){
        printf("ERROR");
        exit(1);
    }
    fread(&aux, sizeof(T_Tours),1,pf);
    while(!feof(pf) && i<ce){
        v[i] = aux;
        i++;
        fread(&aux, sizeof(T_Tours),1,pf);
    }
    fclose(pf);
    return i;
}

int cargarVector2(){
}

void inicializaMatriz(float m[][4], int cf, int cc){
    int f,c;

    for(c=0 ; c<cc ; c++){
        for(f=0 ; f<cf ; f++){
            m[f][c]=0;
        }
    }
}

int actualizarVector(T_Tours v[], float mIXT[][4], int cf, int cc){
    FILE *aVentas, *aError;
    T_Ventas aux;
    int i=0, agenciaAnt, cantV;
    float impT;

    aVentas = fopen("VENTAS", "rb");
    if(aVentas==NULL){
        printf("ERROR");
        exit(2);
    }
    aError = fopen("ERROR", "wb");
    if(aError==NULL){
        printf("ERROR");
        fclose(aVentas);
        exit(3);
    }
    fread(&aux, sizeof(T_Ventas),1,aVentas);
    while(!feof(aVentas)){
        agenciaAnt = aux.agencia;
        cantV = 0;
        impT = 0;

        while(!feof(aVentas) && agenciaAnt == aux.agencia){
            pos = buscar(v[i],cf,aux.codT);
            if(pos != -1){
                v[i].cantV+=aux.cantV; // Punto b

                cantV+=aux.cantV; // Punto d
                impT+=v[i].precio*aux.cantV; // Punto d

                mIXT[pos][aux.trimestre-1]+=(v[i].cantV * v[i].precio); // Punto e
            }else{
                fwrite(&aux, sizeof(T_Ventas),1,aError); // Punto b
            }
            i++;
        }
        // Punto d
        printf("Agencia: %d", agenciaAnt);
        printf("\nCantidad de tours vendidos: %d", cantV);
        printf("\nImporte total: %.2f\n", impT);

        fread(&aux, sizeof(T_Ventas),1,aVentas);
    }
    fclose(aVentas);
    fclose(aError);

    return i;
}

int buscar(T_Tours v[], int ce, int x){
    int pos=-1, i=0;

    while(pos==-1 && i<ce){
        if(v[i]==x)
            pos=i;
        else
            i++;
    }
    return pos;
}

void grabarArchivo(T_Tours v[], int ce){
    FILE *pf;
    T_Tours aux;
    int i;

    pf=fopen("TOURSNUEVO", "wb");
    if(pf==NULL){
        printf("ERROR");
        exit(4);
    }
    while(!feof(pf) && i<ce){
        for(i=0;i<ce;i++){
            aux = v[i];
            fwrite(&aux, sizeof(T_Tours),1,pf);
        }
    }
}

void puntoE(T_Tours v[], float m[][4], int cf){
    int f;
    float v1, v2, v3, v4, v5=0, sum1=sum2=sum3=sum4=0;

    printf("Nombre del Tour\tTrim.1\tTrim.2\tTrim.3\tTrim.4\tTotal x Tour");

    for(f=0 ; f<cf ; f++){
        printf("\n%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f", v[f].nombreT, v1=m[f][1], v2=m[f][2], v3=m[f][3], v4=m[f][4], v5=v1+v2+v3+v4);
        sum1+=m[f][1];
        sum2+=m[f][2];
        sum3+=m[f][3];
        sum4+=m[f][4];
    }
    printf("Total x Trimestre\t%.2f\t%.2f\t%.2f\t%.2f\t", sum1, sum2, sum3, sum4);
}

void puntoF(){

}
