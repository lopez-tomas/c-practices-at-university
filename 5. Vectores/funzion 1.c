#include <stdio.h>
int edadAGrupoEtario (int,int,int,int);
int main()
{
    int edad;
    printf("ingrese edad:");
    scanf("%d",&edad);
    edadAGrupoEtario (edad,0,14,1);
    edadAGrupoEtario (edad,15,21,2);
    edadAGrupoEtario (edad,22,28,3);
    edadAGrupoEtario (edad,29,35,4);
    edadAGrupoEtario (edad,35,42,5);
    edadAGrupoEtario (edad,43,49,6);
    edadAGrupoEtario (edad,50,63,7);
    edadAGrupoEtario (edad,64,150,8);
    return 0;
}

int edadAGrupoEtario (int e,int a,int b,int c)
{int n;
n=0;
    if(a<e<b)
    {
        n=c;
        if(n!=0){
                printf("Valor %d",c);
    }else {printf("No esta en este valor ");}
    return (c);
    }
}
