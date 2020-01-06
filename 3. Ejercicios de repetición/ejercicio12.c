#include <stdio.h>

int main(){
    int sueldo, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;

    printf("Ingrese su sueldo: ");
    scanf("%d", &sueldo);
    getchar();

    while(sueldo != 0){
        if(sueldo < 900){
            cont1++;
        }else if(sueldo >= 900 && sueldo < 1200){
            cont2++;
        } else if(sueldo >= 1200 && sueldo < 2000){
            cont3++;
        } else if(sueldo >= 2000){
            cont4++;
        }
        printf("Ingrese su sueldo: ");
        scanf("%d", &sueldo);
    }

    printf("\na) Cantidad: %d\n", cont1);
    printf("b) Cantidad: %d\n", cont2);
    printf("c) Cantidad: %d\n", cont3);
    printf("d) Cantidad: %d", cont4);

    return 0;

}



