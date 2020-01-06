/*
 ESTRUCTURA DE ITERACI�N DEFINIDA
 --------------------------------

 Es una estructura que repite o itera una cantidad de veces exacta o conocida todas las
 instrucciones que se encuentren dentro del ciclo o bucle.

 FORMATO
 -------
                 |-------------------------------|
                 |                               |
                 |             SENTENCIAS        |
         (   VAR.CONTROL   )        A            |
         (-----------------)     REPETIR;        |
         (DESDE|HASTA|PASO )                     |
                 |                               |
                 |                               |
                 |-------------------------------|

 CODIFICACI�N
 ------------

   GENERAL
   -------

   for( DESDE; HASTA ; PASO)
         {
           SENTENCIAS A REPETIR;
         }

   LENGUAJE C
   ----------

   for( VARIABLE DE CONTROL = VALOR_INICIAL;VARIABLE DE CONTROL <OPERADOR RELACIONAL> VALOR_FINAL;VARIABLE DE CONTROL=VALOR_MODIFICACION )
         {
           SENTENCIAS A REPETIR. --> NO MODFICAR EL VALOR DE LA VARIABLE DE CONTROL !!!!!

         }


 COMPONENTES
 -----------

 -VARIABLE DE CONTROL: Es la variable que controla o cuenta la cantidad de iteraciones del ciclo for. Es de tipo int.

 -VALOR_INICIAL, VALOR_FINAL, VALOR_MODIFICACION = Son valores enteros,puede ser una constante, una variable u operaci�n de tipo int.

 -OPERADOR RELACIONAL: <,>,<=,>=,==,!=


 FUNCIONAMIENTO
 --------------

 1) Inicializa el contenido de la variable control con el valor indicado en VALOR_INICIAL.

 2) Compara el valor de la variable de control contra el VALOR_FINAL a trav�s del operador relacional.

 3)
    Si la condici�n se cumple:

        - Ingresa al ciclo for y ejecuta todas las sentencias a repetir.

        - Luego de ejecutar la �ltima sentencia del ciclo for, actualiza el
          valor de la variable de control con el valor indicado en MODIFICA.

        - Regresar al paso 2).

    Si la condici�n no se cumple salir del ciclo for.




*/

#include <stdio.h>

int main()
{
  int i; //DECLARACI�N DE LA VARIABLE DE CONTROL.

  //MOSTRAR TODOS LOS N�MEROS ENTEROS DESDE 1 AL 10.

  for (i=0;i<10;i++)// for(i=1;i<=10;i++)
      {
        printf("\t");
        printf("%d\n",i+1);
      }


  getch();
  return 0;


}
