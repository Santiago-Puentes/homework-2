#include "real.hpp"
#include "entero.hpp"
#include "complejo.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    // Pruebas con Entero
    unique_ptr<Numero> entero1 = make_unique<Entero>(5);
    unique_ptr<Numero> entero2 = make_unique<Entero>(-3);

    cout << "Entero 1: " << entero1->toString() << endl;
    cout << "Entero 2: " << entero2->toString() << endl;

    unique_ptr<Numero> sumaEnteros = unique_ptr<Numero>(entero1->suma(*entero2));
    cout << "Suma de enteros: " << sumaEnteros->toString() << endl;

    unique_ptr<Numero> restaEnteros = unique_ptr<Numero>(entero1->resta(*entero2));
    cout << "Resta de enteros: " << restaEnteros->toString() << endl;

    unique_ptr<Numero> multiplicacionEnteros = unique_ptr<Numero>(entero1->multiplicacion(*entero2));
    cout << "Multiplicación de enteros: " << multiplicacionEnteros->toString() << endl;

    // Pruebas con Real
    unique_ptr<Numero> real1 = make_unique<Real>(5.5);
    unique_ptr<Numero> real2 = make_unique<Real>(-3.3);

    cout << "Real 1: " << real1->toString() << endl;
    cout << "Real 2: " << real2->toString() << endl;

    unique_ptr<Numero> sumaReales = unique_ptr<Numero>(real1->suma(*real2));
    cout << "Suma de reales: " << sumaReales->toString() << endl;

    unique_ptr<Numero> restaReales = unique_ptr<Numero>(real1->resta(*real2));
    cout << "Resta de reales: " << restaReales->toString() << endl;

    unique_ptr<Numero> multiplicacionReales = unique_ptr<Numero>(real1->multiplicacion(*real2));
    cout << "Multiplicación de reales: " << multiplicacionReales->toString() << endl;

    // Pruebas con Complejo
    unique_ptr<Numero> complejo1 = make_unique<Complejo>(2.0, 3.0);
    unique_ptr<Numero> complejo2 = make_unique<Complejo>(-1.0, 4.0);

    cout << "Complejo 1: " << complejo1->toString() << endl;
    cout << "Complejo 2: " << complejo2->toString() << endl;

    unique_ptr<Numero> sumaComplejos = unique_ptr<Numero>(complejo1->suma(*complejo2));
    cout << "Suma de complejos: " << sumaComplejos->toString() << endl;

    unique_ptr<Numero> restaComplejos = unique_ptr<Numero>(complejo1->resta(*complejo2));
    cout << "Resta de complejos: " << restaComplejos->toString() << endl;

    unique_ptr<Numero> multiplicacionComplejos = unique_ptr<Numero>(complejo1->multiplicacion(*complejo2));
    cout << "Multiplicación de complejos: " << multiplicacionComplejos->toString() << endl;

    // Pruebas de casos borde
    unique_ptr<Numero> enteroCero = make_unique<Entero>(0);
    unique_ptr<Numero> realCero = make_unique<Real>(0.0);
    unique_ptr<Numero> complejoCero = make_unique<Complejo>(0.0, 0.0);

    cout << "Entero cero: " << enteroCero->toString() << endl;
    cout << "Real cero: " << realCero->toString() << endl;
    cout << "Complejo cero: " << complejoCero->toString() << endl;

    unique_ptr<Numero> sumaCero = unique_ptr<Numero>(enteroCero->suma(*realCero));
    cout << "Suma de entero cero y real cero: " << sumaCero->toString() << endl;

    unique_ptr<Numero> sumaComplejoCero = unique_ptr<Numero>(complejoCero->suma(*complejoCero));
    cout << "Suma de complejos cero: " << sumaComplejoCero->toString() << endl;


    return 0;
}