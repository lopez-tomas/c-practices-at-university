#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define tam 30

void inicializar(int[], char[], int[], int);

void cargaEquipos(int[], char[], int);
int ingCod(int, int);
int ingPts(int);
char ingClase(char, char);

void mesAbril(int[], int[], int);
int ingValDia(int, int);
int ingPts2(int, int);
int ingGoels(int);
void buscarEquipo(int[], int, int, int);

void ordenarEquipos(int[], int);
void tablaPuntuacion(int[], int);

int main(){
    int vEquipos[tam];
    int vGoles[tam];
    char vClase[tam];

    inicializar(vEquipos, vClase, vGoles, tam);

    cargaEquipos(vEquipos, vClase, tam);

    mesAbril(vEquipos, vGoles, tam);

    ordenarEquipos(vEquipos, tam);

    tablaPuntuacion(vEquipos, tam);

    return 0;
}

void inicializar(int v[], char vCl[], int vG[], int ce){
    int i;

    for(i = 0 ; i <= ce ; i++){
        v[i] = 0;
        vG[i] = 0;
        vCl[i] = 'N';
    }
}

void cargaEquipos(int v[], char vCl[], int ce){
    int codigo, puntos;
    char clase;

    codigo = ingCod(0, ce);

    while(codigo != 0){
        puntos = ingPts(0);
        v[codigo - 1] = puntos;

        //clase = ingClase('F', 'M');
        //vCl[codigo - 1] = clase;

        codigo = ingCod(0, ce);
    }
}

int ingCod(int desde, int hasta){
    int cod;

    do{
        printf("Ingresar código del equipo: ");
        scanf("%d", &cod);
    }while(cod < desde && cod > hasta);

    return cod;
}

int ingPts(int desde){
    int p;

    printf("Puntos: ");
    scanf("%d", &p);

    while(p < desde){
        printf("Puntos: ");
        scanf("%d", &p);
    }

    return p;
}

char ingClase(char f, char m){
    char s;

    do{

        printf("Sexo (F | M): ");
        fflush(stdin);
        scanf("%c", s);
        s = toupper(s);

    }while(s != f && s != m);

    return s;
}

void mesAbril(int v[], int vG[], int ce){
    int dia, codigo, puntos, goles;

    dia = ingValDia(1, 30);

    while(dia != 0){

        codigo = ingCod(0, ce);
        while(codigo != 0){
            puntos = ingPts2(0, 3);
            goles = ingGoles(0);
            vG[codigo - 1] = goles;

            buscarEquipo(v, codigo, puntos, goles);

            codigo = ingCod(0, ce);
        }

        dia = ingValDia(1, 30);
    }
}

int ingValDia(int desde, int hasta){
    int d;

    do{
        printf("Dia del mes: ");
        scanf("%d", &d);
    }while(d < desde && d > hasta);

    return d;
}

int ingPts2(int desde, int hasta){
    int p;

    printf("Puntos: ");
    scanf("%d", &p);

    while(p < desde && p > hasta){
        printf("Puntos: ");
        scanf("%d", &p);
    }

    return p;
}

int ingGoles(int desde){
    int g;

    printf("Goles: ");
    scanf("%d", &g);

    while(g < desde){
        printf("Goles: ");
        scanf("%d", &g);
    }

    return g;
}

void buscarEquipo(int v[], int cod, int pts, int goles){
    if(v[cod - 1] != 0){
        v[cod - 1] += pts;
    }else{
        printf("El equipo de futbol es inexistente.\n");

        printf("\nDatos ingresados:\n");
        printf("Equipo (COD): %d", cod);
        printf("\nPuntos: %d", pts);
        printf("\nGoles: %d", goles);
    }
}

void ordenarEquipos(int v[], int ce){
    int i, j, aux, cambio;

    i = 0;

    do{
        cambio = 0;

        for(j = 0 ; j < ce - i ; j++){
            if(v[j] < v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                cambio = 1;
            }
        }
        j++;
    }while(cambio == 1 && j < ce);

}

void tablaPuntuacion(int v[], int ce){
    int i;

    printf("Posicion\t Contenido\n");

    for(i = 0 ; i < ce ; i++){
        if(v[i] != 0){
            printf("%d\t \t%d\n", i,v[i]);
        }
    }
}
