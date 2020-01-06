/*

 VECTORES DE STRINGS COMO PAR�METROS FORMALES Y ACTUALES DE UNA FUNCI�N
 ----------------------------------------------------------------------

 Recordar que el nombre o identificador del vector de string es una referencia a la primera direcci�n de la zona de memoria reservada.

 -vector de string  como par�metro real o actual o argumento:  SOLO DE COLOCA EL NOMBRE O IDENTIFICADOR DE LA MATRIZ.
                                                    EN REALIDAD LO QUE SE ENV�A ES LA DIRECCI�N DE INICIO
                                                    DE MEMORIA PARA QUE SE COPIE EN OTRO ARRAY EN VIRTUD
                                                    DE QUE AMBOS APUNTEN A LA MISMA DIRECCI�N DE MEMORIA.
                                                    EL PASAJE DE PAR�METROS ES POR REFERENCIA.


- vector de string  como par�metro formal: ES IGUAL A LA DECLARACI�N DE UN VECTOR DE STRING, PERO NO ES OBLIGATORIO COLOCAR EL TAMA�O DE FILA,
                                           PERO S� ES OBLIGATORIO COLOCAR EL TAMA�O DE LA COLUMNA.

- Tipo de dato del vector de string  en el prototipo: char [][CANTIDAD DE COLUMNAS]  - NO ES OBLIGATORIO COLOCAR LA CANTIDAD DE FILAS -


*/

#include<stdio.h>
#include<conio.h>

//DECLARACI�N DE CONSTANTES.
#define CANT_FILAS 2
#define CANT_COLUMNAS 2

//PROTOTIPO DE FUNCIONES

void Carga(char [][CANT_COLUMNAS],int);
void Mostrar(char [][CANT_COLUMNAS],int);




int main()
{

  char VecString [CANT_FILAS][CANT_COLUMNAS];//DECLARACI�N.


 printf("La direccion de inicio de memoria del vector de string declarada en el main es %x\n\n",VecString);

 //LLAMAR O INVOCAR A LAS FUNCIONES.
 Carga(VecString,CANT_FILAS);  //SOLO SE COLOCAR EL NOMBRE DEL VECTOR DE STRING CUANDO SE ENV�A COMO PAR�METOR REAL.
 Mostrar(VecString,CANT_FILAS); //SOLO SE COLOCAR EL NOMBRE DEL VECTOR DE STRING CUANDO SE ENV�A COMO PAR�METOR REAL.


 getch();
 return 0;

}

//DEFINICI�N DE FUNCIONES.
void Carga(char VecString[][CANT_COLUMNAS],int cf)
{
 int f;

 printf("\nEl contenido de la vector de string mat (VecString que recibe como parametro formal) de la funcion en Carga es %x\n\n",VecString);

   for (f=0;f<CANT_FILAS;f++)//CARGA POR FILAS.
       {
          printf("Ingrese el %d string:",f+1);
          gets(VecString[f]);//ACCESO COMO VECTOR.
       }
}
/////////////////////////////////////////////////////////////////////////
void Mostrar(char VecString[][CANT_COLUMNAS],int cf)
{
 int f;

 printf("\nEl contenido de la vector de string mat (VecString que recibe como parametro formal) de la funcion en Carga es %x\n\n",VecString);

  printf("\nVECTOR DE STRINGS\n");
   for (f=0;f<CANT_FILAS;f++)
    {
      puts(VecString[f]);//ACCESO COMO VECTOR.
    }

}

