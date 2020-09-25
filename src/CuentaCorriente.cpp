#include <cstring>
#include <sstream> //stringstream
#include "CuentaCorriente.h"

using namespace std;

float CuentaCorriente::saldoMinimo=500;

CuentaCorriente::CuentaCorriente(char *dni, Fecha f, float saldo, float comision)
    :Cuenta(dni, f, saldo)
{
    this->comision=comision;
}

void CuentaCorriente::setSaldoMinimo(float s)
{
    if (s<100)
        s=100;
    CuentaCorriente::saldoMinimo=s;
}

void CuentaCorriente::cobrarComision()
{
    if (this->getSaldo() < saldoMinimo)
        this->setSaldo(this->getSaldo()-comision);
}

string CuentaCorriente::cadena() const
{
    stringstream s;
    s << Cuenta::cadena() << ", comision " << this->comision << " exento a partir de " << CuentaCorriente::saldoMinimo;
    return s.str();
}

ostream& operator<<(ostream &s, const CuentaCorriente &f)
{
    s << f.getDni() << " (" << f.getN() << " - " << f.getFechaApertura().cadena() << ") " << f.getSaldo ()
      << " euros, comision " << f.comision << " exento a partir de " << CuentaCorriente::saldoMinimo;
    return s;
}
