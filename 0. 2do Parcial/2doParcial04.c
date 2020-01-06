#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define APP 300

typedef struct{
    int cod;
    char nombre[19];
    float tam;
}T_App;

typedef struct{
    int cod;
    int dia; // 1 a 31
    char nombreU[26];
    float kbDesc;
}T_Descargas;

typedef struct{
    char nombreU[26];
    int cantDescComp;
}T_Usuarios;

int cargarVector(T_App[], int);

void inicializarM(int[][31], int, int)

int buscar(T_App[], int, int);
void Usuarios(T_App[], int[][31], int)

void puntoDos(T_App[], int[][31], int, int);

int puntoTres(int[][31], int, int);

void puntoCuatro(int[][31], int, int);

int main(){
    T_App vAplicaciones[APP];
    int mDescargasCompletas[cantApps][31];
    int cantApps, cantNoDesc;

    cantApps=cargarVector(vAplicaciones, APP);

    inicializarM(mDescargasCompletas, cantApps, 31);

    Usuarios(vAplicaciones, mDescargasCompletas, cantApps);


    puntoDos(vAplicaciones, mDescargasCompletas, cantApps, 31);


    cantNoDesc = puntoTres(mDescargasCompletas, cantApps, 31);
    printf("\n\nCantidad de aplicaciones no descargas: %d", cantNoDesc);


    printf("\n\n");
    puntoCuatro(mDescargasCompletas, cantApps, 31);

    return 0;
}

int cargarVector(T_App v[], int ce){
    FILE *pf;
    T_App aux;
    int i=0;

    pf=fopen("Aplicaciones.dat");
    if(pf==NULL){
        printf("No se pudo abrir el archivo.");
        exit(1);
    }
    fread(&aux, sizeof(T_App),1,pf);
    while(!feof(pf) && i<ce){
        v[i]=aux;
        i++;
        fread(&aux, sizeof(T_App),1,pf);
    }
    fclose(pf);
    return i;
}

void inicializarM(int m[][31], int cf, int cc){
    int f, c;

    for(f=0;f<cf;f++){
        for(c=0;c<cc;c++){
            m[f][c]=0;
        }
    }
}

void Usuarios(T_App v[], int mDesc[][31], int ce){
    FILE *aDescs, *aUsers;

    T_Descargas desc;
    T_Usuarios user;

    int totalDesc;
    char nombre[26];

    aDescs=fopen("Descargas.dat","rb");
    if(aDescs==NULL){
        printf("No se pudo abrir el archivo.");
        exit(2);
    }
    aUsers=fopen("Usuarios.dat","wb");
    if(aUsers==NULL){
        printf("No se pudo crear el archivo.");
        fclose(aDescs);
        exit(3);
    }
    fread(&desc, sizeof(T_Descargas),1,aDescs);
    while(!feof(aDescs)){
        strcpy(nombre,desc.nombreU);
        totalDesc=0;

        while(!feof(aDescs) && strcmpi(nombre,desc.nombreU)==0){
            pos=buscar(v[], ce, desc.cod);
            if(pos != -1){
                if(v[pos].tam==desc.kbDesc){
                    totalDesc++;
                    mDesc[pos][desc.dia-1]++; // Punto 2
                }
            fread(&desc, sizeof(T_Descargas),1,aDescs);
            }
            strcpy(user.nombreU,nombre);
            user.cantDescComp=totalDesc;
            fwrite(&user, sizeof(T_Usuarios),1,aUsers); // Punto 1
        }
        fclose(aDescs);
        fclose(aUsers);
    }
}

int buscar(T_App v[], int ce, int x){
    int pos=-1, i=0;

    while(pos==-1 && i<ce){
        if(v[i].cod == x)
            pos=i;
        else
            i++;
    }

    return pos;
}

void puntoDos(T_App v[], int mD[][31], int cf, int cc){
    int f, c;

    printf("Cod.App\t[1]\t[2]\t[3]\t[4]\t[5]\t[6]\t[7]\t[8]\t[9]\t[10]\t[11]\t[12]\t[13]\t[14]\t[15]\t[16]\t[17]\t[18]\t[19]\t[20]\t[21]\t[22]\t[23]\t[24]\t[25]\t[26]\t[27]\t[28]\t[29]\t[30]\t[31]");

    for(f=0;f<cf;f++){
        printf("\n%d\t",v[f].cod);
        for(c=0;c<cc;c++){
            printf("%d\t", mD[f][c]);
        }
    }
}

int puntoTres(int mD[][31], int cf, int cc){
    int cant=0, f, c, sum;

    for(f=0;f<cf;f++){
        sum=0;
        for(c=0;f<cc;c++){
            sum+=mD[f][c];
        }
        if(sum==0)
            cant++;
    }
    return cant;
}

void puntoCuatro(int mD[][31], int cf, int cc){
    int f, c, sum;

    printf("Días en los que se descargaron, por lo menos una vez, todas las aplicaciones:");

    for(c=0;c<cc;c++){
        sum=0;
        for(f=0;f<cf;f++){
            if(mD[f][c]!=0)
                sum++;
        }
        if(sum==cf)
            printf("\nDia: %d", c+1);
    }
}
