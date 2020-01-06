#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tam 25
#define tamC 6

#define chars 26

void inicializar(char[][chars], int[], int[], int[], int, int);

int cargaDest(char[][chars], int);

float reservas(char[][chars], int[], int[], int[], int);
int ingSem(int, int);
int buscar(char[][chars], char[chars], int);
int ingCategoria(int, int);
int ingPers(int, int);

//void mostrarVectorChar(char[][chars], int);

void cantPersXDest (char[][chars], int[], int);


void catHotelwMenorCantPers(int[], int);
void ordenar(int[], int);

void cantResXDest(char[][chars], char[chars], int[], int, int);

void mostrarVector(char[][chars], int[], int);
void ordenar2(char[][chars], int[], int);


int main(){

    // vDest, vPersDest & vCantResPorDest son VECTORES PARALELOS
    char vDest[tam][chars];
    int vPersDest[tam];
    int vCat[tamC];
    int vCantResPorDest[tam];

    int cant;
    float cantPers;
    int res;

    inicializar(vDest, vPersDest, vCat, vCantResPorDest, tam, tamC);

    cant = cargaDest(vDest, tam);

    cantPers = reservas(vDest, vPersDest, vCat, vCantResPorDest, cant);

    printf("\n\nCantidad de Destinos: %d\n\n", cant);

    //mostrarVector(vPersDest, tam);

    //mostrarVectorChar(vDest, tam);

    // Informe Nro.1:
    /* Cantidad de Personas por Destino */
    cantPersXDest(vDest, vPersDest, tam);

    // Informe Nro.2:
    /* Categoria del hotel donde se hospedan la menor cant. de personas */
    printf("\n");
    catHotelwMenorCantPers(vCat, tamC);

    // Informe Nro.3:
    /* Porcentaje de Personas de 1er Semana */
    printf("\n");
    printf("\nPorcentaje de Personas de 1er Semana: %.2f\n", cantPers);

    // Informe Nro.4:
    /* Cantidad de Reservas por Destino */
    printf("\n");
    mostrarVector(vDest, vCantResPorDest, tam);


    return 0;
}

void inicializar(char vD[][chars], int vPD[], int vC[], int vCRPD[], int ce, int ce2){
    int i;

    for(i = 0 ; i <= ce ; i++){
        vD[i][chars] = 'N';
        vPD[i] = 0;
        vCRPD[i] = 0;
    }

    for(i = 0 ; i <= ce2 ; i++){
        vC[i] = 0;
    }
}

int cargaDest(char vD[][chars], int ce){

    char dest[chars];
    int i, cantDest;

    printf("Destino: ");
    gets(dest);

    i = 0;
    cantDest = 0;

    while((strcmpi(dest, "FIN") != 0) && i < ce){
        strcpy(vD[i],dest);

        i++;
        cantDest++;

        printf("Destino: ");
        gets(dest);
    }

    return cantDest;
}

float reservas(char vD[][chars], int vPD[], int vC[], int vCRPD[], int cant){
    int acumPersPrimerSem = 0;
    int sem, cat, cantPers;
    char dest[chars];
    int pos;
    int totalPers = 0;
    float porcPrimSem;

    int cantReservas;

    sem = ingSem(0, 4);

    while(sem != 0){

        cantReservas = 0;

        printf("\nDestino: ");
        scanf("%s", &dest);

        pos = buscar(vD, dest, cant);

        cat = ingCategoria(1, 5);

        cantPers = ingPers(1, 20);

        vC[cat-1] += cantPers;

        vPD[pos] = cantPers;

        if(sem == 1){
            acumPersPrimerSem += cantPers;
        }

        totalPers += cantPers;

        porcPrimSem = (float)(acumPersPrimerSem/totalPers)*100;

        cantReservas++;

        cantResXDest(vD, dest, vCRPD, cantReservas, cant);

        sem = ingSem(1, 4);
    }

    return porcPrimSem;
}

int ingSem(int desde, int hasta){
    int sem;

    printf("\nSemana: ");
    scanf("%d", &sem);

    while(sem < desde && sem > hasta){
        printf("\nSemana: ");
        scanf("%d", &sem);
    }
}

int ingPers(int desde, int hasta){
    int pers;

    printf("\nCantidad de personas: ");
    scanf("%d", &pers);

    while(pers < desde && pers > hasta){
        printf("\nCantidad de personas: ");
        scanf("%d", &pers);
    }

    return pers;
}

int ingCategoria(int desde, int hasta){
    int cat;

    printf("\nCategoria del hotel: ");
    scanf("%d", &cat);

    while(cat < desde && cat > hasta){
        printf("\nCategoria del hotel: ");
        scanf("%d", &cat);
    }
    return cat;
}

int buscar(char vD[][chars], char nombre[chars], int cant){
    int i, pos;

    i = 0;
    pos = -1;

    while(i < cant && pos == -1){
        if(strcmpi(vD[i], nombre) == 0){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}

void cantPersonasDest(int vec[], int e){
    int i;

    printf("\nPosicion\tContenido\n");

    for(i = 0 ; i < e ; i++){
        printf("%d\t \t%d\n", i, vec[i]);
    }
}

void mostrarVector(char vD[][chars], int vCRPD[], int ce){
    int i;

    printf("Destino\t  Cantidad de Reservas\n");

    for(i = 0 ; i < ce ; i++){
        //ordenar2(vD, vCRPD, ce);
        printf("%s\t %d\n", vD[i], vCRPD[i]);
    }
}

void ordenar2(char vD[][chars], int vCRPD[], int ce){
    int i, j;
    int cambio;

    int auxInt;
    char auxChar;

    i = 1;

    do{
        cambio = 0;

        for(j = 0 ; j < ce - i ; j++){
            if(vCRPD[j] < vCRPD[j+1]){

                auxInt = vCRPD[j];
                vCRPD[j] = vCRPD[j+1];
                vCRPD[j+1] = auxInt;

                strcpy(auxChar, vD[j]);
                strcpy(vD[j], vD[j+1]);
                strcpy(vD[j+1], auxChar);

                cambio = 1;
            }
        }
        j++;
    }while(cambio == 1 && i < ce);
}

// Función para Informe Nro.1:

void cantPersXDest(char vD[][chars], int vPD[], int ce){
    int i;

    printf("Destinos\t  Cantidad de Personas\n");

    for(i = 0 ; i < ce ; i++){
        printf("%s\t  %d\n", vD[i], vPD[i]);
    }
}

// Funciones para Informe Nro.2:

void catHotelwMenorCantPers(int vC[], int ce){
    int i;

    printf("Categoria de Hotel\t Cantidad de Personas\n");

    for(i = 0 ; i < ce ; i++){
        if(vC[i] != 0){
            ordenar(vC, ce);
            printf("%d\t\t  %d\n", i+1, vC[i]);
        }
    }
}

void ordenar(int vC[], int ce){
    int i, j;
    int aux, cambio;

    i = 1;

    do{
        cambio = 0;

        for(j = 0 ; j < ce - i ; j++){
            if(vC[j] < vC[j+1]){
                aux = vC[j];
                vC[j] = vC[j+1];
                vC[j+1] = aux;

                cambio = 1;
            }
        }
        j++;
    }while(cambio == 1 && i < ce);
}

void cantResXDest(char vD[][chars], char d[chars], int vCRPD[], int cR, int ce){
    int i;

    //printf("Destinos\t  Cantidad de Reservas\n");

    for(i = 0 ; i < ce ; i++){
        if(strcmpi(vD[i], d) == 0){
            vCRPD[i] = cR;
            //printf("%s\t  %d\n", vD[i], vCRPD[i]);
        }
    }
}
