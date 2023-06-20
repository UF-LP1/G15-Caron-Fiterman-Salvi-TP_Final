#include "cmedico.h"

cMedico::cMedico(string nombre, string apellido, string dni, string matricula): cPersona(nombre,apellido,dni), Matricula(matricula) {}

const string cMedico::get_matricula() const{
    return this->Matricula;
}

void cMedico::dar_permiso_protesis(cPaciente paciente){

    if(paciente.get_radiomiembro() != 0){ //si necesita una protesis
        paciente.set_permisoprotesis(true); //le da permiso al pac para hacerse una protesis
    }

    return;
}


const string cMedico::to_string() const{
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

ostream& operator<<(ostream& os, const cMedico& MedicoImprimir){
    os<< MedicoImprimir.to_string()<<endl;
    return os;
}


cMedico::~cMedico(){}

