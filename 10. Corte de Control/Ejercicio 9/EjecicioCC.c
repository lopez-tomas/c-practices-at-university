#include <stdio.h>
#include <stdlib.h>

struct CajaA
{
    int nroCaja;
    char nombre[31];
    float saldo;
};
struct Movi
{
    int sucursal;
    int nroCta;
    int dia;
    int mes;
    int codOp;
    float importe;
};

void inicializar(int[],int);
int llenarVec(struct CajaA[],int);
void procesarMovi(struct CajaA[],int[],int);
int buscar(struct CajaA[],int,int);
void actualizarArch(struct CajaA[],int);
void mas5Ex(struct CajaA[],int[],int);

int main()
{
    struct CajaA vCajas[5000];
    int cant,vEx[5000];
    //inicializar(vEx,5000);
    cant=llenarVec(vCajas,5000);
    inicializar(vEx,cant);
    procesarMovi(vCajas,vEx,cant);
    actualizarArch(vCajas,cant); //punto a
    mas5Ex(vCajas,vEx,cant); //punto c
    return 0;
}

int llenarVec(struct CajaA vc[],int ce)
{
    int i=0;
    struct CajaA caja;
    FILE *ac=fopen("ARCH_SALDOS.DAT","rb");
    if(ac==NULL)
        exit(1);
    fread(&caja,sizeof(struct CajaA),1,ac);
    while(!feof(ac) && i<ce)
    {
        vc[i]=caja;
        i++;
        fread(&caja,sizeof(struct CajaA),1,ac);
    }
    return i;
}

void procesarMovi(struct CajaA vc[],int ve[],int ce)
{
    int sucA,pos;
    float totSuc;

    struct Movi movi;

    FILE *am, *ass;

    am=fopen("ARCH_MOVI.DAT","rb");
    if(am==NULL)
        exit(1);
    ass=fopen("ARCH_SIN_SALDOS.DAT","wb");
    if(ass==NULL)
    {
        fclose(am);
        exit(1);
    }
    fread(&movi,sizeof(struct Movi),1,am);
    while(!feof(am))
    {
        sucA=movi.sucursal;
        totSuc=0;
        do
        {
            pos=buscar(vc,ce,movi.nroCta);
            if(pos!=-1){

                switch(movi.codOp){
                    case 1:
                        vc[pos].saldo+=movi.importe;
                        totSuc+=movi.importe;
                        break;
                    case 2:
                        if(movi.importe > vc[pos].saldo)
                            fwrite(&movi,sizeof(struct Movi),1,ass);
                        else
                        {
                            vc[pos].saldo-=movi.importe;
                            ve[pos]++;
                        }
                        break;
                }
            }
            fread(&movi,sizeof(struct Movi),1,am);
        }while(!feof(am) && movi.sucursal==sucA);
        printf("El importe total depositado en la sucursal %d es de %.2f \n",sucA,totSuc); //punto b
    }
    fclose(am);
    fclose(ass);
}

void actualizarArch(struct CajaA vc[],int ce) //punto a
{
    FILE *aa;
    int i;
    aa=fopen("ARCH_SALDOS.DAT","wb");
    if(aa==NULL)
        exit(1);
    for(i=0;i<ce;i++)
        fwrite(&vc[i],sizeof(struct CajaA),1,aa);
    fclose(aa);
}

void mas5Ex(struct CajaA vc[],int ve[],int ce) //punto c
{
    int i;
    printf("Cuentas que realizaron mas de 5 extraciones\n");
    for(i=0;i<ce;i++)
    {
        if(ve[i]>5)
            printf("%d\n",vc[i].nroCaja);
    }
}

int buscar(struct CajaA vc[],int ce,int bus)
{
    int i=0,pos;
    while(i<ce && vc[i].nroCaja!=bus)
        i++;
    if(i==ce)
        pos=-1;
    else
        pos=i;
    return pos;
}

void inicializar(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
}
