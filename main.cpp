#include "archivo.h"

int main(){

    //FILE* f = fopen("PEDIDO.DAT", "wb+");
    //int i;

    // cout << "holaa" << endl;


  escribir_pedidos();
  leer_pedidos();
  cargar_proveedores();


  cargar_modelos();
  // cargar_componentes();
  return 0;
}