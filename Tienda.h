#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include "Producto.h"
#include "CuentaCorriente.h"

class Tienda {
public:
    Tienda();
    ~Tienda();
    vector<Producto*> productos;
    vector<Producto*> carrito;

    void agregarProducto(Producto* producto);
    void modificarProducto(Producto* producto, const string& nombre = "", int precio = -1, int descuento = -1);
    void agregarAlCarrito(Producto* producto);
    void realizarCompra(CuentaCorriente* cuenta);


};

#endif // TIENDA_H
