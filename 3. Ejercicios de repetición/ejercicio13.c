#include <stdio.h>

int main(){
    int edad, cont = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    while(edad != 0){
        if(edad == 18){
            cont++;
        }else if(edad == 19){
            cont2++;
        }else if(edad == 20){
            cont3++;
        }else if(edad == 21){
            cont4++;
        }else if(edad == 22){
            cont5++;
        }

        printf("\nIngrese su edad: ");
        scanf("%d", &edad);

    }

    printf("\n18: %d\n", cont);
    printf("19: %d\n", cont2);
    printf("20: %d\n", cont3);
    printf("21: %d\n", cont4);
    printf("22: %d\n", cont5);


    return 0;
}
