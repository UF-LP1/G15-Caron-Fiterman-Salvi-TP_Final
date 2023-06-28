#include "cortopedia.h"

cOrtopedia::cOrtopedia(string nombre, string direccion, list<cProtesis*> ListaProtesis): Nombre(nombre), Direccion(direccion)
{
    this->ListadoProtesis = ListaProtesis;
}

cOrtopedia::cOrtopedia(string nombre, string direccion): Nombre(nombre), Direccion(direccion)
{
    this->ListadoProtesis.clear();
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



const unsigned int cOrtopedia::get_StockSupIzqQ() const{
    return this->StockSupIzqQ;
}
void cOrtopedia::set_StockSupIzqQ(unsigned int StockSupIzqQ){
    this->StockSupIzqQ=StockSupIzqQ;
    return;
}
const unsigned int cOrtopedia::get_StockSupDerQ() const{
    return this->StockSupDerQ;
}
void cOrtopedia::set_StockSupDerQ(unsigned int StockSupDerQ){
    this->StockSupDerQ=StockSupDerQ;
    return;
}
const unsigned int cOrtopedia::get_StockInfIzqQ() const{
    return this->StockInfIzqQ;
}
void cOrtopedia::set_StockInfIzqQ(unsigned int StockInfIzqQ){
    this->StockInfIzqQ=StockInfIzqQ;
    return;
}
const unsigned int cOrtopedia::get_StockInfDerQ() const{
    return this->StockInfDerQ;
}
void cOrtopedia::set_StockInfDerQ(unsigned int StockInfDerQ){
    this->StockInfDerQ=StockInfDerQ;
    return;
}
const unsigned int cOrtopedia::get_StockSupIzqNQ() const{
    return this->StockSupIzqNQ;
}
void cOrtopedia::set_StockSupIzqNQ(unsigned int StockSupIzqNQ){
    this->StockSupIzqNQ=StockSupIzqNQ;
    return;
}
const unsigned int cOrtopedia::get_StockSupDerNQ() const{
    return this->StockSupDerNQ;
}
void cOrtopedia::set_StockSupDerNQ(unsigned int StockSupDerNQ){
    this->StockSupDerNQ=StockSupDerNQ;
    return;
}
const unsigned int cOrtopedia::get_StockInfIzqNQ() const{
    return this->StockInfIzqNQ;
}
void cOrtopedia::set_StockInfIzqNQ(unsigned int StockInfIzqNQ){
    this->StockInfIzqNQ=StockInfIzqNQ;
    return;
}
const unsigned int cOrtopedia::get_StockInfDerNQ() const{
    return this->StockInfDerNQ;
}
void cOrtopedia::set_StockInfDerNQ(unsigned int StockInfDerNQ){
    this->StockInfDerNQ=StockInfDerNQ;
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



const string cOrtopedia:: to_string(){
    list<cProtesis*>::const_iterator it = ListadoProtesis.begin();
    stringstream salida;
    salida << "Nombre Ortopedia: " << this->Nombre <<endl
           << "Direccion: " << this->Direccion <<endl
           << "Stock Protesis Quirurgicas Superiores Izquierdas: " << this->StockSupIzqQ <<endl
           << "Stock Protesis Quirurgicas Superiores Derechas: " << this->StockSupDerQ<<endl
           << "Stock Protesis Quirurgicas Inferiores Izquierdas: " << this->StockInfIzqQ<<endl
           << "Stock Protesis Quirurgicas Inferiores Derechas: " << this->StockInfDerQ<<endl
           << "Stock Protesis No Quirurgicas Superiores Izquierdas: "<< this->StockSupIzqNQ <<endl
           << "Stock Protesis No Quirurgicas Superiores Derechas: " << this->StockSupDerNQ<<endl
           << "Stock Protesis No Quirurgicas Inferiores Izquierdas: " << this->StockInfIzqNQ<<endl
           << "Stock Protesis No Quirurgicas Inferiores Derechas: " << this->StockInfDerNQ<<endl;

    while (it != ListadoProtesis.end()) {
        salida << **it <<endl;
        it++;
    }

    return salida.str();
}

void cOrtopedia::imprimir(){
    cout << this->to_string() << endl;
    return;
}

cOrtopedia::~cOrtopedia(){}
