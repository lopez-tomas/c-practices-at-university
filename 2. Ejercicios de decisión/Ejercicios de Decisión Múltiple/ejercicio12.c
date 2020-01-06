#include <stdio.h>
#include <ctype.h>

int main()
{
    int hc, imp, ok;
    char cod;

    printf("Ingrese su Nro de Historia Clinica: ");
    scanf("%d", &hc);
    printf("\nCodigos: A - D - F - M - T\n");

    printf("\nIngrese el CODIGO correspondiente: ");
    fflush(stdin);
    scanf("%c", &cod);
    getchar();

    cod = toupper(cod);
    ok = 1;

    switch(cod)
    {
    case 'A':
        imp = 200;
        break;

    case 'D':
        imp = 400;
        break;

    case 'F':
        imp = 600;
        break;

    case 'M':
    case 'T':
        imp = 1500;
        break;

    default:
        ok = 0;
    }

    if(ok == 1){
        printf("\nHC: %d", hc);
        printf("\nCOD: %c", cod);
        printf("\nImporte: %d\n", imp);
    } else{
        printf("\nSeleccione uno de los CODIGOS anteriores, por favor");
    }

    return 0;
}
