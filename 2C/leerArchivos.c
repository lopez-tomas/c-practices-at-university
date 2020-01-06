#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nroCaja; // 6 cifras
    char apeNom[31];
    float saldo; //>=0
}T_Saldos;

typedef struct{
    int sucursal; // 4 cifras no correlativo
    int nroCaja;
    int mes;
    int dia;
    int codOp; // 1: deposito (suma al saldo) - 2: extraccion (resta al saldo)
    float importe; // >0
}T_Movimientos;

void leerSaldo();
void leerMovi();

int main(){

    leerSaldo();
    printf("\n\n\n");
    leerMovi();

    return 0;
}

void leerMovi(){
    T_Movimientos movi;

    FILE *pf;

    pf=fopen("ARCH_MOVI.dat","rb");
    if(pf==NULL){
        printf("No se pudo abrir el archivo.");
        exit(5);
    }
    printf("# DATOS DEL ARCHIVO MOVIMIENTOS #\n\n");
    printf("Sucursal\tNro.Caja\tMes\tDia\tCod.OP\tImporte");

    fread(&movi, sizeof(T_Movimientos),1,pf);
    while(!feof(pf)){
        printf("\n%d\t\t%d\t\t%d\t%d\t%d\t%.2f", movi.sucursal, movi.nroCaja, movi.mes, movi.dia, movi.codOp, movi.importe);
        fread(&movi, sizeof(T_Movimientos),1,pf);
    }
}

void leerSaldo(){
    T_Saldos saldo;

    FILE *aSal;

    aSal=fopen("ARCH_SALDOS.dat","rb");
    if(aSal==NULL){
        printf("No se pudo abrir el archivo.");
        exit(5);
    }
    printf("# DATOS DEL ARCHIVO SALDOS #\n\n");
    printf("Nro.Caja\tNombre completo\t\tSaldo");

    fread(&saldo, sizeof(T_Saldos),1,aSal);
    while(!feof(aSal)){
        printf("\n%d\t\t%s\t\t%.2f",saldo.nroCaja,saldo.apeNom,saldo.saldo);
        fread(&saldo, sizeof(T_Saldos),1,aSal);
    }
}
