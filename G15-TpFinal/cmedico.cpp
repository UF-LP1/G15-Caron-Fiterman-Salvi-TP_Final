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
    stringstream salida;
    salida << cPersona::to_string()<<endl
           << "Matricula Medico: " << this->get_matricula()<<endl;

    return salida.str();
}

void cMedico::imprimir(){
    cout << this->to_string() << endl;
    return;
}


cMedico::~cMedico(){}
