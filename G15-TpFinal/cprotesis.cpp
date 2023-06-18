#include "cprotesis.h"



cProtesis::cProtesis(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis, string material){
    this->Largo = largo;
    this->Radio = radio;
    this->fechaFabricacion = fechaFabricacion;
    this->Fabricante = fabricante;
    this->InfoProtesis = infoProtesis;
    this->Material = material;
}


cProtesis::cProtesis(const cProtesis &copia){
    this->Largo = copia.Largo;
    this->Radio = copia.Radio;
    this->fechaFabricacion = copia.fechaFabricacion;
    this->Fabricante = copia.Fabricante;
    this->InfoProtesis = copia.InfoProtesis;
}

const float cProtesis::get_largo(){
    return this->Largo;
}

void cProtesis::set_largo(float Largo){
    this->Largo = Largo;
    return;
}

const float cProtesis::get_radio(){
    return this->Radio;

}

void cProtesis::set_radio(float Radio){
    this->Radio = Radio;
    return;
}

const QDate cProtesis::get_fechaFabricacion(){
    return this->fechaFabricacion;
}

void cProtesis::set_fechaFabricacion(QDate fecha){
    this->fechaFabricacion = fecha;
    return;
}

const string cProtesis::get_fabricante(){
    return this->Fabricante;
}

void cProtesis:: set_fabricante(string fabricante){
    this->Fabricante = fabricante;
    return;
}

const TipoProtesis cProtesis::get_tipoProtesis(){
    return this->InfoProtesis;
}

void cProtesis::set_tipoProtesis(TipoProtesis tipo){
    this->InfoProtesis = tipo;
    return;
}

const string cProtesis::get_material(){
    return this->Material;
}

void cProtesis::set_material(string Material){
    this->Material = Material;
    return;
}

const string cProtesis::to_string(){
    stringstream salida;
    salida << "Largo Protesis: "<< this->get_largo() <<endl
           << "Radio: "<<this->get_radio()<<endl
           << "Fecha Fabricacion: " << this->get_fechaFabricacion().toString().toStdString()<<endl
           << "Informacion Protesis: " << this->get_tipoProtesis()<<endl
           << "Material Protesis: " << this->get_material()<<endl;

    return salida.str();

}

void cProtesis::imprimir(){
    cout << this->to_string() << endl;
    return;
}

cProtesis::~cProtesis(){}
