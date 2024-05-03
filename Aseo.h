#ifndef ASEO_H
#define ASEO_H

#include "Producto.h"

class Aseo : public Producto {
public:
    Aseo(const string& nombre, const string& marca, int precio, int descuento, int inventario, const string& material);

private:
    string material;
};

#endif // ASEO_H
