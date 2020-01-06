/*

 STRINGS COMO PAR�METROS FORMALES Y ACTUALES DE UNA FUNCI�N
 -----------------------------------------------------------

 Recordar que el nombre o identificador del string es una referencia a la primera direcci�n de la zona de memoria reservada.

 -String como par�metro real o actual o argumento:  SOLO DE COLOCA EL NOMBRE O IDENTIFICADOR DEL STRING.
                                                    EN REALIDAD LO QUE SE ENV�A ES LA DIRECCI�N DE INICIO
                                                    DE MEMORIA PARA QUE SE COPIE EN OTRO ARRAY EN VIRTUD
                                                    DE QUE AMBOS APUNTEN A LA MISMA DIRECCI�N DE MEMORIA.
                                                    EL PASAJE DE PAR�METROS ES POR REFERENCIA.


- String como par�metro formal: ES IGUAL A LA DECLARACI�N DE UN STRING, PERO NO ES OBLIGATORIO COLOCAR EL TAMANO,
                                YA QUE LO QUE RECIBE ES UNA DIRECCI�N DE MEMORIA.

- Tipo de dato del string en el prototipo: char []  - NO ES OBLIGATORIO COLOCAR EL TAMA�O -


*/

#include<stdio.h>
#include<conio.h>

//DECLARACI�N DE CONSTANTES.
#define TAM 51

//PROTOTIPO DE FUNCIONES
void Carga(char []);
void Mostrar(char []);

int main()
{
 //DECLARACI�N DEL STRING
 char string[TAM]; //PUEDE ALMACENAR HASTA TAM-1 CARCATERES M�XIMO, EN ESTE EJEMPLO SON 50.

 printf("La direccion de inicio de memoria del string declarado en el main es %x\n\n",string);

 printf("Ingrese una cadena de %d caracteres maximo:",TAM-1);
 Carga(string);   //SOLO SE COLOCA EL NOMBRE DEL STRING CUANDO SE ENV�A COMO PAR�METOR REAL.
 Mostrar(string); //SOLO SE COLOCA EL NOMBRE DEL STRING CUANDO SE ENV�A COMO PAR�METOR REAL.

 getch();
 return 0;

}

//DEFINICI�N DE FUNCIONES.
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
   puts(vec);//agrega salto de l�nea.
   printf("\nLa cantidad de caracteres ingresados son:%d",strlen(vec));

}


