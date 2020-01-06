#include <stdio.h>
#include <stdlib.h>

#define MAX 20000

struct Saldos{
    int nroCaja;
    char nomApe[31];
    float saldo;
};

struct Movimientos{
    int sucursal;
    int nroCuenta;
    int mes;
    int dia;
    int codOp;
    float importe;
};

int main(){
    struct Saldos vSaldos[MAX];
    int vExtrac[MAX];
    int cantCuentas;

    cantCuentas = llenarVector(vSaldos, MAX);

    inicializar(vExtrac, cantCuentas);
    procesarMovimientos(vSaldos, cantCuentas, vExtrac); // Punto b)

    actualizarArchivo(vSaldos, cant); // Punto a)

    extracciones(vSaldos, vExtrac, cant); // Punto c)

    return 0;
}

int llenarVector(struct Saldos v[], int ce){
    int i = 0;
    struct Saldos sal;

    FILE *aSal = fopen("ARCH_SALDOS", "rb");
    if(aSal == NULL){
        printf("ERROR");
        exit(1);
    }else{
        fread(&sal, sizeof(struct Saldos), 1, aSal);
        while(!feof()){

            v[i] = sal;
            i++;

            fread(&sal, sizeof(struct Saldos), 1, aSal);
        }
    }

    return i;
}

void inicializar(int vE[], int ce){
    int i;

    for(i = 0 ; i < ce ; i++){
        vE[i] = 0;
    }
}

void actualizarArchivo(struct Saldos v[], int ce){

}

void procesarMovimientos(struct vS[], int ce, int vE[]){
    struct Movimientos movi;
    int pos, sucA;
    float impTotal;

    FILE *aMovi = fopen("ARCH_MOVI", "rb");
    if(aMovi == NULL){
        printf("ERROR");
        exit(2);
    }else{
        FILE *aSinSaldo = fopen("ARCH_SIN_SALDO", "wb");
        if(aSinSaldo == NULL){
            printf("ERROR");
            fclose(aMovi);
            exit(3);
        }else{
            fread(&movi sizeof(struct Movimientos), 1, aMovi);
            while(!feof(aMovi) && i < ce){
                sucA = movi.sucursal;
                impTotal = 0;

                do{
                    pos = buscar(vS, ce, movi.nroCuenta);
                    if(pos != -1){
                        if(movi.codOp == 1){
                            vS[pos].saldo += movi.importe;
                            impTotal += movi.importe;
                        }else if(movi.codOp == 2){
                            if(vS[pos].saldo >= movi.importe){
                                vS[pos].saldo -= movi.importe;
                                vE[pos]++;
                            }else{
                                fwrite(&movi, sizeof(struct Movimientos), 1, aSinSaldo);
                            }
                        }
                    }
                    fread(&movi sizeof(struct Movimientos), 1, aMovi);
                }while(!feof(aMovi) && sucA == movi.sucursal);

                printf("%d      %f", sucA, impTotal); // Punto b)
            }
            fclose(aMovi);
            fclose(aSinSaldo);
        }
    }
}
