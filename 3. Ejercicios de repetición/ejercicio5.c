#include <stdio.h>

int main()
{
    int i, suma=0, cant;
    float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;

    printf("Ingrese la cantidad de numeros que desea sumar: ");
    scanf("%d", &cant);

    printf("\nIngrese 10 numeros: ");
        scanf("%f" "%f" "%f" "%f" "%f" "%f" "%f" "%f" "%f" "%f", &num1, &num2, &num3, &num4, &num5,
                                                                 &num6, &num7, &num8, &num9, &num10);
        getchar();

    for(i=1 ; i<=cant ; i++){
        suma = num + i;
    }

    printf("\n%.2f\n", suma);


    return 0;
}
