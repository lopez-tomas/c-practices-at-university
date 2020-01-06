#include <stdio.h>

#define PRIMERO 100
#define SEGUNDO 7
#define TERCERO 3
#define CUARTO 2

int main()
{
    int cant;
    char cod;
    float imp, desc;

    printf("Codigos: 1; 10; 100;");
    printf("\n         2; 22; 222;");
    printf("\n         3; 33;");
    printf("\n         4; 44;\n");

    printf("\nIngrese el CODIGO del articulo que desea: ");
    scanf("%c", &cod);
    getchar();
    getchar();

    printf("\nIngrese la cantidad a comprar: ");
    scanf("%d", &cant);

    switch(cod){
    case '1':
    case '10':
    case '100':
        imp = PRIMERO * cant;
        printf("\nImpuesto: %.2f", imp);
        break;

    case '2':
    case '22':
    case '222':
        if(cant >= 10){
            imp = (cant * 65)/10;
            printf("\nImpuesto: %.2f", imp);
        } else{
            imp = cant * SEGUNDO;
            printf("\nImpuesto: %.2f", imp);
        }
        break;

    case '3':
    case '33':
        if(cant > 10){
            desc = (float)(cant * TERCERO)/10;
            imp = (float)(cant * TERCERO) - desc;
            printf("\nImpuesto: %.2f", imp);
        } else{
            imp = cant * TERCERO;
            printf("\nImpuesto: %.2f", imp);
        }
        break;

    case '4':
    case '44':
        imp = cant * CUARTO;
        printf("\nImpuesto: %.2f", imp);

    default:
        printf("\nElija uno de los CODIGOS anteriores.");
    }

    return 0;
}
