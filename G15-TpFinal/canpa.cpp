#include "canpa.h"


cANPA::cANPA(string direccion, list<cRegistrosANPA*> listaRegistros, list<cHospital*> listaHospitales): direccion(direccion){ //constructor
    this->ListaRegistros = listaRegistros;
    this->ListaHospitales = listaHospitales;
}

list<cRegistrosANPA*> cANPA::get_ListaRegistros() const{
    return this->ListaRegistros;
}

list<cHospital*> cANPA::get_ListaHospitales() const{
    return this->ListaHospitales;
}

const string cANPA::get_direccion() const{
    return this->direccion;
}


void cANPA::Entregar_Protesis(cPaciente paciente, cProtesis protesisPaciente){ //le entrega la protesis al paciente, usa la sobrecarga del = para asignarle la protesis
    //HACER CODIGO

    // "Se debe utilizar la sobrecarga del operador "==" para verificar si la prótesis en stock
    // es la que el paciente necesita." consigna

}

void cANPA::AgregarRegistroPaciente(cRegistrosANPA pacienteNuevo){ //usa sobrecarga del ==, se usa en la sobrecarga del +
    list<cRegistrosANPA*>::iterator it = this->ListaRegistros.begin();
    bool encontrado = false;

    while(it!= this->ListaRegistros.end()){
        if(pacienteNuevo == *(*it)) //sobrecarga del == de cRegistrosANPA
            encontrado = true;
        it++;
    }

    if(encontrado == false) //si el paciente no esta en la lista previamente
        this->ListaRegistros.push_back(&pacienteNuevo);

    return;
}

//cPaciente cANPA::BuscarPacXProtesis(cProtesis protesisPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

//}//Buscar pacientes que ya poseen prótesis según la prótesis o el hospital.


cPaciente cANPA::BuscarPacXHospital(cHospital hospitalPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

}//Buscar pacientes que ya poseen prótesis según la prótesis o el hospital.

const string cANPA::ListarRegistros() const{

    list<cRegistrosANPA*>::const_iterator it = ListaRegistros.begin();
    stringstream salidaLista;

    while (it != ListaRegistros.end()) {
        salidaLista << *it <<endl; //sobrecarga <<
        ++it;
    }

    return salidaLista.str();
}

const string cANPA::ListarHospitales() const{
    list<cHospital*>::const_iterator it = ListaHospitales.begin();
    stringstream salidaLista;

    while (it != ListaHospitales.end()) {
        salidaLista << *it <<endl; //sobrecarga <<
        ++it;
    }

    return salidaLista.str();

}


const string cANPA::to_string() const{
    stringstream salida;
    salida << "Direccion ANPA:"<< this->direccion<<endl
           << this->ListarRegistros()<<endl
           << this->ListarHospitales()<<endl;

    return salida.str();
}

void cANPA::imprimir(){
    cout << this->to_string() << endl;
    return;
}

cANPA::~cANPA(){}


void cANPA::operator+(cRegistrosANPA &registroNuevo){
    this->AgregarRegistroPaciente(registroNuevo);
    return;
}


void cANPA::operator-(cRegistrosANPA &registroBorrar){
    list<cRegistrosANPA*>::iterator it= this->ListaRegistros.begin();
    bool encontrado = false;

    while(it != this->ListaRegistros.end()){
        if(*(*it)==registroBorrar){ //sobrecarga del ==
            encontrado = true;
            break;
        }

        it++;
    }

    if(encontrado == true)
        this->ListaRegistros.erase(it);

    return;
}


void cANPA::operator+(cHospital &HospitalNuevo){
    list<cHospital*>::iterator it = this->ListaHospitales.begin();
    bool encontrado = false;

    while(it!= this->ListaHospitales.end()){
        if(HospitalNuevo == *(*it)) //sobrecarga del == de cHospital
            encontrado = true;
        it++;
    }

    if(encontrado == false) //si el hospital no esta en la lista previamente
        this->ListaHospitales.push_back(&HospitalNuevo);
}

void cANPA::operator-(cHospital &HospitalBorrar){
    list<cHospital*>::iterator it = this->ListaHospitales.begin();
    bool encontrado = false;

    while(it != this->ListaHospitales.end()){
        if(*(*it)==HospitalBorrar){ //sobrecarga del ==
            encontrado = true;
            break;
        }

        it++;
    }

    if(encontrado == true)
        this->ListaHospitales.erase(it);

    return;

}
