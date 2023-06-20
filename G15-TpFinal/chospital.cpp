
#include "chospital.h"

cHospital::cHospital()
{

}

const string cHospital::get_Nombre() const{
    return this->Nombre;
}

const string cHospital::get_Direccion() const{
    return this->Direccion;
}

void cHospital::set_ListaMedicos(list<cMedico*> ListaMedicos){
    this->ListaMedicos = ListaMedicos;
    return;
}

const list<cMedico*> cHospital::get_ListaMedicos() const{
    return this->ListaMedicos;
}

void cHospital::set_ListaPacientes(list<cPaciente*> ListaPacientes){
    this->ListaPacientes = ListaPacientes;
    return;
}

const list<cPaciente*> cHospital:: get_ListaPacientes() const{
    return this->ListaPacientes;
}

const string cHospital::ListarMedicos() const{

    list<cMedico*>::const_iterator it = ListaMedicos.begin();
    stringstream salidaLista;

    while (it != ListaMedicos.end()) {
        salidaLista << *it <<endl; //usa la sobrecarga de << del medico
        ++it;
    } //recorro toda la lista de medicos

    return salidaLista.str();
}

const string cHospital::ListarPacientes() const{

    list<cPaciente*>::const_iterator it = ListaPacientes.begin();
    stringstream salidaLista;

    while (it != ListaPacientes.end()) {
        salidaLista << *it <<endl; //usa la sobrecarga de << del paciente
        ++it;
    } //recorro toda la lista de pacientes

    return salidaLista.str();
}

const string cHospital::to_string() const{
    stringstream salida;

    salida << "Nombre Fabricante: "<< this->get_Nombre() <<endl
           << "Direccion: " << this->get_Direccion() <<endl
           << "Lista Medicos: " << this->ListarMedicos() <<endl //toda la lista
           << "Lista Pacientes: " << this->ListarPacientes() <<endl; //idem
    return salida.str();
}
void cHospital::imprimir(){
    cout << this->to_string() << endl;
}


void cHospital::operator+(cPaciente &pacienteNuevo){
    list<cPaciente*>::iterator it = this->ListaPacientes.begin();
    bool encontrado = false;

    while(it != this->ListaPacientes.end()){
        if(pacienteNuevo == *(*it)) //sobrecarga del ==
            encontrado = true; //ya existe ese paciente en la lista
        it++;
    }

    if(encontrado == false) //si el paciente no esta en la lista previamente, lo agrego
        this->ListaPacientes.push_back(&pacienteNuevo);

    return;

}

void cHospital::operator-(cPaciente &pacienteBorrar){
    list<cPaciente*>::iterator it= this->ListaPacientes.begin();
    bool encontrado = false;

    while(it != this->ListaPacientes.end()){
        if(*(*it)==pacienteBorrar){ //sobrecarga del ==
            encontrado = true;
            break;
        }

        it++;
    }

    if(encontrado == true)
        this->ListaPacientes.erase(it);

    return;

}

void cHospital::operator+(cMedico &medicoNuevo){
    list<cMedico*>::iterator it = this->ListaMedicos.begin();
    bool encontrado = false;

    while(it != this->ListaMedicos.end()){
        if(medicoNuevo == *(*it)) //sobrecarga del ==
            encontrado = true; //ya existe ese medico en la lista
        it++;
    }

    if(encontrado == false) //si el paciente no esta en la lista previamente, lo agrego
        this->ListaMedicos.push_back(&medicoNuevo);

    return;

}

void cHospital::operator-(cMedico &medicoBorrar){
    list<cMedico*>::iterator it = this->ListaMedicos.begin();
    bool encontrado = false;

    while(it != this->ListaMedicos.end()){
        if(*(*it)==medicoBorrar){ //sobrecarga del ==
            encontrado = true;
            break;
        }

        it++;
    }

    if(encontrado == true)
        this->ListaMedicos.erase(it);

    return;
}

bool cHospital::operator==(const cHospital &HospitalAComparar){
    bool iguales = false;

    if(this->Nombre == HospitalAComparar.Nombre &&
       this->Direccion == HospitalAComparar.Direccion &&
       this->ListaMedicos == HospitalAComparar.ListaMedicos &&
       this->ListaPacientes == HospitalAComparar.ListaPacientes
       ){
        iguales = true;
    }

    return iguales;
}

cHospital::~cHospital(){}

ostream& operator<<(ostream& os, const cHospital& Hospital){
    os<< Hospital.to_string()<<endl;
    return os;
}

