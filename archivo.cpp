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
  FILE* archivo = fopen("pedidos.dat", "wb");

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
    FILE* archivo = fopen("pedidos.dat", "rb");
    if(archivo == NULL){
      cout << "Error al abrir el achivo" << endl;
      return;
    }
  
  Pedido regPedido;
  cout << "PEDIDOS: " << endl;
  cout << "--------------------------------" << endl;
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

void cargar_proveedores(NodoProv*& listaProv){
  
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
    cout << "PROVEEDORES:  " << endl;
    cout << "--------------------------------" << endl;
    while(provTemp != NULL){
      cout << provTemp->info.nombre << endl;
      provTemp = provTemp->sgte;
    }
    cout << "--------------------------------" << endl;
    
  }

  void cargar_modelos(Modelos modelo[]){
      
      for(int i=0; i<50; i++){
      modelo[i].id_modelo = i+1;
      modelo[i].precio_base = 0;
      modelo[i].temporada = 'v';
      strcpy(modelo[i].descripcionMod, "xxx");
      modelo[i].ListaComp = NULL;
      }
       modelo[1].ListaComp = new Nodo();
       modelo[1].id_modelo = 12;
       strcpy(modelo[1].descripcionMod, "Deportivo");
       modelo[1].precio_base = 400;
       modelo[1].temporada = 'v';
       modelo[1].ListaComp->info.id_accesorio = 4; 

       modelo[2].ListaComp = new Nodo();
       modelo[2].id_modelo = 14;
       strcpy(modelo[2].descripcionMod, "Casual");
       modelo[2].precio_base = 200;
       modelo[2].temporada = 'v';
       modelo[2].ListaComp->info.id_accesorio = 3;

       modelo[3].ListaComp = new Nodo();
       modelo[3].id_modelo = 16;
       strcpy(modelo[3].descripcionMod, "Elegante");
       modelo[3].precio_base = 600;
       modelo[3].temporada = 'v';
       modelo[3].ListaComp->info.id_accesorio = 2; 

       modelo[4].ListaComp = new Nodo();
       modelo[4].id_modelo = 18;
       strcpy(modelo[4].descripcionMod, "Rock");
       modelo[4].precio_base = 150;
       modelo[4].temporada = 'v';
       modelo[4].ListaComp->info.id_accesorio = 1;

    
      cout << "MODELOS: " << endl;
      cout << "--------------------------------" << endl;
      for(int i=1; i<5; i++){
              cout << "ID de modelo: " << modelo[i].id_modelo << endl;
              cout << "Descripcion: " << modelo[i].descripcionMod << endl;
              cout << "Precio base: " <<  modelo[i].precio_base << endl;
              cout << "Temporada: " << modelo[i].temporada << endl;
          if(modelo[i].ListaComp != NULL){
              cout << "ID de accesorio: " << modelo[i].ListaComp->info.id_accesorio << endl;
        } else {
              cout << "No tiene accesorios" << endl;
        }
              cout << "--------------------------------" << endl;
      }
             
  }
	
void cargar_componentes(Componentes comp[]){
      
      for(int i = 0; i < 1000; i++){
          comp[i].id_accesorio = 1000+i;
          comp[i].stock = 500;
          strcpy(comp[i].descripcionCom, "xxx");
          comp[i].ListaProv = NULL;
      /*  if(comp[1].ListaProv == NULL){
            comp[1].ListaProv = new NodoProv();
            } */
        if(i == 0){
          comp[0].ListaProv = new NodoProv(); // reservamos memoria para el primer nodo de Proveedores (i=0)

          comp[0].id_accesorio = 1000;
          strcpy(comp[0].descripcionCom, "Suela");
          comp[0].ListaProv->info.id_provs = 4; // hacemos que cada componente tenga un id de proveedor
          comp[0].stock = 240;
        }
      }
      /* comp[1].id_accesorio = 1001;
      strcpy(comp[1].descripcionCom, "Cordon");
      comp[1].ListaProv->info.id_provs = 3; // hacemos que cada componente tenga un id de proveedor
      comp[1].stock = 600; */

      cout <<"COMPONENTES: " << endl;
      cout << "--------------------------------" << endl;
      for(int i=0; i<1; i++){
      if(comp[i].ListaProv != NULL){
        cout << "ID de Proveedor: " << comp[i].ListaProv->info.id_provs << endl;
      } else {
          cout << "ID de proveedor no encontrado" << endl;
      }
          cout << "ID: " << comp[i].id_accesorio << endl;
          cout << "Descripcion: " << comp[i].descripcionCom << endl;
          cout << "Stock: " << comp[i].stock << endl;
      }
      cout << "--------------------------------" << endl;
      
  }





// fseek(archivo, 0, SEEK_SET); (para volver al inicio del archivo)
