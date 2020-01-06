#include <stdio.h>
#include <stdlib.h>


#define fTam 5
#define cTam 12

void inicializar(int[][cTam], int[], int[], int, int);
void carga(int[][cTam], int[], int[], int, int);

int valSucursal(int, int);
int valRubro(int, int);
int valPedido(int);

void mostrarA(int[][cTam], int, int);
void mostrarBC(int[], int);
void mostrarD(int[], int);
void mostrarE(int[][cTam], int);
void mostrarF();
void mostrarG();

int main(){
    int vSuper[fTam][cTam];
    int vF[fTam];
    int vC[cTam];

    inicializar(vSuper, vF, vC, fTam, cTam);

    carga(vSuper, vF, vC, fTam, cTam);

    printf("\n\n");
    printf("Punto a)\n\n");
    mostrarA(vSuper, fTam, cTam);
    printf("\n\n");

    printf("Punto b)\n\n");
    mostrarBC(vF, fTam);
    printf("\n\n");

    printf("Punto c)\n\n");
    mostrarBC(vC, cTam);
    printf("\n\n");

    printf("Punto d)\n\n");
    mostrarD(vC, cTam);
    printf("\n\n");

    printf("Punto e)\n\n");
    mostrarE(vSuper, fTam);
    printf("\n\n");

    printf("Punto f)\n\n");
    mostrarF(vF, fTam);
    printf("\n\n");

    printf("Punto g)\n\n");
    mostrarG(vC, cTam);
    printf("\n\n");

    return 0;
}

void inicializar(int vS[][cTam], int vF[], int vC[], int cf, int cc){
    int f, c;

    for(f = 0 ; f < cf ; f++){
            vF[f] = 0;
        for(c = 0 ; c < cc ; c++){
            vS[f][c] = 0;
            vC[c] = 0;
        }
    }
}

void carga(int vS[][cTam], int vF[], int vC[], int cf, int cc){
  int numSucursal, codRubro, mercaderia;

  numSucursal = valSucursal(0, 5);

  while(numSucursal != 0 &&){
    codRubro = valRubro(1, 12);
    mercaderia = valPedido(0);

    if(numSucursal >= 1 && numSucursal <= 5){
      vS[numSucursal - 1][codRubro - 1] += mercaderia;
      vF[numSucursal - 1] += mercaderia;
    }

    if(codRubro >= 1 && codRubro <= 12){
      vC[codRubro - 1] += mercaderia;
    }

    numSucursal = valSucursal(0, 5);
  }
}

int valSucursal(int desde, int hasta){
  int s;

  printf("Ingrese la sucursal: ");
  scanf("%d", &s);

  while(s < desde && s > hasta){
    printf("Ingrese la sucursal: ");
    scanf("%d", &s);
  }
  return s;
}
int valRubro(int desde, int hasta){
  int r;

  printf("Ingrese Nro. de Rubro: ");
  scanf("%d", &r);

  while(r < desde && r > hasta){
    printf("Ingrese Nro de Rubro: ");
    scanf("%d", &r);
  }
  return r;
}
int valPedido(int desde){
  int p;

  printf("Ingrese la cantidad de pedidos: ");
  scanf("%d", &p);

  while(p <= desde){
    printf("Ingrese la cantidad de pedidos: ");
    scanf("%d", &p);
  }
  return p;
}


void mostrarA(int vS[][cTam], int cf, int cc){
  int i, f, c;

  for(i = 1 ; i <= cc ; i++){
    printf("    %d\t", i);
  }
  printf("\n\n");

  for(f = 0 ; f < cf ; f++){
    printf("\n%d", f+1);
    for(c = 0 ; c < cc ; c++){
      printf("    %d\t", vS[f][c]);
    }
  }
}

void mostrarBC(int v[], int ce){
  int i;

  if(ce == fTam){
    printf("Sucursales\t Pedidos\n");

    for(i = 0 ; i < ce ; i++){
      printf("%d\t\t %d\n", i+1, v[i]);
    }
  }else{
    printf("Rubros\t Pedidos\n");

    for(i = 0 ; i < ce ; i++){
      printf("%d\t %d\n", i+1, v[i]);
    }
  }
}

void mostrarD(int vC[], int cc){
  int i, m, cont;

  m = vC[0];

  for(i = 0 ; i < cc ; i++){
    if(vC[i] > m){
      m = vC[i];
    }
  }

  for(i = 0 ; i < cc ; i++){
    if(vC[i] == 0){
      cont++;
    }
  }

  if(cont < cc){
    for(i = 0 ; i < cc ; i++){
      printf("Rubro de mayor cantidad de pedidos: %d\n", i+1);
    }
  }else{
    printf("Ningun rubro tiene pedidos.\n");
  }
}

void mostrarE(int vS[][cTam], int cf){
  int i, f;

  printf("\t7\n");

  for(f = 0 ; f < cf ; f++){
    printf("\n%d", f+1);
    printf("\t%d", vS[f][6]);
  }
}

void mostrarF(int vF[], int cf){
  int i, m;

  m = vF[0];

  for(i = 0 ; i < cf ; i++){
    if(vF[i] < m){
      m = vF[i];
    }
  }
  for(i = 0 ; i < cf ; i++){
    if(vF[i] == m && vF[i] != 0){
      printf("Sucursal/es de menor cantidad de pedidos: %d\n", i+1);
    }
  }
  printf("Todas las sucursales no pidieron nada.\n");
}

void mostrarG(int vC[], int cc){
  int i, cont = 0;

  for(i = 0 ; i < cc ; i++){
    if(vC[i] == 0){
      cont++;
    }
  }
  if(cont == cc){
    printf("Todos los rubros no fueron pedidos por ninguna sucursal.\n");
  }else{
    for(i = 0 ; i < cc ; i++){
      if(vC[i] == 0){
        printf("Rubro NO pedido por ninguna sucursal: %d\n", i+1);
      }
    }
  }
}
