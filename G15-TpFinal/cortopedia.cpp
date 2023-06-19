#include "cortopedia.h"

cOrtopedia::cOrtopedia(string nombre, string direccion, list<cProtesis*> ListaProtesis): Nombre(nombre), Direccion(direccion)
{
    this->ListadoProtesis = ListaProtesis;
}

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

const string cOrtopedia:: to_string(){
    //HACER CODIGO
}

void cOrtopedia::imprimir(){
     //HACER CODIGO
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
