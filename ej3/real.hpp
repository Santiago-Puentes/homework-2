#pragma once
#include "numero.hpp"

class Real : public Numero {
private:
    double valor;

public:
    Real(double v);
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    string toString() const override;
};