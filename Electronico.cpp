#include "Electronico.h"
#include <iostream>
using namespace std;

Electronico::Electronico(const string& nombre, const string& marca, int precio, int descuento, int inventario, int garantia)
    : Producto(nombre, marca, precio, descuento, inventario), garantia(garantia) {}
