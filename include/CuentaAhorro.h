#ifndef CUENTAAHORRO_H
#define CUENTAAHORRO_H

#include <Cuenta.h>


class CuentaAhorro : public Cuenta {
    float interes;

    public:
        CuentaAhorro(char *dni, Fecha f, float saldo, float interes);

        void generarIntereses();
        string cadena() const;

    CuentaAhorro& operator=(const CuentaAhorro& other);
    friend ostream &operator<<(ostream &s, const CuentaAhorro &f);

    //(Clase cuenta abstracta) - No que queremos que cuentaahorro tambien lo sea
    //virtual void nada() const{;}
};

#endif // CUENTACORRIENTE_H
