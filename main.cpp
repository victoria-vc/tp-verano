#include "archivo.h"

int main(){

  

  Nodo* listaComponentes = NULL;
  NodoProv* listaProveedores = NULL;
  Modelos mod[50];
  Componentes comps[1000];

  escribir_pedidos();
  leer_pedidos();

  cargar_proveedores(listaProveedores);
  cargar_modelos(mod);
  cargar_componentes(comps, listaProveedores);


  // prueba:
  int pos;
  pos = buscar_modelo(mod, 50, 3); 
  cout << pos << endl;

 // falta hacer:
 
  // calcular_costoP();
  // buscar_modelo();
  // buscar_proveedor();
  // calcular_costoT();
  // meter todo de nuevo en el archivo pedidos.dat
  // imprimir costos ginales
  
  

  return 0;
}