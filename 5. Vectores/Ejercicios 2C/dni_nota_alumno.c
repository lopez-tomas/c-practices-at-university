// Ingresar el DNI y nota de parcial de un curso.
// El ingreso termina con un DNI negativo.
// Máximo de 60 alumnos.
/*
    Mostrar:

    a) Listado de alumnos con su DNI y nota obtenida.
    b) Máxima nota obtenida y el DNI de los alumnos que la obtuvieran.
*/

#include <stdio.h>
#include <stdlib.h>
#define cant 60
#define limI 19999999
#define limS 99999999

int inicializar(int[], float[], int);
int validarDNI(int, int, int, int[], int, int);
float validarNota(int, int);
void listado(int[], float[], int);
float buscarMax(float[], int);
void alumnosNotaMax(int[], float[], int, float);

int main(){
    int vDNI[cant]={0}, dni, i=0;
    float vNota[cant]={0}, nota, notaMax;

    printf("# Ingreso al sistema escolar #\n\n");

    dni=validarDNI(limI,limS,0,vDNI,cant,0);

    while(dni>0 && i<cant){
        nota=validarNota(0,11);

        vDNI[i]=dni;
        vNota[i]=nota;
        i++;

        dni=validarDNI(limI,limS,0,vDNI,cant,1);
    }

    listado(vDNI, vNota, cant);

    notaMax=buscarMax(vNota, cant);
    printf("\n\nNota máxima del listado: %.2f", notaMax);

    if(notaMax != 1)
        alumnosNotaMax(vDNI, vNota, cant, notaMax);
    else
        printf("No hay alumnos con una nota máxima.");

    return 0;
}

int validarDNI(int infLim, int supLim, int base, int vDNI[], int ce, int buscar){
    int dni,i,no;

    do{
        i=0;
        printf("Ingrese su número de documento: ");
        scanf("%d", &dni);
        system("cls");

        if(buscar != 0){
            for(i;i<ce;i++){
                if(vDNI[i]==dni)
                    no=vDNI[i];
            }
        }
    }while((!(dni>=infLim && dni<supLim) && (dni>base)) || dni==no);

    return dni;
}

float validarNota(int infLim, int supLim){
    float nota;

    do{
        printf("Ingrese la nota del parcial: ");
        scanf("%f", &nota);
    }while(!(nota>infLim && nota<supLim));

    return nota;
}

void listado(int vDNI[], float vN[], int ce){
    int i;

    printf("Listado de alumnos:\n");
    printf("[i]\tNro. Documento\tNota Parcial\n\n");

    for(i=0;i<ce;i++){
        if(vDNI[i]!=0)
            printf(" %d\t%d\t%.2f\n", i+1, vDNI[i], vN[i]);
    }
}

float buscarMax(float vN[], int ce){
    int i;
    float nMax;

    for(i=0;i<ce;i++){
        if(i==0 || vN[i]>nMax)
            nMax=vN[i];
    }

    return nMax;
}

void alumnosNotaMax(int vDNI[], float vN[], int ce, float max){
    int i;

    printf("\n\nDNI de los alumnos que obtuvieron la nota máxima:\n");

    for(i=0;i<ce;i++){
        if(vN[i]==max)
            printf("%d\n", vDNI[i]);
    }

}
