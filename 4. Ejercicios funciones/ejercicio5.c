#include <stdio.h>
int edadAgrupoEtario(int);

int main(){
    int edad;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    edadAgrupoEtario(edad);

    return 0;
}

int edadAgrupoEtario(int edad){
    if(edad <= 14){
        printf("\n1");
    }else if(edad >= 15 && edad <= 21){
        printf("\n2");
    }else if(edad >= 22 && edad <= 28){
        printf("\n3");
    }else if(edad >= 29 && edad <= 35){
        printf("\n4");
    }else if(edad >= 36 && edad <= 42){
        printf("\n5");
    }else if(edad >= 43 && edad <= 49){
        printf("\n6");
    }else if(edad >= 50 && edad <= 63){
        printf("\n7");
    }else if(edad >= 64){
        printf("\n8");
    }

    return edad;

}
