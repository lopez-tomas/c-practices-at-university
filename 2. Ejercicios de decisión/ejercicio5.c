#include <stdio.h>
#include <stdint.h>

int main()
{
    int nro1, nro2, nro3;

    printf("Ingrese tres numeros: ");
    scanf("%d" "%d" "%d", &nro1, &nro2, &nro3);

    if(nro1 > nro2){
        if(nro1 > nro3){
            printf("El mayor numero es: %d", nro1);
        } else{
            printf("El mayor numero es: %d", nro3);
        }
    } else{
        if(nro2 > nro3){
            printf("El mayor numero es: %d", nro2);
        } else{
            printf("El mayor numero es: %d", nro3);
        }
    }

    return 0;
}
