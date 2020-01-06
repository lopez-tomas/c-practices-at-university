/*PROGRAMA PARA DECLARAR E INICIALIZAR STRINGS Y VECTORES DE STRING*/

#include <stdio.h>
#include <stdlib.h>

//DECLARACIÓN DE CONSTANTES.
#define FILAS 4 //CANTIDAD DE FILAS.
#define CANT_CAR 31//CANTIDAD DE COLUMNAS O CARACTERES DE CADA STRING.

//PROTOTIPO DE FUNCIONES.
void MostrarString(char [],int);
void MostrarVectorDeCadenas (char [] [CANT_CAR],int,int );

//PROGRMA PRINCIPAL.
int main()
{

   /*STRINGS*/

   char cadena1[CANT_CAR]={"Programacion"};/*DECLARA E INICIALIZA EL STRING COL EL VALOR : Programacion*/

   char cadena2[]= "Programa para inicializar strings,vectores de strings";
                  /*
                   DECLARA E INICIALIZA EL STRING ASIGNANDO EL TAMAÑO 54 A LA DIMENSIÓN.
                   COL EL VALOR : Programa para inicializar strings,vectores de strings
                  */
   char cadena3[]={'h','o','l','a','\0'}; /*DECLARA E INICIALIZA EL STRING CON EL TAMAÑO 5 Y EL VALOR hola

                                            char cadena3[]="hola";
                                            char cadena3[5]="hola";
                                            cahr cadena3[5]={'h','o','l','a','\0'};
                                          */

   char cadena4[]=""; //TAMAÑO 1 Y EL VALOR ES \0 - CADENA VACÍA */

   /*VECTORES DE STRINGS: SE DECLARAN COMO UNA MATRIZ Y SE UTILIZAN COMO UN VECTOR.*/
   char vectorcadena1[FILAS][CANT_CAR] = {"MATERIA","Elementos","de","Programacion"};
                                          /* DECLARA E INICIALIZA EL VECTOR DE STRING
                                             CON LOS SIGUIENTES VALORES :

                                             INDICE CONTENIDO
                                                0     MATERIA
                                                1     Elementos
                                                2     de
                                                3     Programacion

                                             EL MISMO RESULTADO SE OBTIENE CON LAS SIGUIENTES DECLARACIONES:

                                             char cadena[][CANT_CAR] = {"MATERIA","Elementos","de","Programacion"};

                                             char cadena[FILAS][CANT_CAR] = {{"MATERIA"},{"Elementos"},{"de"},{"Programacion"}};

                                            */

   char vectorcadena2[][CANT_CAR] = {"MATERIA","Algebra","I","Ingenieria"};
                                      /* DECLARA E INICIALIZA EL VECTOR DE STRING, ASIGNANDO EL NÚMERO 4
                                         A LA CANTIDAD DE FILAS, CON LOS SIGUIENTES VALORES :

                                             INDICE CONTENIDO
                                                0     MATERIA
                                                1     Algebra
                                                2     I
                                                3     Ingenieria
                                      */
   char vectorcadena3[FILAS][CANT_CAR] = {{"ALUMNO"},{"Juan"},{"Perez"},{"Ingenieria en Informatica"}};
                                          /* DECLARA E INICIALIZA EL VECTOR DE STRING
                                             CON LOS SIGUIENTES VALORES :

                                                 INDICE CONTENIDO
                                                    0     ALUMNO
                                                    1     Juan
                                                    2     Perez
                                                    3     Ingenieria en Informatica
                                          */



   //MOSTRAR
   MostrarString(cadena1,1);
   MostrarString(cadena2,2);
   MostrarString(cadena3,3);
   MostrarString(cadena4,4);
   MostrarVectorDeCadenas(vectorcadena1,FILAS,1);
   MostrarVectorDeCadenas(vectorcadena2,FILAS,2);
   MostrarVectorDeCadenas(vectorcadena3,FILAS,3);

   system("PAUSE");
   return 0;

}
//DESARROLLO DE FUNCIONES.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MostrarString(char cadena [],int nro)
{
  printf("\nValor de la cadena%d : %s\nCantidad de caracteres : %d\n",nro,cadena,strlen(cadena));
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MostrarVectorDeCadenas (char cad [] [CANT_CAR],int cf, int nro )
{
    int i;

    printf("\nVECTOR DE CADENAS%d\n",nro);
    printf("\nINDICE\tCONTENIDO\n------------------\n");

    for(i=0;i<cf;i++)
        {
         printf("%3d\t%s\n",i,cad[i]);
         //puts(cad[i]);
        }
}
