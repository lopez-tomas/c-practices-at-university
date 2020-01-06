#include <stdio.h>

int fechaValidada(int, int, int);
int nuevoFormato(int, int, int);
int esBisiesto(int);

int main(){
    int dia, mes, year, fecha, validada;

    do{
    printf("Ingrese una fecha(DD): ");
    scanf("%d", &dia);

    printf("\nIngrese una fecha(MM): ");
    scanf("%d", &mes);

    printf("\nIngrese una fecha(AAAA): ");
    scanf("%d", &year);

    printf("\n");
    printf("\n");

    }while(fecha = fechaValidada(dia, mes, year) == 0);

    //fecha = fechaValidada(dia, mes, year);

    validada = nuevoFormato(dia, mes, year);

    printf("%d", validada);

    return 0;
}

int nuevoFormato(int d, int m, int y){


    int year2, mes2, fecha2;

    year2 = y * 10000;
    mes2 = m * 100;

    fecha2 = year2 + mes2 + d;

    return fecha2;

}

int fechaValidada(int d, int m, int a){
    int ok, h, bisiesto;

    if(a < 1600){
        ok = 0;
    }else{
        if(m < 1 || m >12){
            ok = 0;
        }else{
            switch(m){
            case 2:
                bisiesto = esBisiesto(m);
                if(bisiesto == 1){
                    h = 29;
                }else{
                    h = 28;
                }
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                h = 30;
                break;

            default:
                h = 31;
                break;
            }

            if(d < 1 || d > h){
                ok = 0;
            }else{
                ok = 1;
            }
        }
    }

    return ok;
}

esBisiesto(int a){
    int b;

    if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)){
        b = 1;
    }else{
        b = 0;
    }

    return b;
}
