#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ingClase(char, char);

int main(){
    ingClase('F', 'M');

    printf("$c", sexo);

    return 0;
}

char ingClase(char f, char m){
    char s;

    do{

        printf("Sexo (F | M): ");
        fflush(stdin);
        scanf("%c", s);
        s = toupper(s);

    }while(s != f && s != m);

    return s;
}


