#include <stdio.h>
#include <stdlib.h>


int ingresarHora(int);
int ingresarMinuto(int);
int ingresarSegundo(int);

int mostrarHora(int, int, int);

int cambioHora(int, int);
int cambioMinutoSegundo(int, int);


int main(){
    int hh, mm, ss;
    int hora1;

    int hh2, mm2, ss2;
    int hora2;

    int hf, mf, sf;

    // HORA
    printf("# Ingrese una hora completa #\n");
    printf("\n");

    hh = ingresarHora(hh);
    mm = ingresarMinuto(mm);
    ss = ingresarSegundo(ss);

    printf("Hora ingresada: %d:%d:%d\n", hh, mm, ss);

    // TIEMPO
    printf("\n# Ingrese otra hora completa #\n");
    printf("\n");

    hh2 = ingresarHora(hh2);
    mm2 = ingresarMinuto(mm2);
    ss2 = ingresarSegundo(ss2);

     printf("Hora ingresada: %d:%d:%d\n", hh2, mm2, ss2);

    // FUNCIÓN CAMBIOHORA
    hf = cambioHora(hh, hh2);

    // FUNCION CAMBIOMINUTOSEGUNDO
    mf = cambioMinutoSegundo(mm, mm2);
    sf = cambioMinutoSegundo(ss, ss2);

    // NUEVA HORA
    printf("\nNueva hora: %d:%d:%d\n", hf, mf, sf);

    return 0;
}

int cambioHora(int a, int b){
    int hp, hf;

    hp = a + b;

    if(hp < 24){
        hf = hp;
    }else{
        if(a > b){
            hf = (a - 24) + b;
        }else{
            hf = (b - 24) + a;
        }
    }
    return hf;
}

int cambioMinutoSegundo(int a, int b){
    int mosp, mosf;

    mosp = a + b;

    if(mosp < 60){
        mosf = mosp;
    }else{
        if(a > b){
            mosf = (a - 60) + b;
        }else{
            mosf = (b - 60) + a;
        }
    }
    return mosf;
}

int ingresarHora(int h){
    do{
        printf("Ingrese una hora (HH): ");
        scanf("%d", &h);
        printf("\n");

        system("cls");
    }while(h > 24);

    return h;
}
int ingresarMinuto(int m){
    do{
        printf("Ingrese unos minutos (MM): ");
        scanf("%d", &m);
        printf("\n");

        system("cls");
    }while(m > 60);

    return m;
}

int ingresarSegundo(int s){
    do{
        printf("Ingrese unos segundos (SS): ");
        scanf("%d", &s);
        printf("\n");

        system("cls");
    }while(s > 60);

    return s;
}
