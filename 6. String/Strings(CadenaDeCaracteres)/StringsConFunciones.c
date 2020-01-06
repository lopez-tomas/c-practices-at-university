/*

 STRINGS COMO PARÁMETROS FORMALES Y ACTUALES DE UNA FUNCIÓN
 -----------------------------------------------------------

 Recordar que el nombre o identificador del string es una referencia a la primera dirección de la zona de memoria reservada.

 -String como parámetro real o actual o argumento:  SOLO DE COLOCA EL NOMBRE O IDENTIFICADOR DEL STRING.
                                                    EN REALIDAD LO QUE SE ENVÍA ES LA DIRECCIÓN DE INICIO
                                                    DE MEMORIA PARA QUE SE COPIE EN OTRO ARRAY EN VIRTUD
                                                    DE QUE AMBOS APUNTEN A LA MISMA DIRECCIÓN DE MEMORIA.
                                                    EL PASAJE DE PARÁMETROS ES POR REFERENCIA.


- String como parámetro formal: ES IGUAL A LA DECLARACIÓN DE UN STRING, PERO NO ES OBLIGATORIO COLOCAR EL TAMANO,
                                YA QUE LO QUE RECIBE ES UNA DIRECCIÓN DE MEMORIA.

- Tipo de dato del string en el prototipo: char []  - NO ES OBLIGATORIO COLOCAR EL TAMAÑO -


*/

#include<stdio.h>
#include<conio.h>

//DECLARACIÓN DE CONSTANTES.
#define TAM 51

//PROTOTIPO DE FUNCIONES
void Carga(char []);
void Mostrar(char []);

int main()
{
 //DECLARACIÓN DEL STRING
 char string[TAM]; //PUEDE ALMACENAR HASTA TAM-1 CARCATERES MÁXIMO, EN ESTE EJEMPLO SON 50.

 printf("La direccion de inicio de memoria del string declarado en el main es %x\n\n",string);

 printf("Ingrese una cadena de %d caracteres maximo:",TAM-1);
 Carga(string);   //SOLO SE COLOCA EL NOMBRE DEL STRING CUANDO SE ENVÍA COMO PARÁMETOR REAL.
 Mostrar(string); //SOLO SE COLOCA EL NOMBRE DEL STRING CUANDO SE ENVÍA COMO PARÁMETOR REAL.

 getch();
 return 0;

}

//DEFINICIÓN DE FUNCIONES.
void Carga(char vec[])
{

 printf("\nEl contenido del vector vec (string que recibe como parametro formal) de la funcion en Carga es %x\n\n",vec);

 gets(vec);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mostrar(char vec[])
{
   printf("\nEl contenido del vector vec (string que recibe como parametro formal) de la funcion en Carga es %x\n\n",vec);

   printf("La cadena ingresa es :");
   puts(vec);//agrega salto de línea.
   printf("\nLa cantidad de caracteres ingresados son:%d",strlen(vec));

}


