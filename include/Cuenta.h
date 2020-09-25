#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <sstream> //stringstream
#include <string> //string
#include "Fecha.h"

using namespace std;

class Cuenta
{
        static int n;
        const int numeroCuenta;
        char *dni;
        Fecha fechaApertura;
        float saldo;
    public:
        Cuenta(char *dni, Fecha f, float saldo);
        virtual ~Cuenta();
        Cuenta(const Cuenta& other);
        Cuenta& operator=(const Cuenta& other);

        void ingreso(float c) { this->saldo+=c; }
        void retirada(float c) { this->saldo-=c; }
        float getSaldo() const { return this->saldo; }
        Fecha getFechaApertura() const { return this->fechaApertura; }
        char* getDni() const { return this->dni; }
        int getN () const {return this->numeroCuenta;}
        void setSaldo(float s) { saldo=s; }

        virtual string cadena() const;

    friend ostream &operator<<(ostream &s, const Cuenta &f);
    //Para hacer la clase abstracta
    //virtual void nada() const=0;
};

#endif // CUENTA_H
