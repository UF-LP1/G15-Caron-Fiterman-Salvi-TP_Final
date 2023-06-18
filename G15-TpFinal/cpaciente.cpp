#include "cpaciente.h"

cPaciente::cPaciente(string nombre, string apellido, string dni, QDateTime fechaNac, string telefono, list <string> alergias, string HospitAlatentido, float RadioMiembro, bool PermisoProtesis, cProtesis Protesis)
    : cPersona(nombre,apellido,dni), FechaNac(fechaNac), Protesis(Protesis){
    this->Telefono = telefono;
    this->Alergias = alergias;
    this->HospitalAtendido = HospitAlatentido;
    this->RadioMiembro = RadioMiembro;
    this->PermisoProtesis = PermisoProtesis;
}

void cPaciente::set_telefono(string telefono){
    this->Telefono = telefono;
    return;
}
const string cPaciente::get_telefono(){
    return this->Telefono;
}


void cPaciente::set_alergias(list<string> alergias){
    this->Alergias=alergias;
    return;
}
const list <string> cPaciente::get_alergias(){
    return this->Alergias;
}

void cPaciente::set_hospitalatendido(string HospitalAtendido){
    this->HospitalAtendido = HospitalAtendido;
    return;
}
const string cPaciente::get_hospitalatendido(){
    return this->HospitalAtendido;
}


void cPaciente::set_radio(float radio){
    this->RadioMiembro = radio;
    return;
}
const float cPaciente::get_radiomiembro(){
    return this->RadioMiembro;
}


void cPaciente::set_permisoprotesis(bool permiso){
    this->PermisoProtesis = permiso;
    return;
}
const bool cPaciente::get_permisoprotesis(){
    return this->PermisoProtesis;
}

const QDateTime cPaciente::get_fechanac(){
    return this->FechaNac;
}


const string cPaciente::to_string(){
    //HACER CODIGO
}

void cPaciente::imprimir(){
    //HACER CODIGO
}

cPaciente::~cPaciente(){}
