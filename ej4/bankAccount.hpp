#pragma once
#include <string>
#include <iostream>
using namespace std;

class BankAccount {
protected:
    // Este atributo es protected para que las subclases puedan acceder a él directamente.
    // Esto facilita la implementación de métodos específicos en las subclases.
    double balance;

    // Este atributo es protected para que las subclases puedan acceder a él directamente.
    string titularCuenta;

public:
    // Constructor público para permitir la creación de objetos desde fuera de la clase.
    BankAccount(double initialBalance, const string& titular)
        : balance(initialBalance), titularCuenta(titular) {}

    // Destructor virtual público para permitir la eliminación adecuada de objetos derivados.
    virtual ~BankAccount() = default;

    // Método público para permitir depósitos desde fuera de la clase.
    void depositar(double cantidad) {
        if (cantidad > 0) {
            balance += cantidad;
        }
    }

    // Métodos virtuales públicos para que las subclases los implementen.
    virtual void retirar(double cantidad) = 0;
    virtual void mostrarInfo() = 0;

    // Métodos públicos para obtener información de los atributos protegidos.
    // Esto mantiene la encapsulación al evitar el acceso directo desde fuera de la clase.
    double getBalance() const {
        return balance;
    }

    string getTitularCuenta() const {
        return titularCuenta;
    }
};