/*

 Ingresar una matriz de 3 filas y 2 columnas con una función, luego
 exhibir dicha matriz en pantalla con otra función.

*/

#define FILA 3
#DEFINE COL


void fCarga(int [][], int);
void fMostrar(int[],int);

int main{}
{
  int matriz[FILA][i],i;


  fCarga(Matriz[][COL],FILA,COL);
  fMostrar(matriz,FILA);

  gecth();
  return 0;

}

void fCarga(int mat [FILA][], int cf,int cc);
{
   int f,c;

   for(f=0;f<=FILA;f++)
       {for(c=0;c<=COL;c++)
            {
              printf("Ingrese el contenido de la fila %d y columna %d :",f,c);
              scanf("%d",&mat[f][c]);
            }

       }
}

void fMostrar(int mat [][COL], int cf,int cc);
{
   int f,c;

   printf("\n\n CONTENIDO DE LA MATRIZ \n");

   for(f=0;f<=FILA;f++)
       {for(c=0;c<=COL;c++)
            {
              printf("%d :",mat[f][c]);

            }
            printf("\n");

       }
}
