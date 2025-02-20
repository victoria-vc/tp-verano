#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <cstring>

using namespace std;

struct ListaProveedores{
	int id_provs;
	char nombre[40+1];
	float valor_unitario;
};

struct nodoProv{
	ListaProveedores info; 
	nodoProv* sgte;
};

struct ListaComponentes{
	int id_accesorio;
	int cantidad;
};

struct nodo{
	ListaComponentes info;
	nodo* sgte;
};

struct Componentes{
	int id_accesorio; 
	char descripcionCom[100+1]; 
	int stock;
	nodoProv* ListaProv;
};

struct Modelos{
	int id_modelo;
	char descripcionMod[100+1]; 
	float precio_base;
	char temporada; 
	nodo* ListaComp;
};

struct Pedido{
	int id_pedido;
	int id_linea;
	int fecha; 
	int id_modelo;
	int cantidad;
	float costo;
};

nodo* insertarOrdenado(nodo*&, ListaComponentes);
nodoProv* insertarOrdenadoProv(nodoProv*&, ListaProveedores);
void escribir_pedidos(FILE*&);
void leer_pedidos(FILE*);
void cargar_modelos(Modelos[]);
void cargar_ListaComponentes(nodo*&, Modelos[]);
void cargar_componentes(Componentes[]);
void cargar_ListaProveedores(nodoProv*&, Componentes[]);
void renovarStock(Componentes[], Modelos[], FILE* );
void calcularCostos(FILE*&, Modelos[], Componentes[]);




#endif