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
  cargar_componentes(comps);
  cout << "hola" << endl;

  
  // cargar_componentes();

  // calcular_costoP();
  // buscar_modelo();
  // buscar_proveedor();
  // calcular_costoT();
  
  return 0;
}