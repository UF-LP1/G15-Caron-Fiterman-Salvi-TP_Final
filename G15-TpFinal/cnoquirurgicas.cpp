#include "cnoquirurgicas.h"

cNoQuirurgicas::cNoQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis, string material, string sujecion):
    cProtesis(largo, radio, fechaFabricacion, fabricante, infoProtesis, material){
    this->sujecion=sujecion;
}

cNoQuirurgicas::cNoQuirurgicas(const cNoQuirurgicas &copia): cProtesis(copia){
    this->sujecion = copia.sujecion;
}//constructor por copia

const string cNoQuirurgicas::get_material() const{
    return this->Material;
}

void cNoQuirurgicas::set_material(string Material){
    this->Material = Material;
    return;
}

void cNoQuirurgicas::cambiarSujecion(string nuevaSujecion){
    this->sujecion=nuevaSujecion;
}

const string cNoQuirurgicas::get_sujecion()const{
    return this->sujecion;
}

void cNoQuirurgicas::realizarMantenimiento() {
    cambiarSujecion(this->sujecion);//"renueva la sujecion"
    set_material(this->Material);//"renueva el material"
    return;
}

cNoQuirurgicas::~cNoQuirurgicas(){}
