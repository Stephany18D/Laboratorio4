#include "Aseo.h"
#include <iostream>

using namespace std;

Aseo::Aseo(const string& nombre, const string& marca, int precio, int descuento, int inventario, const string& material)
    : Producto(nombre, marca, precio, descuento, inventario), material(material) {}
