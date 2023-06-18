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


//FALTAN LOS STATIC STOCK!!
