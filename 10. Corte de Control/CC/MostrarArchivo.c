#include <stdio.h>

struct Examen
{
    int dni;
    int nota;
};


int main()
{
    struct Examen ex;
    FILE *arch=fopen("Parcialitos.dat","rb");
    if(arch==NULL)
        printf("ERROR\n");
    else
    {
        fread(&ex,sizeof(struct Examen),1,arch);
        while(!feof(arch))
        {
            printf("%d   %d\n",ex.dni,ex.nota);
            fread(&ex,sizeof(struct Examen),1,arch);
        }
        fclose(arch);
    }

    return 0;
}

