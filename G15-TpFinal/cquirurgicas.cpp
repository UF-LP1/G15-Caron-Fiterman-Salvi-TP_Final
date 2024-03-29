#include "cquirurgicas.h"

cQuirurgicas::cQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis , string material)
:cProtesis(largo, radio, fechaFabricacion, fabricante, infoProtesis, material){}

cQuirurgicas::cQuirurgicas(const cQuirurgicas &copia):cProtesis(copia){} //constructor por copia

const string cQuirurgicas::get_material()const{
    return this->Material;
}

void cQuirurgicas::set_material(string Material){
    this->Material = Material;
    return;
}

void cQuirurgicas::ajustarImplante(float radio, float largo){
    set_largo(largo);
    set_radio(radio);
}

void cQuirurgicas::realizarMantenimiento() {
    ajustarImplante(this->Radio, this->Largo);//la "ajusta"
    set_material(this->Material);//"renueva el material"
    return;
}

cQuirurgicas::~cQuirurgicas(){}
