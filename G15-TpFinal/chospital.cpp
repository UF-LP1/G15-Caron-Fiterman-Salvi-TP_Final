
#include "chospital.h"

cHospital::cHospital()
{

}

const string cHospital::get_Nombre(){
    return this->Nombre;
}

const string cHospital::get_Direccion(){
    return this->Direccion;
}

void cHospital::set_ListaMedicos(list<cMedico*> ListaMedicos){
    this->ListaMedicos = ListaMedicos;
    return;
}

const list<cMedico*> cHospital::get_ListaMedicos(){
    return this->ListaMedicos;
}

void cHospital::set_ListaPacientes(list<cPaciente*> ListaPacientes){
    this->ListaPacientes = ListaPacientes;
    return;
}

const list<cPaciente*> cHospital:: get_ListaPacientes(){
    return this->ListaPacientes;
}


const string cHospital::to_string(){
    //HACER CODIGO
}
void cHospital::imprimir(){
    //HACER CODIGO
}

cHospital::~cHospital(){}
