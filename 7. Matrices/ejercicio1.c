#include <stdio.h>
#include <stdlib.h>

#define f 5
#define c 12

void inicializar(int[][c], int[], int[], int, int);
void carga(int[][c], int[], int[], int, int);

void mostrarA(int[][c], int, int);
void mostrarBC(int[], int);
void mostrarD(int[], int);
void mostrarE(int[][c], int, int);

int main(){
    int vSuper[f][c];
    int vF[f];
    int vC[c];

    inicializar(vSuper, vF, vC, f, c);

    carga(vSuper, vF, vC, f, c);

    mostrarA(vSuper, f, c);
    mostrarBC(vF, f);
    mostrarBC(vC, c);
    mostrarD(vC, c);
    mostrarE(vSuper, f, c);

    return 0;
}

void inicializar(int vS[][c], int vF[], vC[], int tamF, int tamC){
    int f, c;

    for(f = 0 ; f < tamF ; f++){
            vF[f] = 0;
        for(c = 0 ; c < tamC ; c++){
            vS[f][c] = 0;
            vC[c] = 0;
        }
    }
}


