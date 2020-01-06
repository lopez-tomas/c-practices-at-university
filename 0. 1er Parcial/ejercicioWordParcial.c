#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define tam 10
#define chars 20

void inicializar(char[][chars], char[], float[], int);
void combos(char[][chars], float[], int);

float ingPrecio(int);

void listaCombos(char[][chars], char[], float[], int);

int main(){
    char vCombos[tam][chars];
    char vTam[tam];

    float vPrecios[tam];

    inicializar(vCombos, vTam, vPrecios, tam);

    combos(vCombos, vPrecios, tam);

    listaCombos(vCombos, vTam, vPrecios, tam);

    return 0;
}

void inicializar(char vC[][chars], char vT[], float vP[], int ce){
    int i;

    for(i = 0 ; i < ce ; i++){
        vC[i][chars] = 'NC';
        vT[i] = 'F';
        vP[i] = 0;
    }
}

void combos(char vC[][chars], float vP[], int ce){
    int i;
    char combo[chars];
    float precio;

    i = 0;

    printf("Combo: ");
    gets(combo);

    while(strcmpi(combo,'FIN') != 0 && i < ce){
        strcpy(vC[i][chars], combo);
        vP[i] = ingPrecio(0);

        i++;

        printf("Combo: ");
        gets(combo);
    }
}

float ingPrecio(int desde){
    float p;

    printf("Precio del combo: ");
    scanf("%f", &p);

    while(p < desde){
        printf("Precio del combo: ");
        scanf("%f", &p);
    }

    return p;
}

void listaCombos(char vC[][chars], char vT[], float vP[], int ce){
    int i;

    printf("Combo\t Precio\n");

    for(i = 0 ; i < ce ; i++){

        printf("%c\t %.2f\n", vC[i], vP[i]);
    }
}

    float p;

    printf("Precio del combo: ");
    scanf("%f", &p);

    while(p < desde){
        printf("Precio del combo: ");
        scanf("%f", &p);
    }

    return p;
}
