#include <stdio.h>

int main()
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    switch(num)
    {
    case 'PoI':
        if(num % 2 == 0){
            printf("%d es PAR", num);
        } else{
            printf("%d es IMPAR", num);
        }
        break;
    default:
        printf("Sos puto");
    }

    return 0;
}
