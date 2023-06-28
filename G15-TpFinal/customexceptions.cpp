#include "customexceptions.h"

const char* ErrorIgual:: what() const throw(){
    return "Error en la igualacion de objetos";
}

const char* NoPermiso:: what() const throw(){
    return "No hay stock en la ortopedia y el Fabricante no dio permiso para realizar la protesis";
}

const char* PacNoEncontrado:: what() const throw(){
    return "No se encontro el paciente que se buscaba";
}

const char* DatoEsNullptr:: what() const throw(){
    return "El objeto apunta a un Nullptr";
}

