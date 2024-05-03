#include "Tienda.h"
#include <iostream>
using namespace std;

Tienda::Tienda() {}
Tienda::~Tienda() {
    for (auto producto : productos) {
        delete producto;
    }
}

void Tienda::agregarProducto(Producto* producto) {
    productos.push_back(producto);
}

void Tienda::modificarProducto(Producto* producto, const string& nombre, int precio, int descuento) {
    if (!nombre.empty()) {
        producto->setNombre(nombre);
    }
    if (precio != -1) {
        producto->setPrecio(precio);
    }
    if (descuento != -1) {
        producto->setDescuento(descuento);
    }
}

void Tienda::agregarAlCarrito(Producto* producto) {
    if (producto->getInventario() > 0) {
        carrito.push_back(producto);
    } else {
        cout << "El producto esta agotado.\n";
    }
}

void Tienda::realizarCompra(CuentaCorriente* cuenta) {
    int total = 0;
    for (auto producto : carrito) {
        total += producto->getPrecio();
    }
    if (total <= cuenta->getSaldo()) {
        cuenta->retirarDinero(total);
        cout << "Compra realizada.\n";
        for (auto producto : carrito) {
            producto->setInventario(producto->getInventario() - 1);
        }
        carrito.clear();
    } else {
        cout << "Saldo insuficiente.\n";
    }
}
