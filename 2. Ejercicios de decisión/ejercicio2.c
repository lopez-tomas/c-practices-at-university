#include <stdio.h>

int main()
{
    int nro1, calcular;

    printf("Ingrese un numero: ");
    scanf("%d", &nro1);

    calcular = nro1 % 2;

    if(calcular == 0){
        printf("%d es PAR", nro1);
    } else{
        printf("%d es IMPAR", nro1);
    }

    return 0;
}
