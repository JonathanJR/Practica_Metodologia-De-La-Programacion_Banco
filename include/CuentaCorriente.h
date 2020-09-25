#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include <Cuenta.h>


class CuentaCorriente : public Cuenta {
    float comision;
    static float saldoMinimo;
    public:
        CuentaCorriente(char *dni, Fecha f, float saldo, float comision);

        static float getSaldoMinimo() { return saldoMinimo; }
        static void setSaldoMinimo(float s);

        void cobrarComision();
        float getComision (){return comision;}
        void setComision(float nuevacomision) { comision=nuevacomision; }
        string cadena() const;

    //operator<< //HAY QUE IMPLEMENTARLO
    friend ostream &operator<<(ostream &s, const CuentaCorriente &f);

    //(Clase cuenta abstracta) - No queremos que cuentacorriente tambien lo sea
    //virtual void nada() const{;}
};

#endif // CUENTACORRIENTE_H
