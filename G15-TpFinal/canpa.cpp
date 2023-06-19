#include "canpa.h"


cANPA::cANPA(string direccion, list<cRegistrosANPA*> listaRegistros){ //constructor
    this->direccion = direccion;
    this->ListaRegistros = listaRegistros;
}

list<cRegistrosANPA*> cANPA::get_ListaRegistros(){
    return this->ListaRegistros;
}

const string cANPA::get_direccion(){
    return this->direccion;
}


void cANPA::Entregar_Protesis(cPaciente paciente, cProtesis protesisPaciente){ //le entrega la protesis al paciente, usa la sobrecarga del = para asignarle la protesis
    //HACER CODIGO

    // "Se debe utilizar la sobrecarga del operador "==" para verificar si la prótesis en stock
    // es la que el paciente necesita." consigna

}

void cANPA::AgregarRegistroPaciente(cRegistrosANPA pacienteNuevo){ //usa sobrecarga del + y del ==
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

cPaciente cANPA::BuscarPacXProtesis(cProtesis protesisPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

}//Buscar pacientes que ya poseen prótesis según la prótesis o el hospital.


cPaciente cANPA::BuscarPacXHospital(cHospital hospitalPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

}//Buscar pacientes que ya poseen prótesis según la prótesis o el hospital.

const string cANPA::ListarRegistros(){

    list<cRegistrosANPA*>::iterator it = ListaRegistros.begin();
    stringstream salidaLista;

    while (it != ListaRegistros.end()) {
        salidaLista << (*it)->to_string()<<endl;
        ++it;
    }

    return salidaLista.str();
}

const string cANPA::to_string(){
    stringstream salida;
    salida << "Direccion ANPA:"<< this->direccion<<endl
           << this->ListarRegistros()<<endl;

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
