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

}

void cANPA::AgregarPaciente(cPaciente pacienteNuevo){ //usa sobrecarga del +
    //HACER CODIGO
}


cPaciente cANPA::BuscarPacXProtesis(cProtesis protesisPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

}


cPaciente cANPA::BuscarPacXHospital(cHospital hospitalPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

}

const string cANPA::to_string(){

    //HACER CODIGO
}

void cANPA::imprimir(){
    //HACER CODIGO
}


cANPA::~cANPA(){}
