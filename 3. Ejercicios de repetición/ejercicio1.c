#include <stdio.h>

int main()
{
    int nro, i;

    for(i=1; i<=10; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &nro);

        if(nro > 0){
            printf("\n%d\n\n", nro);
        }
    }

    return 0;
}
