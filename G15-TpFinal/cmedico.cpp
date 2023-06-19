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
} //El médico debe poder solicitar prótesis al fabricante en caso de que no haya stock en las ortopedias.

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

bool cMedico::operator==(const cMedico &MedicoAComparar){
    bool iguales = false;
    if(this->Nombre == MedicoAComparar.Nombre &&
        this->Apellido == MedicoAComparar.Apellido &&
        this->DNI == MedicoAComparar.DNI &&
        this->Matricula == MedicoAComparar.Matricula
        ){
        iguales = true;
    }

    return iguales;
}

cMedico::~cMedico(){}
