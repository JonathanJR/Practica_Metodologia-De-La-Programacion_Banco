#include <iostream> //cin, cout
#include <string.h>
#include <string> //getline() para leer frases y guardarlas en un tipo string
#include <sstream> //stringstream
#include <typeinfo> //typeid
#include <stdio.h> //gets() para leer frases
#include "Banco.h"

using namespace std;

Banco::Banco()
{
    this->clientes=new Cliente *[3]; //capacidad inicial 3 clientes
    this->ncli=0;
    this->nmaxcli=3;

    this->cuentas=new Cuenta*[7]; //capacidad inicial 7 cuentas
    this->ncu=0;
    this->nmaxcu=7;
}

Banco::~Banco()
{
    for(int i=0; i<this->ncli; i++)
        delete this->clientes[i];
    delete [] this->clientes;

    for(int i=0; i<this->ncu; i++)
        delete this->cuentas[i];
    delete [] this->cuentas;
}

//ESTE METODO LO HE PUESTO PARA TENER INFORMACION YA CARGADA Y NO TENER QUE TECLEARLA...
//Cuando la clase CuentaAhorro este implementada las lineas que estan comentadas se deben
//descomentar para que se creen 3 Cuentas de Ahorro cuyas direcciones esten almacenadas
//en los puntero existentes en las posiciones 2, 3 y 6
void Banco::cargarDatos()
{
    //el metodo cargarDatos crea 3 clientes y 7 cuentas en total

    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
    this->clientes[0] = new Cliente("75547001H", "Susana Diaz", f1);
    this->clientes[1] = new Cliente("75547001B", "Juan Perez", Fecha(29,2,2000));
    this->clientes[2] = new Cliente("37000017X", "Luis Bono", f2);
    this->ncli=3;

    this->cuentas[0] = new CuentaCorriente("75547001H", f1, 0, 5); //saldo: 0Ђ, comisiуn: 5Ђ exenta si saldo>500Ђ
    this->cuentas[1] = new CuentaCorriente("75547001B", f3, 50, 4); //saldo 50Ђ, comisiуn: 4Ђ exenta si saldo>500Ђ
    this->cuentas[2] = new CuentaAhorro("37000017X", f3, 40, 0.25); //saldo: 40Ђ, interйs: 0.25%
    this->cuentas[3] = new CuentaAhorro("75547001H", Fecha(3,3,2003), 800, 1.5); //saldo: 800Ђ, interйs: 1.50%
    this->cuentas[4] = new CuentaCorriente("75547001H", f2, 100, 4); //saldo: 100Ђ, comisiуn: 4Ђ exenta si saldo>500Ђ
    this->cuentas[5] = new CuentaCorriente("75547001B", f2, 300, 3); //saldo 300Ђ, comisiуn: 3Ђ exenta si saldo>500Ђ
    this->cuentas[6] = new CuentaAhorro("75547001B", f3, 400, 0.75); //saldo: 400Ђ, interйs: 0.75%
    this->ncu=7;
}
/*
bool Banco::cancelarCuenta(int nCuenta)
{
    bool ok = false;

    for(int i=0; i<this->ncu; i++)
    {
        if (cuentas[i]->getN() == nCuenta)
        {
            this->cuentas[i] = this->cuentas[i+1];
            ok = true;
            this->ncu--;
        }
    }
    return ok;
}*/

bool Banco::cancelarCuenta(int nCuenta)
{
    bool ok = false;
    int i=0;
    while (i<this->ncu){
        if (cuentas[i]->getN() == nCuenta)
        {
            delete this->cuentas[i];
            for(int j=i+1; j<this->ncu; j++)
                this->cuentas[j-1]=this->cuentas[j];
            ok = true;
            this->ncu--;
        } else
            i++;
    }
    return ok;
}

/*
bool Banco::cancelarCuentaPorDni(char * dni)
{
    bool ok = false;

    for(int i=0; i<this->ncu; i++)
    {
        if (strcmp(cuentas [i]->getDni(), dni) == 0)
        {
            this->cuentas[i] = this->cuentas[i+1];
            ok = true;
            this->ncu--;
        }
    }
    return ok;
}*/

bool Banco::cancelarCuentaPorDni(char * dni)
{
    bool ok = false;
    int i=0;
    while (i<this->ncu){
        if (strcmp(cuentas [i]->getDni(), dni) == 0)
        {
            for(int j=i+1; j<this->ncu; j++)
                this->cuentas[j-1]=this->cuentas[j];
            ok = true;
            this->ncu--;
        } else
            i++;
    }
    return ok;
}

/*
bool Banco::bajaCliente(char *dni)
{
    bool ok = false;

    for(int i=0; i<this->ncli; i++)
    {
        if (strcmp(clientes [i]->getDni(), dni) == 0)
        {
            this->clientes[i] = this->clientes[i+1];
            cancelarCuentaPorDni (this->clientes[i]->getDni());
            ok = true;
            this->ncli--;
        }
    }
    return ok;
}*/

bool Banco::bajaCliente(char *dni)
{
    bool ok = false;
    int i=0;
    while (i<this->ncli){
        if (strcmp(clientes [i]->getDni(), dni) == 0)
        {
            cancelarCuentaPorDni (this->clientes[i]->getDni());
            delete this->clientes[i];
            for(int j=i+1; j<this->ncli; j++)
                this->clientes[j-1]=this->clientes[j];
            ok = true;
            this->ncli--;
        } else
            i++;
    }
    return ok;
}

int Banco::nCuentasAhorro()
{
    int contador = 0;
    for(int i=0; i<this->ncu; i++)
    {
        if(typeid(*cuentas[i])==typeid(CuentaAhorro))
            contador++;
    }
    return contador;
}

/*
void Banco::rebajarComision(float porcentaje)
{
    for(int i=0; i<this->ncu; i++)
    {
        Cuenta *c = cuentas [i];
        CuentaCorriente *cuenta = dynamic_cast<CuentaCorriente*> (c);
        cuenta->setComision(cuenta->getComision() * ((100 - porcentaje)/100));
        cuentas [i] = cuenta;
    }
}*/

void Banco::rebajarComision(float porcentaje)
{
    for(int i=0; i<this->ncu; i++)
    {
        Cuenta *c = cuentas [i];
        if(CuentaCorriente *cuenta = dynamic_cast<CuentaCorriente*> (c)){
            cuenta->setComision(cuenta->getComision() * ((100 - porcentaje)/100));
            cuentas [i] = cuenta;
        } else
            ;
    }
}

void Banco::abrirCuenta()
{
    char dni[15];
    int pos, tipo, dia, mes, anio;
    float saldo;
    Cuenta *cuenta;
    cout << "Dni: ";
    cin >> dni;
    pos=this->buscarCliente(dni); //-1 si no existe y la posicion donde esta si existe
    if (pos==-1)   //es un cliente nuevo y hay que darlo de alta
    {
        char nombre[30];
        //pedir los datos del cliente
        cout << "Nombre: ";
        //cin >> nombre;  //NO SIRVE SI EL NOMBRE ES COMPUESTO
        cin.ignore(); //el cin al leer una palabra no consume el \n y con ignore() lo consumimos
        //antes de un gets lo debemos poner por si acaso...
        gets(nombre); //para leer frases o nombres con apellidos (palabras con espacios)
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Aсo: ";
        cin >> anio;
        Cliente *c=new Cliente(dni, nombre, Fecha(dia,mes,anio));
        this->agregarCliente(c); //lo aсade a la tabla clientes
    }
    do
    {
        cout << "Tipo de cuenta a abrir (1-Corriente, 2-Ahorro): ";
        cin >> tipo;
    }
    while (tipo!=1 && tipo!=2);   //hasta que no pulse 1 o 2 no deja de preguntar...
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Aсo: ";
    cin >> anio;
    cout << "Saldo inicial: ";
    cin >> saldo;
    if (tipo==1)   //Cuenta Corriente
    {
        float comision;
        cout << "Comision: ";
        cin >> comision;
        cuenta=new CuentaCorriente(dni, Fecha(dia,mes,anio), saldo, comision);
    }
    else if (tipo==2)   //Cuenta Ahorro
    {
        float interes;
        cout << "Interes: ";
        cin >> interes;
        cuenta=new CuentaAhorro(dni, Fecha(dia,mes,anio), saldo, interes);
    }
    //aсadir la cuenta creada al array cuentas
    this->abrirCuenta(cuenta); //ESTE METODO HAY QUE IMPLEMENTARLO...
    //this->cuentas[this->ncu]=cuenta;
    //this->ncu++;
}

void Banco::abrirCuenta(Cuenta *c)
{
    if (this->ncu==this->nmaxcu)   //la tabla esta llena
    {
        Cuenta **aux;
        aux=this->cuentas;
        this->nmaxcu*=2; //duplico la capacidad
        this->cuentas=new Cuenta *[this->nmaxcu]; //creo una nueva tabla
        for(int i=0; i<this->ncu; i++)   //copio los datos de la tabla antigua a la nueva
        {
            this->cuentas[i]=aux[i];
        }
        delete [] aux; //libero la memoria de la tabla antigua
    }
    this->cuentas[this->ncu]=c; //metemos c en la posicion ncu
    this->ncu++; //incrementamos el contador ncu (para que el proximo cliente se meta en la siguiente posicion)
}

void Banco::agregarCliente(Cliente *c)
{
    if (this->ncli==this->nmaxcli)   //la tabla esta llena
    {
        Cliente **aux;
        aux=this->clientes;
        this->nmaxcli*=2; //duplico la capacidad
        this->clientes=new Cliente *[this->nmaxcli]; //creo una nueva tabla
        for(int i=0; i<this->ncli; i++)   //copio los datos de la tabla antigua a la nueva
        {
            this->clientes[i]=aux[i];
        }
        delete [] aux; //libero la memoria de la tabla antigua
    }
    this->clientes[this->ncli]=c; //metemos c en la posicion ncli
    this->ncli++; //incrementamos el contador ncli (para que el proximo cliente se meta en la siguiente posicion)
}

int Banco::buscarCliente(char *dni) const   //-1 si no existe o la posicion do
{
    int i=0, pos;
    bool encontrado=false;
    while(i<this->ncli && encontrado==false)
    {
        if (strcmp(this->clientes[i]->getDni(), dni) == 0)
            encontrado=true;
        else
            i++;
    }
    if (encontrado)
        pos=i;
    else
        pos=-1;
    return pos;
}

//ESTE METODO LO HE IMPLEMENTADO PARA VER EL CONTENIDO DEL BANCO
void Banco::ver() const
{
    cout << "El banco tiene " << this->ncli << " clientes y " << this->ncu << " cuentas\n";
    cout << "Clientes: \n";
    for(int i=0; i<this->ncli; i++)
    {
        cout << *this->clientes[i] << endl; //ejecuto el operator<< de la clase cliente
    }
    cout << "Cuentas: \n";
    for(int i=0; i<this->ncu; i++)
    {
        cout << this->cuentas[i]->cadena() << endl;
    }
}

