#ifndef SISTEMA_H
#define SISTEMA_H

#include <limits> /* Para manejar correctamente los errores de entrada/salida
al limpiar el buffer de entrada despu�s de que una operaci�n de lectura falle. */
#include <vector> //Libreria para el uso de vectores
#include <windows.h> // Libreria para el uso de las funciones de limpieza de pantalla, espera y pausa
#include <locale> // Libreria para la deteccion del idioma
using namespace std;

// Se incluyen los archivos de encabezado necesarios
#include "Inventario.cpp"
#include "Admin.cpp"
#include "Proveedor.cpp"
#include "Producto.cpp"
#include "Funciones.cpp"
#include "Pedido.cpp"
#include "PedidoEspecial.cpp"
#include "PedidoExclusivo.cpp"

//FUNCIONES
void acceso();
void menuPrincipal();
void submenuProveedores(vector<Proveedor> &listaProveedores);
void agregarProveedor(vector<Proveedor> &listaProveedores);
void eliminarProveedor(vector<Proveedor> &listaProveedores);
void agregarProductoMenu(Inventario &inventario);
void eliminarProductoMenu(Inventario &inventario);
void pedidos(vector<Pedido> &listaPedidos);
void logo();
// Variables globales para su uso en el resto del programa
vector<Proveedor> listaProveedores;
vector<Pedido> listaPedidos;
Inventario capacidadMaxima(100);

#endif