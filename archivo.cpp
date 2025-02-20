#include "archivo.h"

nodo* insertarOrdenado(nodo*& listComp, ListaComponentes lComp){
	
	nodo* aux = new nodo();
	aux->info = lComp;
	aux->sgte = NULL;
	if(listComp == NULL || listComp->info.id_accesorio > lComp.id_accesorio ){
		aux->sgte = listComp;
		listComp = aux;
	}
	else{
		nodo* q = listComp;
		while(q->sgte != NULL && q->sgte->info.id_accesorio < lComp.id_accesorio){
			q = q->sgte;
		}
		aux->sgte = q->sgte;
		q->sgte = aux;
	}
	
	return aux;
}

nodoProv* insertarOrdenadoProv(nodoProv*& listaProv, ListaProveedores prov){
	
	nodoProv* aux = new nodoProv();
	aux->info = prov;
	aux->sgte = NULL;
	if(listaProv == NULL || listaProv->info.id_provs > prov.id_provs ){
		aux->sgte = listaProv;
		listaProv = aux;
	}
	else{
		nodoProv* q = listaProv;
		while(q->sgte != NULL && q->sgte->info.id_provs < prov.id_provs){
			q = q->sgte;
		}
		aux->sgte = q->sgte;
		q->sgte = aux;
	}
	
	return aux;
}

void escribir_pedidos(FILE*& archivo){
	
  archivo = fopen("pedidos.dat", "wb");

    Pedido pedidos[5] = {
          {1, 1, 20250101, 1, 4, 0},
          {1, 2, 20250101, 2, 6, 0},
          {2, 1, 20250102, 1, 2, 0},
          {3, 1, 20250103, 3, 5, 0},
          {4, 1, 20250103, 4, 10, 0},
      };
      
fwrite(&pedidos, sizeof(Pedido), 5, archivo); 

  fclose(archivo);
  return;
}


void leer_pedidos(FILE* archivo){
	
	Pedido ped;
    archivo = fopen("pedidos.dat", "rb");
    
    cout << "PEDIDOS: " << endl;
    cout << "--------------------------------" << endl;
    while (fread(&ped, sizeof(Pedido), 1, archivo) == 1){ 
        cout << "ID Pedido: " << ped.id_pedido << endl;
        cout << "ID Linea: " << ped.id_linea << endl;
        cout << "Fecha: " << ped.fecha << endl;
        cout << "ID Modelo: " << ped.id_modelo << endl;
        cout << "Cantidad: " << ped.cantidad << endl;
        cout << "Costo: " << ped.costo << endl;
        cout << "--------------------------------" << endl;
    }
  
    fclose(archivo);
}

void cargar_modelos(Modelos modelo[]){
      
      for(int i = 0; i < 5; i++){
      modelo[i].id_modelo = 0;
      modelo[i].precio_base = 0;
      modelo[i].temporada = 'v';
      strcpy(modelo[i].descripcionMod, "xxx");
      modelo[i].ListaComp = NULL;
      }
     
      modelo[0].id_modelo = 1;
      strcpy(modelo[0].descripcionMod, "Clasico");
      modelo[0].precio_base = 400;
      modelo[0].temporada = 'v';

      modelo[1].id_modelo = 2;
      strcpy(modelo[1].descripcionMod, "Deportivo");
      modelo[1].precio_base = 120;
      modelo[1].temporada = 'v';

      modelo[2].id_modelo = 3;
      strcpy(modelo[2].descripcionMod, "Casual");
      modelo[2].precio_base = 200;
      modelo[2].temporada = 'v';

      modelo[3].id_modelo = 4;
      strcpy(modelo[3].descripcionMod, "Elegante");
      modelo[3].precio_base = 600;
      modelo[3].temporada = 'v';

      modelo[4].id_modelo = 5;
      strcpy(modelo[4].descripcionMod, "Rock");
      modelo[4].precio_base = 150;
      modelo[4].temporada = 'v';

    return;       
}

void cargar_ListaComponentes(nodo*& ListComp, Modelos mod[]){
	
    for(int i = 0 ; i < 5 ; i++){
        mod[i].ListaComp = NULL;
    }

    for (int i = 0; i < 5; i++) {
        ListaComponentes nuevoComp;

        nuevoComp.id_accesorio = 1000 + i;
        nuevoComp.cantidad = (i + 1) * 5; 

        insertarOrdenado(mod[i].ListaComp, nuevoComp);
    }

return;
}


void cargar_componentes(Componentes comp[]){

      for(int i = 0; i < 5; i++){
          comp[i].id_accesorio = 0;
          comp[i].stock = 0; 
          strcpy(comp[i].descripcionCom, "xxx");
          comp[i].ListaProv = NULL;
        }
        comp[0].id_accesorio = 1000;
        strcpy(comp[0].descripcionCom, "Suela");
        comp[0].stock = 400;

        comp[1].id_accesorio = 1001;
        strcpy(comp[1].descripcionCom, "Cordon");
        comp[1].stock = 600;

        comp[2].id_accesorio = 1002;
        strcpy(comp[2].descripcionCom, "Goma");
        comp[2].stock = 700;

        comp[3].id_accesorio = 1003;
        strcpy(comp[3].descripcionCom, "Pigmento");
        comp[3].stock = 2000;
        
        comp[4].id_accesorio = 1004;
        strcpy(comp[4].descripcionCom, "Tachas");
        comp[4].stock = 800;
       
return;
}

void cargar_ListaProveedores(nodoProv*& ListaProv, Componentes comp[]){
    for(int i = 0 ; i < 5 ; i++){
        comp[i].ListaProv = NULL;
    }

    for(int i = 0 ; i < 5 ; i++){
        ListaProveedores prov1 = {1, "Juan", 100+(i*3)};
        ListaProveedores prov2 = {2, "Jose", 300-(i*50)};
        ListaProveedores prov3 = {3, "Ignacio", 80+(i*30)};
        
        insertarOrdenadoProv(comp[i].ListaProv, prov1);
        insertarOrdenadoProv(comp[i].ListaProv, prov2);
        insertarOrdenadoProv(comp[i].ListaProv, prov3);
    }

return;
}

void renovarStock(Componentes comp[], Modelos mod[], FILE* f){
	
    Pedido ped;
	f = fopen("pedidos.dat", "rb+");
	
	while(fread(&ped, sizeof(Pedido),1, f )){
		for(int i = 0 ; i < 5 ; i++){
		int actualizar = ped.cantidad * mod[i].ListaComp->info.cantidad;
		comp[i].stock -= actualizar;
	    }
	}
	
}

void calcularCostos(FILE*& f, Modelos mod[], Componentes comp[]){
	
    f = fopen("pedidos.dat", "rb+");

    Pedido ped;
    int pedidoActual = -1;
    float costoTotal = 0;

    while (fread(&ped, sizeof(Pedido), 1, f)){ 
        if (ped.id_pedido != pedidoActual){
            if (pedidoActual != -1) {  
                cout << "Costo total: $" << costoTotal << endl << endl;
            }
            pedidoActual = ped.id_pedido;
            costoTotal = 0; 
            cout << "PEDIDO " << pedidoActual << ":" << endl;
        }
        float costoLinea = 0;
        for (int i = 0; i < 5; i++){
            if (ped.id_modelo == mod[i].id_modelo){
                nodo* aux = mod[i].ListaComp;
                while (aux != NULL){
                    int idAccesorio = aux->info.id_accesorio;
                    int cantAccesorio = aux->info.cantidad;
                    float valMin = 9999;  
                    for (int j = 0; j < 5; j++){
                        if (comp[j].id_accesorio == idAccesorio){
                            nodoProv* aux2 = comp[j].ListaProv;
                            while (aux2 != NULL){
                                if (aux2->info.valor_unitario < valMin){
                                    valMin = aux2->info.valor_unitario;
                                }
                                aux2 = aux2->sgte;
                            }
                        }
                    }
                    costoLinea += (cantAccesorio * ped.cantidad) * valMin;

                    aux = aux->sgte;
                }
                costoLinea += mod[i].precio_base;  
            }
        }
        
        cout << "Linea " << ped.id_linea << ": $" << costoLinea << endl;
        costoTotal += costoLinea;

        ped.costo = costoLinea;  
        int pos = ftell(f) - sizeof(Pedido); 
        fseek(f, pos, SEEK_SET);  
        fwrite(&ped, sizeof(Pedido), 1, f);
		fflush(f);  
        fseek(f, pos + sizeof(Pedido), SEEK_SET);
    }
    
    cout << "Costo total: $" << costoTotal << endl << endl;
    renovarStock(comp, mod, f);
    
    fclose(f);
return;
}
