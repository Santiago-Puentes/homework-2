#pragma once
#include "bankAccount.hpp"
#include "cajaDeAhorro.hpp"

class CuentaCorriente : public BankAccount {
private:
    // Este atributo es privado porque es un detalle de implementación interno.
    // No debe ser accesible desde fuera para mantener la encapsulación.
    CajaDeAhorro* cajaDeAhorro;

public:
    // Constructor público para permitir la creación de objetos desde fuera de la clase.
    CuentaCorriente(double initialBalance, const string& titular, CajaDeAhorro* caja)
        : BankAccount(initialBalance, titular), cajaDeAhorro(caja) {}

    // Método público para permitir que se realicen retiros desde fuera de la clase.
    void retirar(double cantidad) override {
        if (cantidad <= balance) {
            balance -= cantidad;
        } else if (cajaDeAhorro && cantidad <= (balance + cajaDeAhorro->getBalance())) {
            double restante = cantidad - balance;
            balance = 0;
            cajaDeAhorro->retirar(restante);
        } else {
            cout << "La cuenta no posee dinero suficiente." << endl;
        }
    }

    // Método público para mostrar información de la cuenta.
    void mostrarInfo() override {
        cout << "Tipo de cuenta: Cuenta Corriente\n";
        cout << "Titular: " << titularCuenta << "\n";
        cout << "Balance: $" << balance << "\n";
    }

    // Función amiga para verificar fondos.
    // Se utiliza para acceder a los atributos privados de la clase.
    friend void verificarFondos(const CuentaCorriente& cuenta);
};

inline void verificarFondos(const CuentaCorriente& cuenta) {
    if (cuenta.balance <= 0) {
        cout << "La cuenta corriente no tiene fondos." << endl;
    }
}