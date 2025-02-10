#include "archivo.h"


void escribir_pedidos(){
  FILE* archivo = fopen("archivo.txt", "wb");

  if(archivo == NULL){
    cout << "Error al abrir el achivo" << endl;
    return;
  }
  
    Pedido pedidos[6] = {
          {10, 1, 20250101, 1, 4, 0},
          {10, 2, 20250101, 2, 6, 0},
          {11, 1, 20250208, 4, 10, 0},
          {12, 1, 20250210, 3, 4, 0},
          {13, 1, 20250211, 1, 4, 0},
          {14, 1, 20250212, 6, 12, 0}
      };
      
// escribimos el archivo
fwrite(pedidos, sizeof(Pedido), 6, archivo); 

// cerramos el archivo
  fclose(archivo);
}


void leer_pedidos(){
    FILE* archivo = fopen("archivo.txt", "rb");
    if(archivo == NULL){
      cout << "Error al abrir el achivo" << endl;
      return;
    }
  
  Pedido regPedido;
  while (fread(&regPedido, sizeof(Pedido), 1, archivo) == 1) { 
    cout << "ID Pedido: " << regPedido.id_pedido << endl;
    cout << "ID Línea: " << regPedido.id_linea << endl;
    cout << "Fecha: " << regPedido.fecha << endl;
    cout << "ID Modelo: " << regPedido.id_modelo << endl;
    cout << "Cantidad: " << regPedido.cantidad << endl;
    cout << "Costo: " << regPedido.costo << endl;
    cout << "--------------------------------" << endl;
  }
  
  fclose(archivo);
  
}



// fseek(archivo, 0, SEEK_SET); (para volver al inicio del archivo)
