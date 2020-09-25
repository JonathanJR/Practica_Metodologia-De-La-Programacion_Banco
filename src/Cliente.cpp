#include "Cliente.h"
#include <cstring>

Cliente::Cliente(char *dni, char *nombre, Fecha f):fechaAlta(f)
{
    this->dni=new char[strlen(dni)+1];
    strcpy(this->dni, dni);

    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

Cliente::~Cliente()
{
    delete [] this->dni;
    delete [] this->nombre;
}

Cliente::Cliente(const Cliente& other):fechaAlta(other.fechaAlta)
{
    this->dni=new char[strlen(other.dni)+1];
    strcpy(this->dni, other.dni);

    this->nombre=new char[strlen(other.nombre)+1];
    strcpy(this->nombre, other.nombre);
}

Cliente& Cliente::operator=(const Cliente& rhs)
{
    if (this != &rhs)
    {
        delete [] this->dni;
        this->dni=new char[strlen(rhs.dni)+1];
        strcpy(this->dni, rhs.dni);

        delete [] this->nombre;
        this->nombre=new char[strlen(rhs.nombre)+1];
        strcpy(this->nombre, rhs.nombre);
    }
    return *this;
}

void Cliente::setNombre(char *nombre)
{
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cliente::setFecha(Fecha f)
{
    this->fechaAlta = f;
}

string Cliente::cadena() const
{
    string cadena;
    cadena = this->nombre + (string)" -> Alta: " + this->fechaAlta.cadena() ;
    return cadena;
}

ostream& operator<<(ostream &s, const Cliente &f)
{
    s << f.nombre << " (" << f.dni << " - " << f.fechaAlta << ")";
    return s;
}
