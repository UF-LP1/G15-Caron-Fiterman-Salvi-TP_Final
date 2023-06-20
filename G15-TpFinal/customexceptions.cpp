#include "customexceptions.h"

const char* ErrorIgual:: what() const throw(){
    return "Error en la igualacion de objetos";
}

const char* NoPermiso:: what() const throw(){
    return "No hay stock en la ortopedia y el Fabricante no dio permiso para realizar la protesis";
}
