#include <stdio.h>
#include <stdint.h>

int main(){

    int year, mes;

    printf("Ingrese el numero del mes: ");
    scanf("%d", &mes);
    getchar();

    printf("Ingrese un year (4 digitos): ");
    scanf("%d", &year);
    getchar();


    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        printf("El mes %d tiene 31 dias", mes);

    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
         printf("El mes %d tiene 30 dias", mes);

    } else if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
        printf("El mes %d tiene 29 dias", mes);

    } else{
         printf("El mes %d tiene 28 dias", mes);
    }


    return 0;
}
