#include "cpersona.h"

using namespace std;
cPersona::cPersona(string nombre,string apellido,string dni):Nombre(nombre),Apellido(apellido),DNI(dni){

}

const string cPersona::get_nombre()const{
    return this->Nombre;
}

const string cPersona::get_apellido()const{
    return this->Apellido;
}

const string cPersona::get_DNI() const{
    return this->DNI;
}

const string cPersona::to_string() const{
    stringstream salida;
    salida << "Nombre Paciente: " << this->get_nombre()<<endl
           << "Apellido Paciente: "<< this->get_apellido()<<endl
           << "DNI Paciente: " << this->get_DNI()<<endl;

    return salida.str();
}

void cPersona::imprimir(){
    cout << this->to_string() << endl;
    return;

}

cPersona::~cPersona(){}
