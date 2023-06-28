
#include "chospital.h"

cHospital::cHospital(string Nombre, string direccion) : Nombre(Nombre), Direccion(direccion)
{
    this->ListaMedicos.clear();
    this->ListaPacientes.clear();

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

const list<cMedico*>& cHospital::get_ListaMedicos() const{
    return this->ListaMedicos;
}

void cHospital::set_ListaPacientes(list<cPaciente*> ListaPacientes){
    this->ListaPacientes = ListaPacientes;
    return;
}

const list<cPaciente*>& cHospital:: get_ListaPacientes() const{
    return this->ListaPacientes;
}

list<cPaciente*>::iterator cHospital::get_BeginListaPacientes(){
    return this->ListaPacientes.begin();
}

list<cPaciente*>::iterator cHospital::get_EndListaPacientes(){
    return this->ListaPacientes.end();
}


const string cHospital::to_string() const{
    list<cPaciente*>::const_iterator it = ListaPacientes.begin();
    list<cMedico*>::const_iterator it2 = ListaMedicos.begin();
    stringstream salida;

    salida << "Nombre Fabricante: "<< this->get_Nombre() <<endl
           << "Direccion: " << this->get_Direccion() <<endl
           << "Lista Pacientes: "<< endl;

    while (it != ListaPacientes.end()) {
        salida << **it <<endl; // Desreferencia el puntero y utiliza el operador << sobrecarga cPaciente
        it++;
    }  //recorro toda la lista de pacientes

    salida<< "Lista Medicos: "<<endl;
    while (it2 != ListaMedicos.end()) {
        salida << **it2 <<endl; //usa la sobrecarga de << del medico
        it2++;
    } //recorro toda la lista de medicos

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

cPaciente& cHospital::operator[](unsigned int idx){
    list<cPaciente*>::iterator it= this->ListaPacientes.begin();
    int cont = 0;

    while(cont<idx && it!= this->ListaPacientes.end()){
        it++;
        cont++;
    }
    return **it;
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

cMedico& cHospital::getMedico(unsigned int idx){
    list<cMedico*>::iterator it= this->ListaMedicos.begin();
    int cont = 0;

    while(cont<idx && it!= this->ListaMedicos.end()) {
        it++;
        cont++;
    }

    return **it;
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

