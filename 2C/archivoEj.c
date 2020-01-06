#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CANT 20000

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

void leerArchivo();
int cargaVector(T_Saldos[], int);
int buscar(T_Saldos[], int, int);
void Movimientos(T_Saldos[], int[], int);
void ActualizarSaldos(T_Saldos[], int);
void ListadoCuentas(T_Saldos[], int[], int, int);

// EJERCICIO 21 DE ARCHIVOS
int main(){
    int cantCuentas, vExtracciones[CANT]={0};
    T_Saldos vSaldos[CANT];

    cantCuentas = cargaVector(vSaldos, CANT);

    Movimientos(vSaldos, vExtracciones, cantCuentas);

    ActualizarSaldos(vSaldos, cantCuentas);

    printf("\n\nCuentas que realizaron mas de 5 extracciones:\n");
    ListadoCuentas(vSaldos, vExtracciones, CANT, 5);

    return 0;
}

int cargaVector(T_Saldos v[], int ce){
    int i=0;
    FILE *pf;
    T_Saldos Saldo;

    pf=fopen("ARCH_SALDOS.dat","rb");
    if(pf==NULL){
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    fread(&Saldo, sizeof(T_Saldos),1,pf);
    while(!feof(pf) && i<ce){
        v[i] = Saldo;
        //v[i].nroCaja=Saldo.nroCaja;
        //v[i].apeNom=Saldo.apeNom;
        //v[i].saldo=Saldo.saldo;
        i++;

        fread(&Saldo, sizeof(T_Saldos),1,pf);
    }
    fclose(pf);

    return i;
}

void Movimientos(T_Saldos v[], int vE[], int ce){
    FILE *aMovi, *aSinSaldo;
    T_Saldos Saldo;
    T_Movimientos Movi, SinSaldo;
    int pos, sucant;
    float sum_suc;

    aMovi=fopen("ARCH_MOVI.dat","rb");
    if(aMovi==NULL){
        printf("No se pudo abrir el archivo");
        exit(2);
    }
    aSinSaldo=fopen("SIN_SALDO","wb");
    if(aSinSaldo==NULL){
        printf("No se pudo crear el archivo");
        fclose(aMovi);
        exit(3);
    }

    fread(&Movi, sizeof(T_Movimientos),1,aMovi);
    while(!feof(aMovi)){
            sucant=Movi.sucursal;
            sum_suc=0;
            while(sucant==Movi.sucursal && !feof(aMovi)){
                pos=buscar(v, ce, Movi.nroCaja);
                if(pos!=-1){
                    if(Movi.codOp==1){
                        v[pos].saldo+=Movi.importe;
                        sum_suc+=Movi.importe;
                    }else{
                        if(v[pos].saldo > Movi.importe){
                            v[pos].saldo-=Movi.importe;
                            vE[pos]++;
                        }else{
                            fwrite(&SinSaldo, sizeof(T_Movimientos),1,aSinSaldo);
                            printf("Movimiento de la caja de ahorro %d\n"
                                   "Rechazado por saldo insuficiente", Movi.sucursal);
                        }
                    }
                }
                fread(&Movi, sizeof(T_Movimientos),1,aMovi);
        }
        printf("\nTotal de deposito en sucursal %d: %.2f\n\n", sucant, sum_suc);
    }
    fclose(aMovi);
    fclose(aSinSaldo);
}

int buscar(T_Saldos v[], int ce, int b){
    int pos=-1, i=0;

    while(pos==-1 && i<ce){
        if(v[i].nroCaja==b)
            pos=i;
        else
            i++;
    }
    return pos;
}

void ActualizarSaldos(T_Saldos v[], int ce){
    FILE *pf;
    int i;

    pf=fopen("ARCH_SALDO.dat","wb");
    if(pf==NULL){
        printf("No se pudo abrir el archivo");
        exit(4);
    }

    for(i=0;i<ce;i++){
        fwrite(&v[i], sizeof(T_Saldos),1,pf);
    }
    fclose(pf);
}

void ListadoCuentas(T_Saldos v[], int vE[], int ce, int cant){
    int i;
    printf("Nro.Caja\tApellido y Nombre\tSaldo");

    for(i=0;i<ce;i++){
        if(vE[i]>cant)
            printf("%d\t%s\t%.2f\n", v[i].nroCaja, v[i].apeNom, v[i].saldo);
    }
}
