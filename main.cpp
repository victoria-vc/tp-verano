#include "archivo.h"

int main(){

    //FILE* f = fopen("PEDIDO.DAT", "wb+");
    //int i;

    // cout << "holaa" << endl;

  Nodo* listaComponentes = NULL;
  NodoProv* listaProveedores = NULL;
  Modelos mod[50];
  Componentes comps[1000];

  escribir_pedidos();
  leer_pedidos();

  cargar_proveedores(listaProveedores);
  cargar_modelos(mod);
  cargar_componentes(comps, listaProveedores);
  cout << "hola" << endl;

  
 // falta hacer:

  // calcular_costoP();
  // buscar_modelo();
  // buscar_proveedor();
  // calcular_costoT();
  // meter todo de nuevo en el archivo pedidos.dat
  // imprimir costos ginales
  
  return 0;
}