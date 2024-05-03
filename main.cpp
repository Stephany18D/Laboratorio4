#include <iostream>
#include <vector>
#include "Producto.h"
#include "Tienda.h"
#include "CuentaCorriente.h"
#include "Comestible.h"
#include "Electronico.h"
#include "Aseo.h"
using namespace std;

int main() {
    string nombre, apellidos, direccion, telefono, numeroIdentificacion, clave;
    double saldo;

    cout << "Bienvenido a la Tienda\n";
    cout << "Ingrese sus datos para crear una cuenta\n";
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Apellidos: ";
    getline(cin, apellidos);
    cout << "Direccion: ";
    getline(cin, direccion);
    cout << "Telefono: ";
    getline(cin, telefono);
    cout << "Número de identificacion: ";
    getline(cin, numeroIdentificacion);
    cout << "Clave de acceso (ingrese 12345 si no tiene una clave): ";
    getline(cin, clave);
    cout << "Saldo inicial: ";
    cin >> saldo;
    cin.ignore();

    CuentaCorriente cuenta(nombre, apellidos, direccion, telefono, numeroIdentificacion, clave, saldo);

    Tienda tienda;

    tienda.agregarProducto(new Comestible("Peras", "NaturFruit", 30, 0, 15, "20/05/2024"));
    tienda.agregarProducto(new Electronico("Tablet", "TechGenius", 800, 5, 10, 24));
    tienda.agregarProducto(new Aseo("Detergente", "CleanFresh", 7, 0, 25, "Líquido"));

    int opcion;
    do {
        cout << "\n Menu de la Tienda \n";
        cout << "1. Agregar productos al carrito.\n";
        cout << "2. Modificar nombres, precios o porcentaje de descuento de productos.\n";
        cout << "3. Realizar compra.\n";
        cout << "4. Salir.\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                if (!tienda.productos.empty()) {
                    cout << "Productos disponibles:\n";
                    for (size_t i = 0; i < tienda.productos.size(); ++i) {
                        cout << i+1 << ". " << tienda.productos[i]->getNombre() << " - Precio: " << tienda.productos[i]->getPrecio() << "\n";
                    }
                    size_t seleccion;
                    cout << "Ingrese el numero del producto que desea agregar al carrito: ";
                    cin >> seleccion;
                    cin.ignore();
                    if (seleccion >= 1 && seleccion <= tienda.productos.size()) {
                        tienda.agregarAlCarrito(tienda.productos[seleccion-1]);
                        cout << "Producto agregado al carrito\n";
                    } else {
                        cout << "Opcion no valida\n";
                    }
                } else {
                    cout << "No hay productos disponibles.\n";
                }
                break;
            }
            case 2: {
                if (!tienda.productos.empty()) {
                    cout << "Seleccione el producto que desea modificar:\n";
                    for (size_t i = 0; i < tienda.productos.size(); ++i) {
                        cout << i+1 << ". " << tienda.productos[i]->getNombre() << "\n";
                    }
                    size_t seleccion;
                    cout << "Ingrese el numero del producto que desea modificar: ";
                    cin >> seleccion;
                    cin.ignore();
                    if (seleccion >= 1 && seleccion <= tienda.productos.size()) {
                        cout << "\nSeleccione que desea modificar:\n";
                        cout << "1. Nombre\n";
                        cout << "2. Precio\n";
                        cout << "3. Descuento\n";
                        int opcion_modificacion;
                        cout << "Ingrese la opcion: ";
                        cin >> opcion_modificacion;
                        cin.ignore();
                        string nuevo_nombre;
                        int nuevo_precio, nuevo_descuento;
                        switch (opcion_modificacion) {
                            case 1:
                                cout << "Ingrese el nuevo nombre: ";
                                getline(cin, nuevo_nombre);
                                tienda.modificarProducto(tienda.productos[seleccion-1], nuevo_nombre);
                                cout << "Nombre modificado\n";
                                break;
                            case 2:
                                cout << "Ingrese el nuevo precio: ";
                                cin >> nuevo_precio;
                                tienda.modificarProducto(tienda.productos[seleccion-1], "", nuevo_precio);
                                cout << "Precio modificado\n";
                                break;
                            case 3:
                                cout << "Nuevo porcentaje de descuento: ";
                                cin >> nuevo_descuento;
                                tienda.modificarProducto(tienda.productos[seleccion-1], "", -1, nuevo_descuento);
                                cout << " Descuento modificado\n";
                                break;
                            default:
                                cout << "Opción no valida\n";
                                break;
                        }
                    } else {
                        cout << "Opción no valid!\n";
                    }
                } else {
                    cout << "No hay productos disponibles.\n";
                }
                break;
            }
            case 3:
                if (!tienda.carrito.empty()) {
                    cout << "\nResumen de Compra\n";
                    int total = 0;
                    for (auto producto : tienda.carrito) {
                        cout << "Producto: " << producto->getNombre() << " - Precio: $" << producto->getPrecio() << "\n";
                        total += producto->getPrecio();
                    }
                    cout << "Total: $" << total << "\n";
                    cout << "Gracias por su compra\n";
                    for (auto producto : tienda.carrito) {
                        producto->setInventario(producto->getInventario() - 1);
                    }
                    tienda.carrito.clear();
                } else {
                    cout << "No hay productos en el carrito\n";
                }
                break;
            case 4:
                cout << "Gracias por su visita\n";
                break;
            default:
                cout << "Ingrese una opcion valida.\n";
                break;
        }
    } while (opcion != 4);

    for (auto producto : tienda.productos) {
        delete producto;
    }

    return 0;
}
