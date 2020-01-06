#include <stdio.h>

int main()
{
    int hc;
    char cod;
    float imp;

    ok = 1;

    printf("Ingrese HC: ");
    scanf("%d", &hc);

    printf("Ingrese codigo");
    fflush(stdin);
    scanf("%c", &cod);

    if(cod == 'A'){
        imp = 200;
    } else if(cod == 'D'){
        imp = 400;
    } else if(cod == 'F'){
        imp = 600;
    } else if(cod == 'M'){
        imp = 1500;
    } else{
        ok = 1
    }

    if(ok == 1){
        printf("")
    }

    return 0;
}
