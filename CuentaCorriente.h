#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include <string>
using namespace std;

class CuentaCorriente {
public:
    CuentaCorriente();
    CuentaCorriente(const string& nombre, const string& apellidos, const string& direccion, const string& telefono, const string& numeroIdentificacion, const string& clave, double saldo);

    void setNombre(const string& nombre);
    string getNombre() const;
    void setApellidos(const string& apellidos);
    string getApellidos() const;
    void setDireccion(const string& direccion);
    string getDireccion() const;
    void setTelefono(const string& telefono);
    string getTelefono() const;
    void setNumeroIdentificacion(const string& numeroIdentificacion);
    string getNumeroIdentificacion() const;
    void setClave(const string& clave);
    string getClave() const;
    void setSaldo(double saldo);
    double getSaldo() const;

    void retirarDinero(double cantidad);
    void ingresarDinero(double cantidad);
    void consultarCuenta();
    bool saldoNegativo();

private:
    string nombre;
    string apellidos;
    string direccion;
    string telefono;
    string numeroIdentificacion;
    string clave;
    double saldo;
};

#endif // CUENTACORRIENTE_H
