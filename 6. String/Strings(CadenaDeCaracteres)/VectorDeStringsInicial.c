/*

 VECTORES DE STINGS (ARRAYS BIDIMENSIONALES)
 -------------------------------------------

 - Es un conjunto de strings agrupados bajo un nombre en la memoria principal.

 - Tiene las mismas caracter�sticas que los arrays bidimensionales en la declaraci�n.

 - Cada elemento se identifica a trav�s del �ndice (idem Array unidimensionales) para su acceso.



DECLARACI�N - (SE REALIZA EN TIEMPO DE COMPILACI�N)
------------

   --------------------------------------------------------------------------------------
  | char Identificador o variable [cantidad de filas][cantidad de columnas o caracteres];| ---> MATRIZ EST�TICA: Se debe conocer en tiempo de compilaci�n.
   --------------------------------------------------------------------------------------


   - Identificador: Nombre de la variable dimensionada, es una referencia.

   - cantidad de filas (tama�o m�ximo de filas): Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                                                memoria principal para representar a los elementos del vector de sting de forma
                                                horizontal. Es un int mayor que cero y menor un n�mero int.

  - cantidad de columnas (tama�o m�ximo de columnas):Es ka cantidad m�xima de caracteres -1  que puede almacenar cadad string.
                                                     Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                                                     memoria principal para representar a los elementos del vector de sting de forma
                                                     vertical. Es un int mayor que cero y menor un n�mero int.



FORMATO L�GICO
--------------

  //SE DECLARA COMO UN ARRAY BIDIMENSIONAL (MATRIZ).

  char VecString [5][21];// Vector de strings de 5 filas y cada una puede almacenar 20 caracteres como m�ximo.


       0            20
       |------------|
FILA 0 | string[21] |
       |------------|
       |------------|
FILA 1 | string[21] |
       |------------|
       |------------|
FILA 2 | string[21] |
       |------------|
       |------------|
FILA 3 | string[21] |
       |------------|
       |------------|
FILA 4 | string[21] |
       |------------|



- �ndice de fila: Es un int >=0 y <cantidad de filas.






FORMATO F�SICO -MEMORIA PRINCIPAL
---------------------------------

Idem Array Unidimensionales.




 ACCESO
 ------

     ----------------------------------
     | Identificador [INDICE DE FILA] | SE ACCEDE IGUAL QUE UN ARRAY UNIDIMENSIONAL.
     ----------------------------------

     0<=INDICE DE FILA<CANTIDAD DE FILAS.


     DIRECTO: Se coloca directamente la posici�n de fila y columna a trav�s de una constante int,
              para acceder al contenido de una celda.

     INDIRECTO: Se coloca una operaci�n o expresi�n como �ndice de fila y/o columna que genere como resultado un int.
                Puede ser una constante, una operaci�n, una funci�n, un vector que sean int.


 RECORRIDO
 ---------

 Idem Array Unidimensionales.


 NOTAS
 -----

 RECORDAR QUE UN VECTOR DE STRINGS O CADENAS, SE DECLARA COMO UNA MATRIZ Y SE UTILIZA COMO UN VECTOR.

*/

#include<stdio.h>
#include<conio.h>

//DECLARACI�N DE CONSTANTES.
#define CANT_FILAS 5
#define CANT_COLUMNAS 50


int main()
{
  //DECLARACI�N DEL VECTOR DE STRINGS.
  char VecString[CANT_FILAS][CANT_COLUMNAS];//DECLARACI�N COMO MATRIZ.

  int f;


  //CARGAR EL VECTOR DE STRINGS.
  for (f=0;f<CANT_FILAS;f++)
  {
       printf("Ingrese el %d string:",f+1);
       gets(VecString[f]);//ACCESO COMO VECTOR.

  }


  printf("\nVECTOR DE STRINGS\n");
   for (f=0;f<CANT_FILAS;f++)
    {
      puts(VecString[f]);//ACCESO COMO VECTOR.
    }


 getch();
 return 0;
}

