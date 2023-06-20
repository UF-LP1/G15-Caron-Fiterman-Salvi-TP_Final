#include "cnoquirurgicas.h"

cNoQuirurgicas::cNoQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis, string material):
    cProtesis(largo, radio, fechaFabricacion, fabricante, infoProtesis, material){}

cNoQuirurgicas::cNoQuirurgicas(const cNoQuirurgicas &copia): cProtesis(copia){}//constructor por copia

const string cNoQuirurgicas::get_material() const{
    return this->Material;
}

void cNoQuirurgicas::set_material(string Material){
    this->Material = Material;
    return;
}

cNoQuirurgicas::~cNoQuirurgicas(){}
