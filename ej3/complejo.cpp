#include "complejo.hpp"
#include <sstream>

Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

Numero* Complejo::suma(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return new Complejo(real + c.real, imaginario + c.imaginario);
}

Numero* Complejo::resta(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return new Complejo(real - c.real, imaginario - c.imaginario);
}

Numero* Complejo::multiplicacion(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    double nuevoReal = (real * c.real) - (imaginario * c.imaginario);
    double nuevoImaginario = (real * c.imaginario) + (imaginario * c.real);
    return new Complejo(nuevoReal, nuevoImaginario);
}

string Complejo::toString() const {
    ostringstream oss;
    oss << real << (imaginario >= 0 ? "+" : "") << imaginario << "i";
    return oss.str();
}