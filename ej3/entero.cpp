#include "entero.hpp"
#include <sstream>

Entero::Entero(int v) : valor(v) {}

Numero* Entero::suma(const Numero& otro) const {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(valor + e.valor);
}

Numero* Entero::resta(const Numero& otro) const {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(valor - e.valor);
}

Numero* Entero::multiplicacion(const Numero& otro) const {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(valor * e.valor);
}

string Entero::toString() const {
    ostringstream oss;
    oss << valor;
    return oss.str();
}