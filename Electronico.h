#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include "Producto.h"

class Electronico : public Producto {
public:
    Electronico(const string& nombre, const string& marca, int precio, int descuento, int inventario, int garantia);

private:
    int garantia;
};

#endif // ELECTRONICO_H
