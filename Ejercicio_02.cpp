/*Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar productos, así como gestionar las ventas.
Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad (entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
	A: Registrar un nuevo producto.
	B: Listar los productos registrados.
	C: Buscar un producto por nombre.
	D: Actualizar los datos de un producto.
	E: Eliminar un producto.
	F: Registrar una venta.
	G: Listar las ventas realizadas.
	H: Calcular el total de ventas realizadas.
	S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción.*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};
struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float preciototal;
};

void registrarNuevoProducto(vector<Producto>& productos){
    Producto nuevoProducto;
    cout << "Ingrese el nombre del producto a registrar: ";
    cin.ignore();
    getline(cin, nuevoProducto.nombre);
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;
    productos.push_back(nuevoProducto);
    cout << "Producto registrado exitosamente~!" << endl;
    cout << endl;
}

int main(){	
	vector<Producto> productos;
	int opcion;
	do{
		cout << "---Inventario de Productos y Ventas---"<<endl;
		cout << "Seleccione la opcion que desea realizar en el programa:" << endl;
		cout << "(1) Registrar un nuevo producto" << endl;
		cout << "(2) Listar todos los productos registrados" << endl;
		cout << "(3) Buscar un producto por su nombre" << endl;
		cout << "(4) Actualizar los datos de un producto" << endl;
		cout << "(5) Eliminar un producto" << endl;
		cout << "(6) Registrar una nueva venta" << endl;
		cout << "(7) Listar las ventas ya realizadas" << endl;
		cout << "(8) Calcular el total de ventas realizadas" << endl;
		cout << "(0) Salir del programa" << endl;
		cout << "Selecione su opcion: ";
		cin >> opcion;
		cout << endl;
		switch(opcion){
			
			case 1:{
			registrarNuevoProducto(productos);
			break;
			}
			
			case 2:{
			//funcion listarProductos
			break;
			}
		
			case 3:{
			//funcion buscarProductoNombre
			break;
			}
			
			case 4:{
			//funcion actualizarDatosProducto
			break;
			}
			
			case 5:{
			//funcion eliminarProducto
			break;
			}
			
			case 6:{
			//funcion registrarNuevaVenta
			break;
			}
			
			case 7:{
			//funcion listarVentasRealizadas
			break;
			}
			
			case 8:{
			//funcion calcularTotalVentas
			break;
			}
			
			case 0:{
			cout<<"Saliendo del programa..."<<endl;
			break;
			}
			
			default:{
			cout << "Opcion no valida. Intente de nuevo" << endl;
			break;
			}			
		}
		cout << endl;
	} while (opcion != 0);
	
	return 0;
}