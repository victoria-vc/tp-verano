#include "archivo.h"

Nodo* insertarOrdenado(Nodo*& listaComp, ListaComponentes lComp){
      Nodo* aux = new Nodo();
      aux->info = lComp;
      aux->sgte = NULL;

      if(listaComp == NULL || listaComp->info.id_accesorio > lComp.id_accesorio){
        aux->sgte = listaComp;
        listaComp = aux;
      } else {
          Nodo* q = listaComp;
          while(q->sgte != NULL && q->sgte->info.id_accesorio < lComp.id_accesorio){
            q = q->sgte;
          }
          aux->sgte = q->sgte;
          q->sgte = aux;
      }

      return aux;
}


NodoProv* insertarOrdenadoProv(NodoProv*& listaProv, ListaProveedores Provs){
      NodoProv* aux = new NodoProv();
      aux->info = Provs;
      aux->sgte = NULL;

      if(listaProv == NULL || listaProv->info.id_provs > Provs.id_provs){
        aux->sgte = listaProv;
        listaProv = aux;
      } else {
          NodoProv* q = listaProv;
          while(q->sgte != NULL && q->sgte->info.id_provs < Provs.id_provs){
            q = q->sgte;
          }
          aux->sgte = q->sgte;
          q->sgte = aux;
      }

      return aux;
}


void escribir_pedidos(){
  FILE* archivo = fopen("archivo.txt", "wb");

  if(archivo == NULL){
    cout << "Error al abrir el achivo" << endl;
    return;
  }
  
    Pedido pedidos[2] = {
          {10, 1, 20250101, 1, 4, 0},
          {10, 2, 20250101, 2, 6, 0},
      };
      
      
// escribimos el archivo
fwrite(pedidos, sizeof(Pedido), 2, archivo); 

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
  cout << "Pedidos: " << endl;
  while (fread(&regPedido, sizeof(Pedido), 1, archivo) == 1) { 
    cout << "ID Pedido: " << regPedido.id_pedido << endl;
    cout << "ID Línea: " << regPedido.id_linea << endl;
    cout << "Fecha: " << regPedido.fecha << endl;
    cout << "ID Modelo: " << regPedido.id_modelo << endl;
    cout << "Cantidad: " << regPedido.cantidad << endl;
    cout << "Costo: " << regPedido.costo << endl;
    cout << "--------------------------------" << endl;
  }
    cout << " " << endl;
  
  fclose(archivo);
  
}

void cargar_proveedores(){
  NodoProv* listaProv = NULL;
	
	ListaProveedores prov1, prov2, prov3, prov4, prov5,
                   prov6, prov7, prov8, prov9, prov10;

  prov1.id_provs = 1;
	strcpy(prov1.nombre,"Juan");
	prov1.valor_unitario = 80;
	
	prov2.id_provs = 1;
	strcpy(prov2.nombre,"Jose");
	prov2.valor_unitario = 100;
	
	prov3.id_provs = 2;
	strcpy(prov3.nombre,"Ignacio");
	prov3.valor_unitario = 200;
	
	prov4.id_provs = 2;
	strcpy(prov4.nombre,"Martin");
	prov4.valor_unitario = 150;
	
	prov5.id_provs = 2;
	strcpy(prov5.nombre,"Sol");
	prov5.valor_unitario = 250;
	

	prov6.id_provs = 3;
	strcpy(prov6.nombre,"Julian");
	prov6.valor_unitario = 30;
	
	prov7.id_provs = 4;
	strcpy(prov7.nombre,"Micaela");
	prov7.valor_unitario = 100;
	
	prov8.id_provs = 3;
	strcpy(prov8.nombre,"Paola");
	prov8.valor_unitario = 188;
	
	prov9.id_provs = 4;
	strcpy(prov9.nombre,"Mauricio");
	prov9.valor_unitario = 360;
	
	prov10.id_provs = 3;
	strcpy(prov10.nombre,"Nicolas");
	prov10.valor_unitario = 120;
	
	insertarOrdenadoProv(listaProv, prov1);
	insertarOrdenadoProv(listaProv, prov2);
	insertarOrdenadoProv(listaProv, prov3);
	insertarOrdenadoProv(listaProv, prov4);
	insertarOrdenadoProv(listaProv, prov5);
	insertarOrdenadoProv(listaProv, prov6);
	insertarOrdenadoProv(listaProv, prov7);
	insertarOrdenadoProv(listaProv, prov8),
	insertarOrdenadoProv(listaProv, prov9);
	insertarOrdenadoProv(listaProv, prov10);

   NodoProv* provTemp = listaProv;
    cout << "Los proveedores disponibles son: " << endl;
    while(provTemp != NULL){
      cout << provTemp->info.nombre << endl;
      provTemp = provTemp->sgte;
    }
    cout << " " << endl;
    
  }

  void cargar_modelos(){
      Modelos mod[50];

      //for(int i=0; i<50; i++){
        //mod[i].id_modelo = i+1;
        //mod[i].precio_base = 0;
        //mod[i].temporada = 'v';
        //strcpy(mod[i].descripcionMod, "xxx");
        // mod[i].ListaComp = NULL; // cómo hacemos que el puntero apunte a la lista de prov
      //}

        mod[0].id_modelo = 12;
        strcpy(mod[0].descripcionMod,"Deportivo");
        mod[0].precio_base = 400;
        mod[0].temporada = 'v';

      cout << "Los modelos disponibles son:" << endl;
      for(int i=0; i<1; i++){
        cout << mod[i].id_modelo << endl;
        cout << mod[i].descripcionMod << endl;
        cout << mod[i].precio_base << endl;
        cout << mod[i].temporada << endl;
      }

      cout << " " << endl;

      
    
    

  }
	




// fseek(archivo, 0, SEEK_SET); (para volver al inicio del archivo)
