#include "real.hpp"
#include <sstream>

Real::Real(double v) : valor(v) {}

Numero* Real::suma(const Numero& otro) const {
    const Real& r = dynamic_cast<const Real&>(otro);
    return new Real(valor + r.valor);
}

Numero* Real::resta(const Numero& otro) const {
    const Real& r = dynamic_cast<const Real&>(otro);
    return new Real(valor - r.valor);
}

Numero* Real::multiplicacion(const Numero& otro) const {
    const Real& r = dynamic_cast<const Real&>(otro);
    return new Real(valor * r.valor);
}

string Real::toString() const {
    ostringstream oss;
    oss << valor;
    return oss.str();
}