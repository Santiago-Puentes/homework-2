#pragma once
#include "numero.hpp"

class Complejo : public Numero {
private:
    double real;
    double imaginario;

public:
    Complejo(double r, double i);
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    string toString() const override;
};