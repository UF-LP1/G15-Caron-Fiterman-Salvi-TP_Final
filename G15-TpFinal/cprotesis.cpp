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

const float cProtesis::get_largo() const{
    return this->Largo;
}

void cProtesis::set_largo(float Largo){
    this->Largo = Largo;
    return;
}

const float cProtesis::get_radio() const{
    return this->Radio;

}

void cProtesis::set_radio(float Radio){
    this->Radio = Radio;
    return;
}

const QDate cProtesis::get_fechaFabricacion()const{
    return this->fechaFabricacion;
}

void cProtesis::set_fechaFabricacion(QDate fecha){
    this->fechaFabricacion = fecha;
    return;
}

const string cProtesis::get_fabricante()const{
    return this->Fabricante;
}

void cProtesis:: set_fabricante(string fabricante){
    this->Fabricante = fabricante;
    return;
}

const string cProtesis::get_tipoProtesis()const{
    switch (this->InfoProtesis) {
    case SuperiorIzquierda:
        return "Superior Izquierda";

    case SuperiorDerecha:
        return "Superior Derecha";

    case InferiorIzquierda:
        return "Inferior Izquierda";

    case InferiorDerecha:
        return "Inferior Derecha";

    default:
        return "Tipo protesis Desconocida";
    }
}

const TipoProtesis cProtesis::get_TipoProtesisTipo() const{
    return this->InfoProtesis;
}

void cProtesis::set_tipoProtesis(TipoProtesis tipo){
    this->InfoProtesis = tipo;
    return;
}

const string cProtesis::get_material()const{
    return this->Material;
}

void cProtesis::set_material(string Material){
    this->Material = Material;
    return;
}

bool cProtesis::operator==(const cProtesis &ProtesisAComparar){
    bool iguales = false;

    if(this->Largo == ProtesisAComparar.Largo &&
       this->Radio == ProtesisAComparar.Radio &&
       this->fechaFabricacion.toString() == ProtesisAComparar.fechaFabricacion.toString() &&
       this->Fabricante == ProtesisAComparar.Fabricante &&
       this->get_tipoProtesis() == ProtesisAComparar.get_tipoProtesis() && //me devuelve un string en vez de un int
       this->Material == ProtesisAComparar.Material){

        iguales = true;
    }

    return iguales;
}


void cProtesis::operator=(const cProtesis& protesis){
    this->Largo= protesis.Largo;
    this->Radio = protesis.Radio;
    this->fechaFabricacion = protesis.fechaFabricacion;
    this->Fabricante = protesis.Fabricante;
    this->InfoProtesis = protesis.InfoProtesis;
    this->Material = protesis.Material; //asigno todos los valores

    if(this->Largo != protesis.Largo ||
       this->Radio != protesis.Radio ||
       this->fechaFabricacion != protesis.fechaFabricacion ||
       this->Fabricante != protesis.Fabricante ||
       this->InfoProtesis != protesis.InfoProtesis ||
       this->Material != protesis.Material){ //si algo no se copio correctamente

        throw new ErrorIgual();
    }
    return;
}

const string cProtesis::to_string()const{
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

ostream& operator<<(ostream& os, const cProtesis& ProtesisImprimir){
    os<< ProtesisImprimir.to_string()<<endl;
    return os;
}
