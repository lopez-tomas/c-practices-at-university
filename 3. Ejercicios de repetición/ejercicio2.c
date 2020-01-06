#include <stdio.h>

int main()
{
    int num, i, n;

    for(i=1 ; i<=20 ; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &num);

        if(num < 0){
            printf("\n%d\n", i);
        } else{
            n = i - 1;
        }
    }

    return 0;
}
