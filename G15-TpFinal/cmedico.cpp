#include "cmedico.h"

cMedico::cMedico(string nombre,string apellido, string dni, string matricula): cPersona(nombre,apellido,dni), Matricula(matricula) {}

const string cMedico::get_matricula(){
    return this->Matricula;
}

void cMedico::dar_permiso_protesis(cPaciente paciente, cProtesis prote){
    //HACER CODIGO
}


bool cMedico::solicitar_protesis_fabricante(cProtesis prote){
     //HACER CODIGO
    return true;
}

const string cMedico::to_string(){
    //HACER CODIGO
}

void cMedico::imprimir(){
    //HACER CODIGO
}


cMedico::~cMedico(){}
