#include <stdio.h>

//Para hacer CORTE DE CONTROL, MÍNIMAMENTE, los archivos deben estar agrupados.

struct Examen{
    int dni;
    int nota;
};

int main(){
    struct Examen ex;
    int sum, cont, dniA;

    FILE *arch = fopen("Parcialitos.dat", "rb");

    if(arch == NULL){
        printf("ERROR\n");
    }else{
        fread(&ex, sizeof(struct Examen), 1, arch);

        while(!feof(arch)){
            dniA = ex.dni;
            sum = cont = 0;

            do{
                sum+= ex.nota;
                cont++;

                fread(&ex, sizeof(struct Examen), 1, arch);
            }while(!feof(arch) && dniA == ex.dni);

            printf("%d      %d\n", dniA, sum/cont);
        }

        fclose(arch);
    }

    return 0;
}

// Dado este archivo, genere un archivo con un registro por alumno que tenga DNI y la mayor nota obtenida en un parcialito
