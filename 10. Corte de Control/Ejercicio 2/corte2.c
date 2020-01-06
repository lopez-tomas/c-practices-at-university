#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct sfactura
{
    int suc;
    int dpto;
    float impo;
};

struct sTotSuc
{
    int suc;
    float impo;
};

int main()
{
    FILE *paf,*pats;
    struct sfactura fac;
    struct sTotSuc aux;
    float totsuc, tot=0, totDpto,max;
    int primero=0;
    int sucant,dptoant, maxdpto,maxsuc;
    paf=fopen("FactSucDpto.dat","rb");
    pats=fopen("sumxsuc.dat","wb");
    if(paf==NULL || pats==NULL)
    {
        printf("Error al abrir los archivos");
        getch();
        exit(1);
    }
    fread(&fac,sizeof(fac),1,paf);
    while(!feof(paf))
    {
        sucant=fac.suc;
        totsuc=0;
        while(!feof(paf) && sucant==fac.suc)
        {
            dptoant=fac.dpto;
            totDpto=0;
            while(!feof(paf) && sucant==fac.suc && dptoant==fac.dpto)
            {
                totDpto+=fac.impo;
                fread(&fac,sizeof(fac),1,paf);
            }
            if(primero==0||totDpto>max)
            {
                max=totDpto;
                primero=1;
                maxdpto=dptoant;
                maxsuc=sucant;
            }
            printf("\nTotal del dpto %d de la sucursal %d es %.2f",dptoant,sucant,totDpto);
            totsuc+=totDpto;
        }
        aux.impo=totsuc;
        aux.suc =sucant;
        fwrite(&aux,sizeof(aux),1,pats);
        printf("\nEl total del sucursal %d es %.2f",sucant,totsuc);
        tot+=totsuc;
    }
    if(primero==1)
    {
        printf("\nEl mayor departamento fue %d de la sucursal %d", maxdpto,maxsuc);
    }

    fclose(paf);
    fclose(pats);
    printf("\nTotal General: %.2f", tot);
    getch();
    return 0;
}
