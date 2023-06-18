#include "cfabricante.h"

cFabricante:: cFabricante(string nombre, string direccion, string numeroHabilitacion): nombre(nombre), direccion(direccion), numeroHabilitacion(numeroHabilitacion){

}

string cFabricante::get_nombre(){
    return this->nombre;
}

string cFabricante::get_direccion(){
    return this->direccion;
}

string cFabricante::get_NroHabilitacion(){
    return this->numeroHabilitacion;
}
const string cFabricante::to_string(){
    //hacer codigo
    return "hola";
}

void cFabricante::imprimir(){
    //hacer codigo
}


cFabricante::~cFabricante(){}
