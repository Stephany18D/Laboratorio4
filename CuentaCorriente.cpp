#include "CuentaCorriente.h"
#include <iostream>
using namespace std;

CuentaCorriente::CuentaCorriente() : saldo(0.0) {}

CuentaCorriente::CuentaCorriente(const string& nombre, const string& apellidos, const string& direccion, const string& telefono, const string& numeroIdentificacion, const string& clave, double saldo)
    : nombre(nombre), apellidos(apellidos), direccion(direccion), telefono(telefono), numeroIdentificacion(numeroIdentificacion), clave(clave), saldo(saldo) {}

void CuentaCorriente::setNombre(const string& nombre) { this->nombre = nombre; }
string CuentaCorriente::getNombre() const { return nombre; }

void CuentaCorriente::setApellidos(const string& apellidos) { this->apellidos = apellidos; }
string CuentaCorriente::getApellidos() const { return apellidos; }

void CuentaCorriente::setDireccion(const string& direccion) { this->direccion = direccion; }
string CuentaCorriente::getDireccion() const { return direccion; }

void CuentaCorriente::setTelefono(const string& telefono) { this->telefono = telefono; }
string CuentaCorriente::getTelefono() const { return telefono; }

void CuentaCorriente::setNumeroIdentificacion(const string& numeroIdentificacion) { this->numeroIdentificacion = numeroIdentificacion; }
string CuentaCorriente::getNumeroIdentificacion() const { return numeroIdentificacion; }

void CuentaCorriente::setClave(const string& clave) { this->clave = clave; }
string CuentaCorriente::getClave() const { return clave; }

void CuentaCorriente::setSaldo(double saldo) { this->saldo = saldo; }
double CuentaCorriente::getSaldo() const { return saldo; }

void CuentaCorriente::retirarDinero(double cantidad) {
    if (cantidad <= saldo) {
        saldo -= cantidad;
    } else {
        cout << "Saldo insuficiente.\n";
    }
}

void CuentaCorriente::ingresarDinero(double cantidad) {
    saldo += cantidad;
}

void CuentaCorriente::consultarCuenta() {
    cout << "Nombre: " << nombre << "\n";
    cout << "Apellidos: " << apellidos << "\n";
    cout << "Direccion: " << direccion << "\n";
    cout << "Teléfono: " << telefono << "\n";
    cout << "Saldo: " << saldo << "\n";
}

bool CuentaCorriente::saldoNegativo() {
    return saldo < 0;
}
