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
    stringstream salida;

    salida << "Nombre Fabricante: "<< this->get_nombre()<<endl
           << "Direccion: " << this->get_direccion()<<endl
           << "Numero Habilitacion: " << this->get_NroHabilitacion()<<endl;

    return salida.str();
}

void cFabricante::imprimir(){
    cout << this->to_string() << endl;
}


cFabricante::~cFabricante(){}
