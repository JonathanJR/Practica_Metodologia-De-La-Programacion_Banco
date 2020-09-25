#include <cstdlib> //system("PAUSE")
#include <iostream>
#include "Fecha.h" //definicion de la clase Fecha
#include "Cuenta.h" // definicion de la clase Cuenta
#include "CuentaCorriente.h" // definicion de la clase CuentaCorriente
#include "CuentaAhorro.h" // definicion de la clase CuentaAhorro
#include "Banco.h" // definicion de la clase CuentaAhorro
#include <typeinfo>

using namespace std;

int main(int argc, char *argv[])
{
    /*
    //      PRUEBA2.CPP (Parte 1)
    Fecha f1(29,2,2001), f2(f1), f3(29,2,2004);
    cout << "Fechas:" << f1 << ", " << f2 << ", " << f3 << endl;
    Cuenta *p = new Cuenta("75547111M", f1, 0), c("23000111X", Fecha(2,2,2002), 1000);
    cout << CuentaCorriente::getSaldoMinimo() << endl;
    CuentaCorriente::setSaldoMinimo(75);
    CuentaCorriente cc1("17333256H", f1, 0, 5); //saldo: 0€, comisión: 5€ exenta si saldo>100€
    CuentaCorriente cc2("12555100F", f3, 50, 4); //saldo 50€, comisión: 4€ exenta si saldo>100
    CuentaCorriente cc3(cc1);
    CuentaAhorro ca1("17333256H", f1, 40, 0.25); //saldo: 40€, interés: 0.25%
    CuentaAhorro ca2("17000000J", Fecha(3,3,2003), 800, 1.5); //saldo: 800€, interés: 1.50%
    CuentaAhorro ca3(ca2);
    p->ingreso(50);
    c.retirada(300);
    cc1.ingreso(350);
    ca2.retirada(200);
    cout << "suma saldos p, cc1 y ca1: " << p->getSaldo()+cc1.getSaldo() +ca1.getSaldo() << endl;
    cc1.setComision(7);
    //ca2.setInteres(2.00); //el tipo de interés no se puede modificar
    cc1.cobrarComision();
    cc2.cobrarComision();
    ca1.generarIntereses();
    ca2.generarIntereses();
    cout << *p << "\n" << c << "\n" << cc1 << "\n" << cc2 << "\n" << ca1 << "\n" << ca2 <<"\n";
    cout << endl << p->cadena() << "\n" << c.cadena() << endl << cc3.cadena() << "\n" << ca3.cadena() << endl << endl;
    ca1=ca2;
    cc1=cc2;
    *p=c;
    cout << *p << "\n" << c << "\n" << cc1 << "\n" << cc2 << "\n" << ca1 << "\n" << ca2 <<"\n";

    //      PRUEBA2.CPP (Parte 2)
    Cuenta *t[4];
    t[0]=p;
    t[1]=&c;
    t[2]=&cc1;
    t[3]=&ca2;
    t[0]->ingreso(250);
    t[1]->retirada(100);
    t[2]->ingreso(100);
    t[3]->retirada(105);
    cout << "\n-- Datos de los clientes: -- \n";
    for(int i=0; i<4; i++)
        cout << t[i]->cadena() << endl;
    */

    /* Hacer abstracta la clase cuenta
        - Al hacer abstracta la clase cuenta el compilador da error cuando intento crear instancias de la clase Cuenta
        - Si Comento las lineas que dan error el programa me da error cuando lo lanzo, asi que no se que puede estar fallando
    */

    ///*      PRUEBA3.CPP
    cout << endl << "APLICACION BANCARIA\n" << endl;
    bool ok;
    Banco BBVA;
    BBVA.cargarDatos(); //crea 3 clientes y 7 cuentas. Este metodo ha sido creado para no BBVA.ver(); //tener que meter datos cada vez que pruebo el programa
    BBVA.ver();
    cout <<"El banco tiene " << BBVA.nCuentasAhorro() << " cuentas de Ahorro\n\n";
    BBVA.abrirCuenta(); //cuenta ahorro a 37000017X el 01/01/2017 con 100€ al 1%
    BBVA.abrirCuenta(); //cuenta corriente a 22330014G (pepe luis) el 2/2/2017 con 40€ y comision 3€
    ok=BBVA.cancelarCuenta(28); //esta cuenta no existe
    if (ok) cout << "La cuenta 28 ha sido cancelada\n";
    else cout << "La cuenta 28 no existe\n";
    ok=BBVA.cancelarCuenta(4); //esta cuenta si existe
    if (ok)
        cout << "La cuenta 4 ha sido cancelada\n";
    else
        cout << "La cuenta 4 no existe\n";
    ok=BBVA.bajaCliente("75547001B"); //debe eliminar el cliente y sus 3 cuentas
    if (ok) cout << "El cliente 75547001B y sus cuentas han sido canceladas\n";
    else cout << "El cliente 75547001B no existe\n";
    BBVA.ver();
    BBVA.rebajarComision(40);
    cout << "\nTras rebajar un 40% la comision de las cuentas de ahorro...";
    BBVA.ver();
    cout <<"El banco tiene " << BBVA.nCuentasAhorro() << " cuentas de Ahorro\n";
    //*/

    system("PAUSE");
    return 0;
}
