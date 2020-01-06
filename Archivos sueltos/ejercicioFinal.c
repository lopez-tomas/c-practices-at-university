#include <stdio.h>
#include <ctype.h>

int main(){
    int dia, mes, year, cantColegios, i, numEscuela, cantAlumnos = 0, contTec = 0, contNoTec = 0;
    char especialidad, tec, noTec, sexo, opinion;
    int j, dni, nacimiento, diaNac, mesNac, yearNac, edad, contBasico = 0, cont18 = 0, cont19 = 0, cont20 = 0;
    int contMasc = 0, contFem = 0;
    int contBueno = 0, contMalo = 0;

    printf("Ingrese la fecha actual: ");
    scanf("%d" "%d" "%d", &dia, &mes, &year);

    printf("\nIngrese la cantidad de colegios: ");
    scanf("%d", &cantColegios);

    for(i = 1 ; i <= cantColegios ; i++){
        printf("\n");
        printf("\nIngrese el número de la escuela: ");
        scanf("%d", &numEscuela);

        printf("\nIngrese la cantidad de alumnos inscriptos: ");
        scanf("%d", &cantAlumnos);

        printf("\nIngrese la especialidad del colegio (T: Técnico | N: No Técnico): ");
        scanf("%c", &especialidad);
        getchar();

        especialidad = toupper(especialidad);

        if(especialidad == 'T'){
            contTec++;
        }else if(especialidad == 'N'){
            contNoTec++;
        }else{
        }

        cantAlumnos+= cantAlumnos;

        for(j = 1; j == i ; j++){

            printf("\nIngrese su DNI: ");
            scanf("%d", &dni);

            while(dni != 0){
                printf("\nIngrese su fecha de nacimiento: ");
                scanf("%d" "%d" "%d", &diaNac, &mesNac, &yearNac);

                //nacimiento = (yearNac*10000) + (mesNac*100) + diaNac;

                edad = year - yearNac;

                if(edad == 18){
                    cont18++;
                }else if(edad == 19){
                    cont19++;
                }else if(edad == 20){
                    cont20++;
                }else{
                    contBasico++;
                }

                printf("\nIngrese su sexo: ");
                scanf("%c", &sexo);
                getchar();

                sexo = toupper(sexo);

                if(sexo == 'M'){
                    contMasc++;
                }else if(sexo == 'F'){
                    contFem++;
                }else{
                }

                printf("\nOpinión respecto a los conocimientos adquiridos (B: Buenos | M: Malos): ");
                scanf("%c", &opinion);

                if(opinion == 'B'){
                    contBueno++;
                }else if(opinion == 'M'){
                    contMalo++;
                }else{
                }

                cant

                printf("\nIngrese su DNI: ");
                scanf("%d", &dni);

            }
        }

    }



    return 0;
}
