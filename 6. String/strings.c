#include <stdio.h>
#include <string.h>

int main(){
    char nombre[21];
    char ape[21];
    char nomape[41];

    printf("Ingrese nombre y apellido: ");
    //scanf("%s", nomape);
    gets(nomape);
    //fgets(nomape, 31, stdin); //stdin es una constante

    //printf("\n%s", nomape);
    puts(nomape);

    printf("\nCantidad de caracteres: %d\n", strlen(nomape));

    printf("Ingrese su nombre: ");
    gets(nom);

    strcpy(nomape, nom);

    printf("Ingrese su apellido: ");
    gets(ape);

    strcat(nomape, ape);

    return 0;
}
