#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string> //string

using namespace std;

class Fecha
{
    int dia, mes, anio;
public:
    Fecha(int d, int m, int a);

    int getDia() const{return this->dia;}
    int getMes() const{return this->mes;}
    int getAnio() const{return this->anio;}

    void setFecha(int d, int m, int a);
    bool bisiesto() const;

    string cadena() const;

    friend ostream &operator<<(ostream &s, const Fecha &f);
};

#endif // FECHA_H
