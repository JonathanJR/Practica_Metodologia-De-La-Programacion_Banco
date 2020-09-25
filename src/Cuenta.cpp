#include "Cuenta.h"
#include <cstring>

using namespace std;

int Cuenta::n=1;

Cuenta::Cuenta(char *dni, Fecha f, float saldo): numeroCuenta(n), fechaApertura(f)
{
    this->dni=new char[strlen(dni)+1];
    strcpy(this->dni, dni);

    this->saldo=saldo;
    Cuenta::n++;
}

Cuenta::~Cuenta()
{
    delete [] this->dni;
}

Cuenta::Cuenta(const Cuenta& other):numeroCuenta(n),fechaApertura(other.fechaApertura),saldo(other.saldo), dni (other.dni)
{
    Cuenta::n++;
}

Cuenta& Cuenta::operator=(const Cuenta& rhs)
{
    if (this != &rhs)
    {
        delete [] this->dni;
        this->dni=new char[strlen(rhs.dni)+1];
        strcpy(this->dni, rhs.dni);
    }
    return *this;
}

ostream& operator<<(ostream &s, const Cuenta &f)
{
    s << f.dni << " (" << f.numeroCuenta << " - " << f.fechaApertura.cadena() << ") " << f.saldo << " euros";
    return s;
}

string Cuenta::cadena() const{
    stringstream s;
    s << this->dni << " (" << this->numeroCuenta << " - "<< this->fechaApertura << ") " << this->saldo << " euros";
    return s.str();
}
