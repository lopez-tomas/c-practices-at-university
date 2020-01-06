#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char ingresarSexo(char);
int comprobarSexo(char);
int octubre(char, int);


int main(){

    char sexo;
    int nacidasOctubre;

    sexo = ingresarSexo(sexo);

    if(sexo == 'F'){
        contF++;
    }else if(sexo == 'M'){
        contM++;
    }

    comprobarSexo(sexo);

    nacOctubre =


    return 0;
}

char ingresarSexo(char s){
    printf("Ingresar sexo (F | M): ");
    fflush(stdin);
    scanf("%c", &sexo);
    getchar();

    sexo = toupper(sexo);

    return s;
}

int comprobarSexo(char fom){
    char sexo;
    int ok;
    while(fom != 'A'){
        ok = 1;

        do{
            printf("Ingrese una fecha(DD): ");
            scanf("%d", &dia);

            printf("\nIngrese una fecha(MM): ");
            scanf("%d", &mes);

            printf("\nIngrese una fecha(AAAA): ");
            scanf("%d", &year);

            printf("\n");
            printf("\n");

        }while((fecha = fechaValidada(dia, mes, year) == 0) && (bisiesto = esBisiesto(year) == 0));

        sexo = ingresarSexo(sexo);

    }
    return ok;
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

int esBisiesto(int a){
    int b;

    if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)){
        b = 1;
    }else{
        b = 0;
    }

    return b;
}
