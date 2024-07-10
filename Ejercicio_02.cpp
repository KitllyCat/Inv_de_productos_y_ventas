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
#include <iomanip>
#include <algorithm>
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
    cout << "Ingrese el precio del producto($): ";
    cin >> nuevoProducto.precio;
    productos.push_back(nuevoProducto);
    cout << "Producto registrado exitosamente~!" << endl;
    cout << endl;
}

void listarProductos(const vector<Producto>& productos){
    if (productos.empty()){
        cout << "No hay mas productos registrados" << endl;
    } else {
        cout << "---Lista de Productos---" << endl;
        int contador = 1;
        for (const auto& producto : productos){
            cout << contador << ". Nombre: " << producto.nombre << ", Precio: $" << producto.precio << endl;
            contador++;
        }
    }
}

void buscarProductoNombre(const vector<Producto>& productos){
    string nombre;
    cout << "Ingrese el nombre del producto para buscar: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    for (const auto& producto : productos){
        if (producto.nombre == nombre){
            cout << "Producto encontrado:" << endl;
            cout << "Nombre: " << producto.nombre << ", Precio: $" << producto.precio << endl;
            encontrado = true;
            break;
        }
    if (!encontrado){
        cout << "El producto no existe o no se ha encontrado" << endl;
    }
    }
}

void actualizarDatosProducto(vector<Producto>& productos){
    string nombre;
    cout << "Ingrese el nombre del producto para actualizar sus datos: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    for (auto& producto : productos){
        if (producto.nombre == nombre){
            cout << "Producto encontrado. Ingrese el nuevo precio del producto: ";
            cin >> producto.precio;
            cout << "Precio actualizado exitosamente~!" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado){
        cout << "El producto no existe o no se ha encontrado" << endl;
    }
}

void eliminarProducto(vector<Producto>& productos, const string &nombre){
    int indice = -1;
    for (int i = 0; i < productos.size(); ++i){
        if (productos[i].nombre == nombre){
            indice = i;
            break;
        }
    }

    if (indice != -1){
        for (int i = indice; i < productos.size() - 1; ++i){
            productos[i] = productos[i + 1];
        }
        productos.pop_back();
        cout << "El producto ha sido eliminado correctamente~!" << endl;
    } else{
        cout << "Producto no encontrado, ingrese correctamente el nombre" << endl;
    }
}

void registrarNuevaVenta(vector<Producto>& productos, vector<Venta>& ventas, int& idVentaContador){
    if (productos.empty()){
        cout << "No hay más productos disponibles para la venta" << endl;
        return;
    }

    string nombreProducto;
    int cantidad;

    cout << "Ingrese el nombre del producto a vender: ";
    cin.ignore();
    getline(cin, nombreProducto);

    int indice = -1;
    for (int i = 0; i < productos.size(); ++i){
        if (productos[i].nombre == nombreProducto){
            indice = i;
            break;
        }
    }
    if (indice == -1){
        cout << "Producto no encontrado, ingrese el nombre correctamente o intente de nuevo" << endl;
        return;
    }

    cout << "Ingrese la cantidad a vender: ";
    cin >> cantidad;

    float precioTotal = productos[indice].precio * cantidad;

    stringstream ss;
    ss << fixed << setprecision(2) << precioTotal;
    string precioTotalStr = ss.str();

    ventas.push_back({idVentaContador++, nombreProducto, cantidad, precioTotal});

    cout << "Venta registrada satisfactoriamente~! Precio total: $" << precioTotalStr << endl;
}

void listarVentasRealizadas(const vector<Venta>& ventas){
    if (ventas.empty()){
        cout << "No se ha realizado ninguna venta" << endl;
    } else{
        cout << "Listado de las ventas realizadas:" << endl;
        for (const auto& venta : ventas) {
            cout << "ID Venta: " << venta.idVenta << ", Producto: " << venta.producto
                 << ", Cantidad: " << venta.cantidad << ", Precio Total: " << venta.preciototal << endl;
        }
    }
}

int main(){	
	vector<Producto> productos;
	vector<Venta> ventas;
    int idVentaContador = 1;
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
			listarProductos(productos);
			break;
			}
		
			case 3:{
			buscarProductoNombre(productos);
			break;
			}
			
			case 4:{
			actualizarDatosProducto(productos);
			break;
			}
			
			case 5:{
			string nombre;
			cout << "Ingrese el nombre del producto que desea eliminar de la lista: ";
			cin.ignore();
			getline(cin, nombre);
			eliminarProducto(productos, nombre);
			break;
        	}
			
			case 6:{
			registrarNuevaVenta(productos, ventas, idVentaContador);
			break;
			}
			
			case 7:{
			listarVentasRealizadas(ventas);
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