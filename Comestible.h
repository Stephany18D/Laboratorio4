#ifndef COMESTIBLE_H
#define COMESTIBLE_H

#include "Producto.h"

class Comestible : public Producto {
public:
    Comestible(const string& nombre, const string& marca, int precio, int descuento, int inventario, const string& fechaVencimiento);

private:
    string fechaVencimiento;
};

#endif // COMESTIBLE_H
