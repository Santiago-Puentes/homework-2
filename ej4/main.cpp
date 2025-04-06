#include "cajaDeAhorro.hpp"
#include "cuentaCorriente.hpp"

int main() {
    CajaDeAhorro caja(500, "Juan Perez");
    CuentaCorriente cuenta(300, "Juan Perez", &caja);

    cout << "--- Caja de Ahorro ---" << endl;
    caja.mostrarInfo();
    cout << "\ndeposito $200" << endl;
    caja.depositar(200);
    caja.mostrarInfo();
    cout << "\nretiro $100" << endl;
    caja.retirar(100);
    caja.mostrarInfo();
    cout << "\nretiro $700" << endl;
    caja.retirar(700);
    caja.mostrarInfo();
    caja.mostrarInfo();
    caja.mostrarInfo();

    cout << "\n--- Cuenta Corriente ---" << endl;
    cuenta.mostrarInfo();
    cout << "\nretiro $400" << endl;
    cuenta.retirar(400);
    cuenta.mostrarInfo();
    cout << "\nretiro $500" << endl;
    cuenta.retirar(500); 
    cuenta.mostrarInfo();
    cout << "\nretiro $1000" << endl;
    cuenta.retirar(1000); 
    cuenta.mostrarInfo();

    verificarFondos(cuenta); 

    return 0;
}