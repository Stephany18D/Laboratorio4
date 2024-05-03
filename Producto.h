#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using namespace std;

class Producto {
public:
    string getNombre() const;
    void setNombre(const string& nombre);
    string getMarca() const;
    void setMarca(const string& marca);
    int getPrecio() const;
    void setPrecio(int precio);
    int getDescuento() const;
    void setDescuento(int descuento);
    int getInventario() const;
    void setInventario(int inventario);

    Producto(const string& nombre, const string& marca, int precio, int descuento, int inventario);

private:
    string nombre;
    string marca;
    int precio;
    int descuento;
    int inventario;
};

#endif // PRODUCTO_H
