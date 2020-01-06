#include <stdio.h>
#include <stdlib.h>

struct Examen{
    int dni;
    int nota;
};

int main(){
    struct Examen ex;
    struct Examen ex2;
    int aux, dniA;

    FILE *arch, *nuevo;

    arch = fopen("Parcialitos.dat", "rb");

    if(arch == NULL){
        printf("ERROR");
        exit(1);

    }else{
        nuevo = fopen("Ejercicio.dat", "wb");

        if(nuevo == NULL){
            printf("ERROR");
            fclose(arch);
            exit(2);

        }else{
            fread(&ex, sizeof(struct Examen), 1, arch);

            while(!feof(arch)){
                dniA = ex.dni;
                aux = 0;

                do{
                    if(ex.nota > aux){
                        aux = ex.nota;
                    }

                    fread(&ex, sizeof(struct Examen), 1, arch);
                }while(!feof(arch) && dniA == ex.dni);

            printf("%d      %d\n", dniA, aux);
            ex2.dni = dniA;
            ex2.nota = aux;
            fwrite(&ex2, sizeof(struct Examen), 1, nuevo);
            }

            fclose(arch);
            fclose(nuevo);
        }
    }

    return 0;
}


