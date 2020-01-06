/*

 STRINGS - CADENA DE CARACTERES
 ------------------------------

 Es un tipo de dato que recibe un tratamiento especial en el lenguaje de progamación C.

 - Es un array unidimensional (vector) homogéneo de tipo char, con el agregado de un caracter en la última posiciónd el array,
   este caracter se llama FIN DE CADENA, el caracter es '\0'

 - Tiene las mismas características de todos los arrays estudiados anteriormente.


 DECLARACIÓN
 -----------

 char nombre o identificador [tamaño];

  Ejemplo :

  //DECLARACIÓN DE UN STRING DE 10 ELEMENTOS.
  char nombre [10];//SE RESERVAN 10 POSICIONES CONTINUAS DE MEMORIA CUYO CONTENIDO DE C/UN ES UNA CONSTANTE DE TIPO CHAR.

        INDICE CONTENIDO
           0      char
           1      char
           2      char
           3      char
           4      char
           5      char
           6      char
           7      char
           8      char
           9      char

FORMATO Y REPRESENTACIÓN EN LA MEMORIA PRINCIPAL
------------------------------------------------

  Idem arrays unidimensioanles para números.


ACCESO
------

  - Se realiza colocando unicamente el nombre o identificador.

  por ejemplo:
                          c
                          |
                 -------------------------
                /  "Ingrese el nombre"    \
                ---------------------------
                          |
                -----------------------
                \     nombre         / -------> SOLO SE COLOCA EL IDENTETICADOR.
                  -------------------           ^
                          |                     |
                 ---------------------          |
                /      nombre          \ -------
                ------------------------
                          |
                        ------
                        \ F /
                          -


   CODIFICACIÓN
   ------------

   - El Formato para string es %s, para char es %c

     ENTRADA O INGRESO (DESPLAZA EL CARACTER DE FIN DE LA CADENA).
     -----------------

     0) fflush(stdin);//LIMPIAR EL BUFER.

     1) scanf("%s",nombre); ---> NO SE COLOCA EL OPERADOR & YA QUE EL IDENTIFICADOR INDICA TAMBIÉN LA DIRECCIÓN DE MEMORIA.
                                 CORTA EL STRING SI ENCUENTRA UN ESPACIO.

     2) gets(nombre);---> ALMACENA TODO LO INGRESADO SIN RESTRICCIONES.

     3) fgets(nombre,10,stdin); -->SOLO ALMACENA 10 CARACTERES. AGREGA EL \n AL STRING.

     NOTA : RECORDAR QUE EL LENGUAJE C NO VALIDA LÍMITES, NO REALIZARÁN VALIDACIONES SOBRE ESTE TIPO DE DATO.

     SALIDA O EGRESO
     ---------------

     1)printf("%s",nombre);//MUESTRA EL STRING DESDE LA POSICIÓN 0 HASTA LA POSICIÓN DONDE SE ENCUENTRA EL \0 (FIN DE LA CADENA).

     2)puts (nombre); //AGREGA UN SALTO DE LÍNEA.

 -CONSTANTES
  ----------

  - Las constantes de tipo char se colocan entre ''

  - Las constantes de tipo string se colocan entre ""

  por ejemplo:

  #define SIMBOLO '/'

  #define MENSAJE "HOLA MUNDO"


-OPERACIONES CON STRINGS
 -----------------------

 SE REALIZAN A TRAVÉS DE LAS FUNCIONES DE C PARA MANIPULAR STRINGS. SE ENCUENTRAN EN LA BIBLIOTECA string.h
 NO SE PUEDEN REALIZAR OPERACIONES CON STRINGS EN FORMA DIRECTA CON LOS OPERADORES =, +=,== , PARA ELLO
 SE DEBEN UTILIZAR LAS FUNCIONES SIGUIENTES:


 OPERACIÓN                FUNCIÓN
    =        strcpy(Cadena_Destino,Cadena_Origen);  COPIA Cadena_Origen en Cadena_Destino.

   +=        strcat(Cadena_Destino,Cadena_Origen);  AÑADE O CONCATENA UNA CADENA CON OTRA. -> MODIFICA LA POSICIÓN DEL '\0' en Cadena_Destino.

   ==        strcampi(Cadena1,Cadena2);             COMPARA DOS STRINGS. RETORNA UN int
                                                    si = 0 -> Cadena1 = Cadena2
                                                    si > 0 -> Cadena1 > Cadena2 Alfabéticamente.
                                                    si < 0 -> Cadena1 < Cadena2 Alfabéticamente.

  strlen (cadena); //RETORNA UN INT QUE REPRESENTA LA CANTIDAD DE CARACTERES QUE TIENE LA CADENA HASTA EL '\0'

-NOTA
 ----

 SI SE DESA RECORRER POSICIÓN A POSICIÓN UN STRING, SE PUDEN UTILIZAR LAS ESTRUCTURAS DE ITERACIÓN AL IGUAL
 QUE ARRAYS UNIDIMENSIONALES.

*/

#include<stdio.h>
#include<string.h>

//CONSTANTE STRING.
#define MENSAJE "\t\tPrimer programa de strings\n\n"

int main()
{
    //DECLARACIÓN DE LOS STRING.
    char Nombre[20],Apellido[20],NomApe[40];


    printf("%s",MENSAJE);

    printf("Ingrese su nombre:");
    fflush(stdin);
    gets(Nombre);

    strcpy(NomApe,Nombre); //Copia en NomApe El contenido de Nombre.
                           //NomApe = Nombre;

    printf("\nIngrese su apellido:");
    fflush(stdin);
    gets(Apellido);

    strcat(NomApe,Apellido); //Añade ,al contenido de NomApe, el contenido de Aoellido.
                              //NomApe += Apellido.

    printf("\nEl Nombre y Apellido ingresado es %s\nla cantidad de caracteres son %d",NomApe,strlen(NomApe));

    if(strcmpi (NomApe,"JuanPerez")==0 ) // if(NomApe=="JuanPerez" || NomApe=="juanperez" )
       printf("\n\nEl nombre ingresado coincide con Juan Perez");


    getch();
    return 0;
}
