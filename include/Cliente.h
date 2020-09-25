#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string> //string
#include "Fecha.h"

using namespace std;

class Cliente
{
        char *dni;
        char *nombre;
        Fecha fechaAlta;
    public:
        Cliente(char *dni, char *nombre, Fecha f);

        virtual ~Cliente();
        Cliente(const Cliente& other);
        Cliente& operator=(const Cliente& other);

        const char *getNombre() const { return this->nombre; }
        Fecha getFecha() const { return this->fechaAlta; }
        char* getDni() const { return this->dni; }
        void setNombre(char *nombre);
        void setFecha(Fecha f);
        string cadena() const;

    friend ostream &operator<<(ostream &s, const Cliente &f);
};

#endif // CLIENTE_H

