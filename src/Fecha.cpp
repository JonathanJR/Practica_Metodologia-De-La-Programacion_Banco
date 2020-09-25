#include "Fecha.h"
#include <sstream> //stringstream

Fecha::Fecha(int d, int m, int a) {
    this->setFecha(d, m, a);
}

bool Fecha::bisiesto() const {
    if (this->anio%4==0 && (this->anio%100 !=0 || this->anio%400 ==0))
        return true;
    else
        return false;
}

void Fecha::setFecha(int d, int m, int a) {
    int diaMes[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    this->anio=a; //MUY IMPORTANTE, poner el año antes de llamar a bisiesto

    if (this->bisiesto())
        diaMes[2]=29;

    if (m<1)
        m=1;
    else if (m>12)
        m=12;
    this->mes=m;

    if (d<1)
        d=1;
    else if (d>diaMes[m])
        d=diaMes[m];
    this->dia=d;
}

string Fecha::cadena() const {
    string meses[]={" ", "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic" };
    stringstream s;
    s << this->dia << "/" << this->mes << "/" << this->anio;
    return s.str();
}

ostream &operator<<(ostream &s, const Fecha &f) {
    if (f.dia<10)
        s << "0";
    s << f.dia << "/";
    if (f.mes<10)
        s << "0";
    s << f.mes << "/" << f.anio;
    return s;
}
