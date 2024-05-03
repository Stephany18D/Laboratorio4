#include "Comestible.h"
#include <iostream>
using namespace std;


Comestible::Comestible(const string& nombre, const string& marca, int precio, int descuento, int inventario, const string& fechaVencimiento)
    : Producto(nombre, marca, precio, descuento, inventario), fechaVencimiento(fechaVencimiento) {}
