#include "cpaciente.h"

cPaciente::cPaciente(string nombre,string apellido, string dni,QDateTime fechaNac,string telefono,list <string> alergias, string hospitalatentido, float radiomiembro,bool permisoprotesis, cProtesis protesis)
{
}

void cPaciente::set_telefono(string telefono){
    this->Telefono=telefono;
    return;
}
void cPaciente::set_alergias(list<string> alergias){
    this->Alergias=alergias;
    return;
}
void cPaciente::set_hospitalatendido(string hospitalatendido){
    this->HospitalAtendido=hospitalatendido;
    return;
}
void cPaciente::set_radio(float radio){
    this->RadioMiembro=radio;
    return;
}
void cPaciente::set_permisoprotesis(bool permiso){
    this->PermisoProtesis=permiso;
    return;
}
const QDateTime cPaciente::get_fechanac(){
    return this->FechaNac;
}
string cPaciente::get_telefono(){
    return this->Telefono;
}
list <string> cPaciente::get_alergias(){
    return this->Alergias;
}
string cPaciente::get_hospitalatendido(){
    return this->HospitalAtendido;
}
const float cPaciente::get_radiomiembro(){
    return this->RadioMiembro;
}
const float cPaciente::get_radiomiembro(){
    return this->RadioMiembro;
}
const bool cPaciente::get_permisoprotesis(){
    return this->PermisoProtesis;
}
const string cPaciente::to_string(){

}
void cPaciente::imprimir(){

}
cPaciente::~cPaciente();
