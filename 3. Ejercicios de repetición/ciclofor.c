#include <stdio.h>

int main()
{
    int nro, i;

    for(i=1; i<=5; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &nro);

        if(nro % 2 == 0){
            printf("El numero %d es PAR", nro);
        } else{
            printf("El numero %d es IMPAR", nro);
        }

    }

    return 0;
}
