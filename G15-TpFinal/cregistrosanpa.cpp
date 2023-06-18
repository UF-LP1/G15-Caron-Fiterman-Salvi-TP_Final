#include "cregistrosanpa.h"

cRegistrosANPA::cRegistrosANPA(string DNI, string hospital, string medico, QDate FSolicitud, QDate FEntrega, QDate FEntregaEstimada, string pieza, EstadoProtesis estado)
    : DNIPaciente(DNI)
{
    this->Hospital = hospital;
    this->Medico = medico;
    this->FechaSolicitud = FSolicitud;
    this->FechaEntrega = FEntrega;
    this->FechaEntregaEstimada = FEntregaEstimada;
    this->piezaOrtopedica = pieza;
    this->estadoProtesis = estado;
}

const string cRegistrosANPA::get_DNIPaciente(){
    return this->DNIPaciente;
}

const string cRegistrosANPA::get_Hospital(){
    return this->Hospital;
}
void cRegistrosANPA::set_Hospital(string hospital){
    this->Hospital = hospital;
    return;
}

const string cRegistrosANPA::get_Medico(){
    return this->Medico;
}
void cRegistrosANPA::set_Medico(string medico){
    this->Medico = medico;
    return;
}


const string cRegistrosANPA::get_PiezaOrtopedica(){
    return this->piezaOrtopedica;
}
void cRegistrosANPA::set_PiezaOrtopedica(string pieza){
    this->piezaOrtopedica = pieza;
    return;
}

const QDate cRegistrosANPA::get_FechaSolicitud(){
    return this->FechaSolicitud;
}
void cRegistrosANPA::set_FechaSolicitud(QDate solicitud){
    this->FechaSolicitud = solicitud;
}

const QDate cRegistrosANPA::get_FechaEntrega(){
    return this->FechaEntrega;
}
void cRegistrosANPA::set_FechaEntrega(QDate entrega){
    this->FechaEntrega = entrega;
    return;
}

const QDate cRegistrosANPA::get_FechaEntregaEstimada(){
    return this->FechaEntregaEstimada;
}
void cRegistrosANPA::set_FechaEntregaEstimada(QDate entregaEstimada){
    this->FechaEntregaEstimada = entregaEstimada;
    return;
}

const EstadoProtesis cRegistrosANPA::get_EstadoProtesis(){
    return this->estadoProtesis;
}
void cRegistrosANPA::set_EstadoProtesis(EstadoProtesis estado){
    this->estadoProtesis = estado;
    return;
}

const string cRegistrosANPA:: to_string(){
    //HACER CODIGO
}

void cRegistrosANPA::imprimir(){
    //HACER CODIGO
}


cRegistrosANPA::~cRegistrosANPA(){}
