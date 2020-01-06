#include <stdio.h>
#include <stdlib.h>
#define max 60

float tiemposAutos(int);
void ordenar(float[], int[], int);
float promedio(float[], int);
int supProm(float[], int, float);
void sinParticipar(float[], int[], int);

int main(){
    float vTiempos[max] = {0}, tiempo, prom;
    int vAutos[max] = {0}, i=0, cant=0, j;

    tiempo = tiemposAutos(i);

    while(tiempo >= 0){
        vTiempos[i]=tiempo;
        vAutos[i]=i+1;

        i++;

        tiempo = tiemposAutos(i);
    }

    ordenar(vTiempos, vAutos, i);
    printf("\n");
    for(j=0;j<i;j++)
        printf("%d\t%.2f\n", vAutos[j], vTiempos[j]);

    // Punto A:
    printf("\n\nPunto A:\n");
    printf("Auto con mejor tiempo de clasificación: %d\n", vAutos[0]);
    printf("Tiempo: %.2f", vTiempos[0]);

    // Punto B:
    printf("\n\nPunto B:\n");
    printf("Auto con el peor tiempo de clasificación: %d\n", vAutos[i-1]);
    printf("Tiempo: %.2f", vTiempos[i-1]);

    // Punto C:
    printf("\n\nPunto C:\n");
    prom = promedio(vTiempos, i);
    printf("Promedio del tiempo: %.2f\n", prom);

    cant = supProm(vTiempos, i, prom);
    if(cant == 0)
        printf("\nNingún auto superó el promedio");
    else
        printf("\nCantidad de autos que superaron el promedio de tiempo: %d", cant);

    // Punto D:
    sinParticipar(vTiempos, vAutos, max);

    return 0;
}

float tiemposAutos(int n){
    float t;

    printf("Tiempo de clasificación %d: ", n+1);
    scanf("%f", &t);

    return t;
}

void ordenar(float vT[], int vA[], int ce){
    int i=0, j, aux2, cambio;
    float aux;

    do{
        cambio=0;

        for(j=0 ; j<ce-i ; j++){
            if(vT[j-1] > vT[j]){
                aux = vT[j-1];
                vT[j-1] = vT[j];
                vT[j] = aux;

                aux2 = vA[j-1];
                vA[j-1] = vA[j];
                vA[j] = aux2;

                cambio=1;
            }
        }
        i++;
    }while(cambio);
}

float promedio(float vT[], int ce){
    float p;
    int sum=0, i;

    for(i=0 ; i<ce ; i++)
        sum+=vT[i];

    if(ce != 0)
        p=(float)sum/ce;

    return p;
}

int supProm(float vT[], int ce, float p){
    int cant=0, i;

    for(i=0 ; i<ce ; i++){
        if(vT[i]<p)
            cant++;
    }

    return cant;
}

void sinParticipar(float vT[], int vA[], int ce){
    int b=0, i;

    printf("\n\nPunto D:\n");
    printf("Autos que no participaron de la carrera:\n");

    for(i=0 ; i<ce ; i++){
        if(vT[i]==0){
            printf("%d\n", i+1);
            b=1;
        }
    }

    if(b != 1)
        printf("Todos los autos participaron");
}
