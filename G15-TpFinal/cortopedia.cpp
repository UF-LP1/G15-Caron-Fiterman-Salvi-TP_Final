#include "cortopedia.h"

cOrtopedia::cOrtopedia(string nombre, string direccion, list<cProtesis*> ListaProtesis): Nombre(nombre), Direccion(direccion)
{
    this->ListadoProtesis = ListaProtesis;
}

cOrtopedia::cOrtopedia(string nombre, string direccion): Nombre(nombre), Direccion(direccion)
{}
const string cOrtopedia::get_nombre(){
    return this->Nombre;
}

const string cOrtopedia::get_direccion(){
    return this->Direccion;
}

const list <cProtesis*> cOrtopedia::get_ListaProtesis(){
    return this->ListadoProtesis;
}

void cOrtopedia::set_ListaProtesis(list <cProtesis*> listaNueva){
    this->ListadoProtesis= listaNueva;
    return;
}

void cOrtopedia::operator+(cProtesis &ProtesisNueva){
    list<cProtesis*>::iterator it = this->ListadoProtesis.begin();
    bool encontrado = false;

    while(it != this->ListadoProtesis.end()){
        if(ProtesisNueva == *(*it)) //sobrecarga del ==
            encontrado = true; //ya existe ese paciente en la lista
        it++;
    }

    if(encontrado == false) //si la protesis no esta en la lista previamente, lo agrego
        this->ListadoProtesis.push_back(&ProtesisNueva);

    return;

}

void cOrtopedia::operator-(cProtesis &ProtesisBorrar){
    list<cProtesis*>::iterator it = this->ListadoProtesis.begin();
    bool encontrado = false;

    while(it != this->ListadoProtesis.end()){
        if(*(*it)==ProtesisBorrar){ //sobrecarga del ==
            encontrado = true;
            break;
        }

        it++;
    }

    if(encontrado == true)
        this->ListadoProtesis.erase(it);

    return;

}


const string cOrtopedia::ListarProtesis() const{
    list<cProtesis*>::const_iterator it = ListadoProtesis.begin();
    stringstream salidaLista;

    while (it != ListadoProtesis.end()) {
        salidaLista << *it <<endl; //sobrecarga <<
        it++;
    }

    return salidaLista.str();

}


const string cOrtopedia:: to_string(){
    stringstream salida;
    salida << "Nombre Ortopedia: " << this->Nombre <<endl
           << "Direccion: " << this->Direccion <<endl
           << "listado protesis: " << this->ListarProtesis()<<endl
           << "Stock Protesis Quirurgicas Superiores Izquierdas: " << cOrtopedia::StockSupIzqQ <<endl
           << "Stock Protesis Quirurgicas Superiores Derechas: " << cOrtopedia::StockSupDerQ<<endl
           << "Stock Protesis Quirurgicas Inferiores Izquierdas: " << cOrtopedia::StockInfIzqQ<<endl
           << "Stock Protesis Quirurgicas Inferiores Derechas: " << cOrtopedia::StockInfDerQ<<endl
           << "Stock Protesis No Quirurgicas Superiores Izquierdas: " << cOrtopedia::StockSupIzqNQ <<endl
           << "Stock Protesis No Quirurgicas Superiores Derechas: " << cOrtopedia::StockSupDerNQ<<endl
           << "Stock Protesis No Quirurgicas Inferiores Izquierdas: " << cOrtopedia::StockInfIzqNQ<<endl
           << "Stock Protesis No Quirurgicas Inferiores Derechas: " << cOrtopedia::StockInfDerNQ<<endl;

    return salida.str();
}

void cOrtopedia::imprimir(){
    cout << this->to_string() << endl;
    return;
}

cOrtopedia::~cOrtopedia(){}

//STATIC STOCK

unsigned int cOrtopedia::StockSupIzqQ = 10;
unsigned int cOrtopedia::StockSupDerQ = 18;
unsigned int cOrtopedia::StockInfIzqQ = 23;
unsigned int cOrtopedia::StockInfDerQ = 12;
unsigned int cOrtopedia::StockSupIzqNQ = 2;
unsigned int cOrtopedia::StockSupDerNQ = 1;
unsigned int cOrtopedia::StockInfIzqNQ = 0;
unsigned int cOrtopedia::StockInfDerNQ = 4;


//para aumentar: cOrtopedia::StockInfDerNQ++;
//para decrementar: cOrtopedia::StockInfDerNQ--;
