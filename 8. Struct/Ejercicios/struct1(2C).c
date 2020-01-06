#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CANT 50
#define COD 6
#define DESC 31

typedef struct{
    char cod[COD];
    float precio;
    char descr[DESC];
    int cantV;
    float impT;
}T_MesAnterior;

typedef struct{
    char cod[COD];
    int cantP;
}T_NuevoMes;

void inicializarV(T_MesAnterior[], T_NuevoMes[], int);

void cargaProductos(T_MesAnterior[], int, int, int);

int buscarCod(T_MesAnterior[], int, char[COD]);
void ventasMes(T_NuevoMes[], T_MesAnterior[], int, int);

void actualizarVentas(T_MesAnterior[], T_NuevoMes[], int);

void listadoProductos(T_MesAnterior[], int);

int main(){
    T_MesAnterior vProductos[CANT];
    T_NuevoMes vVentas[CANT];

    inicializarV(vProductos, vVentas, CANT);
    //listadoProductos(vProductos, CANT);

    cargaProductos(vProductos, CANT, COD, DESC);

    ventasMes(vVentas, vProductos, CANT, COD);

    actualizarVentas(vProductos, vVentas, CANT);

    listadoProductos(vProductos, CANT);

    return 0;
}

void inicializarV(T_MesAnterior v[], T_NuevoMes vV[], int ce){
    int i;

    for(i=0;i<ce;i++){
        v[i].cantV=0;
        v[i].impT=0;
        v[i].precio=0;
        strcpy(v[i].cod,"NO COD");
        strcpy(v[i].descr,"SIN DESCRIPCION");

        vV[i].cantP=0;
        strcpy(vV[i].cod,"NO COD");
    }
}

void cargaProductos(T_MesAnterior v[], int ce, int cLC, int cLD){
    char c[cLC], d[cLD];
    float p, impT;
    int i=0, cant;

    printf("Ingreso de los datos de los productos\n\n");
    printf("Descripción del producto: ");
    fflush(stdin);
    gets(d);
    toupper(d);

    while(strcmpi(d,"FIN")!=0 && i<ce){
        strcpy(v[i].descr, d);

        printf("\nCódigo del producto: ");
        fflush(stdin);
        gets(c);
        toupper(c);
        strcpy(v[i].cod, c);

        printf("\nPrecio del producto: ");
        scanf("%f", &p);
        v[i].precio = p;

        printf("\nCant. de Unidades vendidas: ");
        scanf("%d", &cant);
        v[i].cantV = cant;

        v[i].impT = p * cant;
        i++;

        system("cls");

        printf("\nDescripción del producto: ");
        fflush(stdin);
        gets(d);
        toupper(d);
    }
}

void ventasMes(T_NuevoMes vV[], T_MesAnterior vP[], int ce, int cLC){
    int cant, i=0, pos;
    char cod[cLC];

    system("cls");
    printf("Ventas del mes\n\n");
    printf("Cantidad pedida: ");
    scanf("%d", &cant);

    while(cant !=0 && i<ce){
        printf("\nCódigo del producto: ");
        fflush(stdin);
        gets(cod);
        toupper(cod);

        pos=buscarCod(vP, ce, cod);
        if(pos != -1){
            strcpy(vV[i].cod, cod);
            vV[i].cantP = cant;
        }
        i++;
        system("cls");

        printf("Cantidad pedida: ");
        scanf("%d", &cant);
    }
}

int buscarCod(T_MesAnterior v[], int ce, char cod[]){
    int pos=-1, i=0;

    while(pos==-1 && i<ce){
        if(strcmpi(v[i].cod,cod)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}

void actualizarVentas(T_MesAnterior vP[], T_NuevoMes vV[], int ce){
    int i, suma;

    for(i=0;i<ce;i++){
        vP[i].cantV+= vV[i].cantP;
        suma == vP[i].precio * vV[i].cantP;
        vP[i].impT+=suma;
    }
}

void listadoProductos(T_MesAnterior vP[], int ce){
    int i;
    system("cls");

    printf("Descripción\tCant.Vendida(unidades)\tImporte Total vendido\n");

    for(i=0;i<ce;i++){
        if(strcmpi(vP[i].descr, "SIN DESCRIPCION")!=0)
            printf("%s\t\t %d\t\t\t%.2f\n", vP[i].descr, vP[i].cantV, vP[i].impT);
    }
}
