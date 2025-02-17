#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <cstring>

using namespace std;

// estructuras

struct ListaProveedores{
  int id_provs; // numérico sin secuencia
  char nombre[40+1];
  float valor_unitario;
};

struct NodoProv{
  ListaProveedores info;
  NodoProv* sgte;
};

struct ListaComponentes{
  int id_accesorio;
  int cantidad;
};

struct Nodo{
  ListaComponentes info;
  Nodo* sgte;
};

struct Componentes{
  int id_accesorio; // secuencia completa que comienza en 1000
  char descripcionCom[100+1]; 
  int stock;
  NodoProv* ListaProv; 
};

struct Modelos{
  int id_modelo; // número secuencial
  char descripcionMod[101]; 
  float precio_base;
  char temporada; // [4];
  Nodo* ListaComp;
};

struct Pedido{
  int id_pedido;
  int id_linea;
  int fecha; 
  int id_modelo;
  int cantidad;
  float costo;
};

// funciones para listas
Nodo* insertarOrdenado(Nodo*&, ListaComponentes);
NodoProv* insertarOrdenadoProv(NodoProv*&, ListaProveedores);

// funciones para manejar los archivos
void escribir_pedidos();
void leer_pedidos();

// funciones para cargar datos de "prueba"
void cargar_proveedores(NodoProv*& listaProv);
void cargar_modelos(Modelos modelo[]);
void cargar_componentes(Componentes comp[], NodoProv* listaProv);





#endif