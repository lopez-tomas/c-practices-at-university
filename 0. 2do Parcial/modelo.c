#include <stdio.h>
#include <stdlib.h>

#define MAX 300
#define DIA 30

struct Aplicaciones{ // Registro por aplicacion, sin orden
    int cod;
    char nomApp[19];
    float kb;
};

struct Descargas{ // Ordenado alfabeticamente por nombre de usuario
    int cod;
    int dia;
    char nomUser[26];
    float kbDescargados;
};

struct Usuarios{
    char nomUser[26];
    int cantDescCompl;
};

int llenarVector(struct Aplicaciones[], int);

void usuarios(struct Aplicaciones[], int);

int buscar(struct Aplicaciones[], int , int);

void puntoDos(int[][DIA], int, int, struct Aplicaciones[]);
int puntoTres(int[][DIA], int, int);
void puntoCuatro(int[][DIA], int, int){

int main(){
    struct Aplicaciones vApps[MAX];
    int vDesc[MAX][DIA];
    int cantApps, cantNoDesc;

    cantApps = llenarVector(vApps, MAX);

    inicializaMatriz(vDesc, cantApps, DIA);

    usuarios(vApps, cantApps, vDesc, DIA);

    //puntoDos(vDesc, cantApps, DIA, vApps);

    cantNoDesc = puntoTres(vDesc, cantApps, DIA);
    printf("Cantidad de aplicaciones sin descargas: %d\n", cantNoDesc);

    puntoCuatro(vDesc, cantApps, DIA);

    return 0;
}

int llenarVector(struct Aplicaciones vA[], int cf, int cc){
    int i = 0;
    struct Aplicaciones app;

    FILE *aApp = fopen("Aplicaciones.dat", "rb");
    if(aApp == NULL){
        printf("ERROR");
        exit(1);
    }else{
        fread(&app, sizeof(struct Aplicaciones), 1, aApp);
        while(!feof(aApp) && i < ce){

            vA[app.cod] = app.kb;
            i++;

            fread(&app, sizeof(struct Aplicaciones), 1, aApp);
        }
        fclose(aApp);
    }

    return i;
}

void inicializaMatriz(int vD[][DIA], int cf, int cc){
    int f, c;

    for(f = 0 ; f < cf ; f++){
        for(c = 0 ; c < cc ; c++){
            vD[f][c] = 0;
        }
    }
}

void usuarios(struct Aplicaciones vA[], int ce, int vD[][DIA], int cc){
    struct Descargas desc;
    struct Usuarios user;

    char nom[26];
    int totalDesc, totalNoDesc, codA, pos;

    FILE *aDesc, *aUser;

    aApp = fopen("Aplicaciones.dat", "rb");
    if(aApp == NULL){
        printf("ERROR");
        exit(2);
    }else{
        aDesc = fopen("Descargas.dat", "rb");
        if(aDesc == NULL){
            printf("ERROR");
            fclose(aApp);
            exit(3);
        }else{
            aUser = fopen("Usuarios.dat", "wb");
            if(aUser == NULL){
                printf("ERROR");
                fclose(aApp);
                fclose(aDesc);
                exit(4);
            }else{
                fread(&desc, sizeof(struct Descargas), 1, aDesc);
                while(!feof(aDesc){

                    codA = desc.cod;
                    strcpy(nom, desc.nomUser);
                    totalDesc = 0;
                    totalNoDesc = 0;

                    do{
                        pos = buscar(vA, ce, desc.kbDescargados);
                        if(pos != -1){
                            if(vA[pos] == desc.kbDescargados){
                                totalDesc++;
                                vD[pos][desc.dia - 1]++; // 2)
                            }
                        }

                        fread(&desc, sizeof(struct Descargas), 1, aDesc);
                    }while(!feof(aDesc) && strcmpi(nom, desc.nomUser) == 0);

                    strcpy(user.nomUser, nom);
                    user.cantDescCompl = totalDesc;

                    fwrite(&user, sizeof(struct Usuarios), 1, aUser); // 1)
                    }
                    fclose(aApp);
                    fclose(aDesc);
                    fclose(aUser);
                }
            }
        }
    }
}

int buscar(struct Aplicaciones vA[], int ce, int bus){
    int i = 0, pos;

    while(i < ce && vA[i].cod != bus){
        i++;
        if(i == ce){
            pos = -1;
        }else{
            pos = i;
        }
    }
    return pos;
}

void puntoDos(int vD[][DIA], int cf, int cc, struct Aplicaciones vA[]){
    int f, c;

    for(f = 0 ; f < cf ; f++){
        printf("Cod. App: %d", vA[f].cod);
        for(c = 0 ; c < cc ; c++){
           printf("Cant. Desc: %d\t Dia: %d", , vD[f][c], c+1)
        }
    }
}

int puntoTres(int vD[][DIA], int cf, int cc){
    int f, c, cont = 0;
    for(f = 0 ; f < cf ; f++){
        for(c ; 0 ; f < cc ; c++){
            if(vD[f][c] == 0){
                cont++;
            }
        }
    }



    return cont;
}

void puntoCuatro(int vD[][DIA], int cf, int cc){
    int f, c;

    for(c = 0 ; c < cc ; c++){
        for(f = 0 ; f < cf ; f++){

        }
    }
}
