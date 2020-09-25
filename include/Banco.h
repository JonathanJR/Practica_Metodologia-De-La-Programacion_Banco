#ifndef BANCO_H
#define BANCO_H

#include "Fecha.h"
#include "Cliente.h"
#include "Cuenta.h"
#include "CuentaCorriente.h"
#include "CuentaAhorro.h"

using namespace std;

class Banco {
        Cliente **clientes; //array dinбmico de punteros a Clientes
        int ncli; //para saber cuantos clientes hay en el array (al principio 0)
        int nmaxcli; //para saber cuantos caben en el array clientes
        Cuenta **cuentas; //array dinбmico de punteros a Cuentas
        int ncu; //para saber cuantas cuentas hay en el array (al principio 0)
        int nmaxcu; //para saber cuantos caben en el array cuentas
    public:
        Banco();
        virtual ~Banco();

        //ESTE METODO LO HE PUESTO PARA TENER INFORMACION YA CARGADA Y NO TENER QUE TECLEARLA...
        void cargarDatos();

        void abrirCuenta();
        bool cancelarCuenta(int numeroCuenta); //true si la cuenta existe, false si no
        bool cancelarCuentaPorDni(char *dni); //true si la cuenta existe, false si no
        bool bajaCliente(char *dni); //true si el cliente existe, false si no
        void rebajarComision(float porcentaje);
        int nCuentasAhorro();

        //metodos auxiliares que creamos por nuestra cuenta
        int buscarCliente(char *dni) const; //-1 si no existe o la posicion donde esta
        void agregarCliente(Cliente *c);
        void abrirCuenta(Cuenta *c);

        //ESTE METODO LO HE IMPLEMENTADO PARA VER EL CONTENIDO DEL BANCO
        void ver() const;
};

#endif // BANCO_H
