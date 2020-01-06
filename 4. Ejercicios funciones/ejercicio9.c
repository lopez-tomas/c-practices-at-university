#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char ingresarSexo(char);
int sexo(char);
int fechaValidada(int, int, int);
int esBisiesto(int);


int main(){

    char sexo;
    int contF = 0, contM = 0;

    int dia, mes, year, fecha, validada, bisiesto;
    int contOctNac = 0;

    int contNacimiento = 0;

    int masviejo;

    printf("Ingresar sexo (F | M): ");
    fflush(stdin);
    scanf("%c", &sexo);
    getchar();

    sexo = toupper(sexo);

    while(sexo != 'A'){
        // CONTADORES F | M
        if(sexo == 'F'){
            contF++;
        }else{
            contM++;
        }

        // NACIMIENTO
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

        // MUJERES NACIDAS EN OCTUBRE
        if(sexo == 'F' && mes == 10){
            contOctNac++;
        }

        // PERSONAS NACIDAS ANTES DEL 9/7/1990
        if(mes < 1990 && dia < 9 && mes < 7){
            contNacimiento++;
        }

        // REPETIR
        printf("Ingresar sexo (F | M): ");
        fflush(stdin);
        scanf("%c", &sexo);
        getchar();

        sexo = toupper(sexo);

    }

    // MENSAJES
    system("cls");

    printf("Cantidad de mujeres: %d\n", contF);
    printf("Cantidad de hombres: %d\n", contM);

    printf("\nCantidad de mujeres nacidas en el mes de Octubre (todos los anios): %d\n", contOctNac);
    printf("Nacimientos antes del 9 de Julio de 1990: %d\n", contNacimiento);

    // MÁS VIEJO-A



    printf("\nSexo de la persona más vieja: %d", masviejo);

    return 0;
}

char ingresarSexo(char s){

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
