#include <cstring>
#include <sstream> //stringstream
#include "CuentaAhorro.h"

using namespace std;

CuentaAhorro::CuentaAhorro(char *dni, Fecha f, float saldo, float interes)
    :Cuenta(dni, f, saldo)
{
    this->interes=interes;
}

CuentaAhorro& CuentaAhorro::operator=(const CuentaAhorro& rhs)
{
    if (this != &rhs)
    {
        ;
    }
    return *this;
}

void CuentaAhorro::generarIntereses()
{
    float interes = (this->getSaldo()*this->interes)/100;
    if (interes > 0.2)
        this->setSaldo(this->getSaldo() + interes);
}

string CuentaAhorro::cadena() const
{
    stringstream s;
    s << Cuenta::cadena() << ", " << this->interes << "%";
    return s.str();
}

ostream& operator<<(ostream &s, const CuentaAhorro &f)
{
    s << f.getDni() << " (" << f.getN() << " - " << f.getFechaApertura().cadena() << ") " << f.getSaldo () << " euros, " << f.interes << "%";
    return s;
}
