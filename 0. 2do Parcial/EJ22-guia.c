#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{ // 24 provincias
    char codProv[4];
    char nombre[31];
}T_Provincias;

typedef struct{
    char codProv[4];
    int nacionalidad; // 1 a 50
    int cantHabit; // > 0
}T_Censos;

typedef struct{
    char codMod;
    char codProv[4];
    int nacionalidad;
    int cant; // > 0
}T_Mod_Censos;

int main(){
    T_Provincias vProv[24];
    int mHabitantes[24][50]= {{0}};
    int vHabitXProv[24]={0};

    cargarVector(vProv, 24);
    cargarMatriz(vProv, mHabitante, 24);
    modificarMatriz(vProv, mHabitantes, 24, vHabitXProv);
}

void cargarVector(T_Provincias v[], int ce){
    FILE *pf;
    T_Provincias aux;
    int i=0;

    pf = fopen("PROVINCIAS","rb");
    if(pf==NULL){
        printf("No se pudo abrir el archivo.");
        exit(1);
    }
    fread(&aux,sizeof(T_Provincias),1,pf);
    while(!feof(pf) && i<ce){
        v[i]=aux;

        i++;
        fread(&aux,sizeof(T_Provincias),1,pf);
    }
    fclose(pf);
}

void cargarMatriz(T_Provincias v[], int m[][50], int cf){
    FILE *pf;
    T_Censo aux;

    pf = fopen("CENSO","rb");
    if(pf==NULL){
        printf("No se pudo abrir el archivo.");
        exit(2);
    }
    fread(&aux, sizeof(T_Censo),1,pf);
    while(!feof(pf)){
        pos = buscar(v, cf, aux.codProv);
        if(pos != -1){
            m[pos][aux.nacionalidad - 1]= aux.cantHabit;
        }

        fread(&aux, sizeof(T_Censo),1,pf);
    }
    fclose(pf);
}

int buscar(T_Provincias v[], int ce, char x[]){
    int pos = -1, int i=0;

    while(pos==-1 && i<ce){
        if(strcmpi(v[i],x)==0)
            pos = i;
        else
            i++;

    }
    return pos;
}

void modificarMatriz(T_Provincias v[], int m[][50], int ce, int vHXP[]){
    FILE *pf;
    T_Mod_Censo aux;

    pf=fopen("MODIF_CENSO","rb");
    if(pf==NULL){
        printf("No se pudo abrir el archivo.");
        exit(3);
    }
    fread(&aux, sizeof(T_Mod_Censo),1,pf);
    while(!feof(pf) && i<ce){
        pos = buscar(v, ce, aux.codProv);
        if(pos!=-1){
            if(aux.codMod) == 'A'){
                m[pos][aux.nacionalidad - 1] += aux.cant;
            }else{
                m[pos][aux.nacionalidad - 1] = aux.cant;
            }
            vHXP[pos]+= m[pos][aux.nacionalidad - 1];
        }
        fread(&aux, sizeof(T_Mod_Censo),1,pf);
    }
    fclose(pf);
}

void grabarArchivo(T_Provincias v[], int m[][50]){
    FILE *pf;
    T_Censos aux;

    pf = fopen("CENSO","wb");
    if(pf==NULL){
        printf("No se pudo crear el archivo.");
        exit(4);
    }
    fwrite(&aux)
}
