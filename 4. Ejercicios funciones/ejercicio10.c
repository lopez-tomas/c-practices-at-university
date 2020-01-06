#include <stdio.h>
#include <stdlib.h>

int sumar(int, int);
int restar(int, int);
int porcentaje(int, int);
int mcd(int, int);

int main(){

    int n1, n2, suma, resta, maxcd, op;
    float porcent;

    printf("Ingrese un numero: ");
    scanf("%d", &n1);

    printf("\nIngrese un numero: ");
    scanf("%d", &n2);

    do{
        printf("\n1. Sumar");
        printf("\n2. Restar");
        printf("\n3. Porcentaje");
        printf("\n4. MCD");
        printf("\n5. Limpiar consola");
        printf("\n9. Salir\n");

        printf("\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            suma = sumar(n1, n2);
            printf("\nLa suma es: %d", suma);
            printf("\n");
            break;

        case 2:
            resta = restar(n1, n2);
            printf("\nLa resta es: %d", resta);
            printf("\n");
            break;

        case 3:
            porcent =(float) porcentaje(n1, n2);
            printf("\nEl porcentaje es: %.2f", porcent);
            printf("\n");
            break;

        case 4:
            maxcd = mcd(n1, n2);
            printf("\n%d", mcd);
            printf("\n");
            break;

        case 5:
            system("cls");
            break;

        //case 9:
            //return 0;
        }

    }while(op != 6 && op != 9);

    return 0;
}

sumar(int nro1, int nro2){
    int suma;

    suma = nro1 + nro2;

    return suma;
}

restar(int nro1, int nro2){
    int resta;

    if(nro1 > nro2){
        resta = nro1 - nro2;
    }else{
        resta = nro2 - nro1;
    }

    return resta;
}

porcentaje(int nro1, int nro2){
    float porcentaje;

    if(nro1 > nro2){
        porcentaje = (float)(nro2 * 100)/nro1;
    }else{
        porcentaje = (float)(nro1 * 100)/nro2;
    }

    return porcentaje;
}

int mcd(int nro1, int nro2){
    int resto, resto2;

    resto = nro1 % nro2;

    if(resto == 0){
        resto = nro2;
    }else{

        do{

        resto2 = nro2 % resto;

        }while(resto != 0);

        resto = resto;
    }
    return resto;
}
