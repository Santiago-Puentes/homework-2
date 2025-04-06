#pragma once
#include "bankAccount.hpp"

class CajaDeAhorro : public BankAccount {
private:
    // Este atributo es privado porque su propósito es interno a la clase.
    // No debe ser accesible desde fuera para evitar manipulaciones no controladas.
    int mostrarInfoCount;

public:
    // Constructor público para permitir la creación de objetos desde fuera de la clase.
    CajaDeAhorro(double initialBalance, const string& titular)
        : BankAccount(initialBalance, titular), mostrarInfoCount(0) {}

    // Método público para permitir que se realicen retiros desde fuera de la clase.
    // Sobrescribe el método virtual de la clase base.
    void retirar(double cantidad) override {
        if (cantidad <= balance) {
            balance -= cantidad;
        } else {
            cout << "Fondos insuficientes en la caja de ahorro." << endl;
        }
    }

    // Método público para mostrar información de la cuenta.
    // Sobrescribe el método virtual de la clase base.
    void mostrarInfo() override {
        cout << "Tipo de cuenta: Caja de Ahorro\n";
        cout << "Titular: " << titularCuenta << "\n";
        cout << "Balance: $" << balance << "\n";
        mostrarInfoCount++;
        if (mostrarInfoCount > 2) {
            balance -= 20;
            cout << "Se descontaron $20 por exceder el límite de consultas." << endl;
        }
    }
};