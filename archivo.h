#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>

using namespace std;

// estructuras

struct ListaProveedores{
  int id_provs; // numérico sin secuencia
  char nombre[40+1];
  float valor_unitario;
};

struct nodoLS{
  ListaProveedores ListaProv;
  nodoLS* sgte;
};

struct ListaComponentes{
  int id_accesorio;
  int cantidad;
  nodoLS* ListaProv;
};

struct nodoLP{
  ListaComponentes ListComp;
  nodoLP* sgte;
};

struct Componentes{
  int id_accesorio; // secuencia completa que comienza en 1000
  char descripcionCom[100+1]; // cadena de 100 caracteres
  int stock;
  nodoLS* ListaProv;
};

struct Modelos{
  int id_modelo; // número secuencial
  char descripcionMod[100+1]; // cadena de 100 caracteres
  float precio_base;
  char temporada[3+1]; // INVierno o VERano
  nodoLP* ListaComp;
};

struct Pedido{
  int id_pedido;
  int id_linea;
  int fecha; //DDMMAAA
  int id_modelo;
  int cantidad;
  float costo;
};

// funciones para manejar los archivos
void escribir_pedidos();
void leer_pedidos();

// void cargar_modelos();
// void cargar_proveedores();
// void cargar_componentes();


#endif