#include "Producto.h"

Producto::Producto(const string& nombre, const string& marca, int precio, int descuento, int inventario)
    : nombre(nombre), marca(marca), precio(precio), descuento(descuento), inventario(inventario) {}

string Producto::getNombre() const {
    return nombre;
}

void Producto::setNombre(const string& nombre) {
    this->nombre = nombre;
}

string Producto::getMarca() const {
    return marca;
}

void Producto::setMarca(const string& marca) {
    this->marca = marca;
}

int Producto::getPrecio() const {
    return precio;
}

void Producto::setPrecio(int precio) {
    this->precio = precio;
}

int Producto::getDescuento() const {
    return descuento;
}

void Producto::setDescuento(int descuento) {
    this->descuento = descuento;
}

int Producto::getInventario() const {
    return inventario;
}

void Producto::setInventario(int inventario) {
    this->inventario = inventario;
}
