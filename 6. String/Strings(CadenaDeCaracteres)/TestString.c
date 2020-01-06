#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
    char nom[5],car;
    int a,b=5,c=1;

    //scanf("%s",nom);
    //SE EXHIBEN TODOS LOS CARACTERES INGRESADOS SI SE COLOCA LUEGO DEL scanf o puts.
    //gets(nom);
    //puts(nom);
    //a=b+c;
    //a=pow(a,2);
    //SOLO SE EXHIBEN LOS CARACTERES DEL TAMAÑO DE LA CADENA.
    //printf("%s",nom);

    a=strcmpi("Casa","casa");
    car='A';
    printf("%d",a);

    return 0;
}
