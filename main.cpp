#include "archivo.h"

int main(){

  int i;
	FILE* f = fopen("pedidos.dat", "rb");
	Pedido ped[5];
	ListaComponentes lComp;
	Modelos mod[5];
	Componentes comp[5];
	nodoProv* listaProv = NULL;
  nodo* listComp = NULL;
    
  escribir_pedidos(f);
  cargar_modelos(mod);
  cargar_ListaComponentes(listComp, mod);
  cargar_componentes(comp);
  cargar_ListaProveedores(listaProv, comp);
    
  calcularCostos(f, mod, comp);
    
  leer_pedidos(f);


  return 0;
}