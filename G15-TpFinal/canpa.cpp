#include "canpa.h"


cANPA::cANPA(string direccion, list<cRegistrosANPA*> listaRegistros, list<cHospital*> listaHospitales): direccion(direccion){ //constructor
    this->ListaRegistros = listaRegistros;
    this->ListaHospitales = listaHospitales;
}

cANPA::cANPA(string direccion): direccion(direccion){
    this->ListaRegistros.clear();
    this->ListaHospitales.clear();
}

list<cRegistrosANPA*> cANPA::get_ListaRegistros() const{
    return this->ListaRegistros;
}

list<cHospital*> cANPA::get_ListaHospitales() const{
    return this->ListaHospitales;
}

const string cANPA::get_direccion() const{
    return this->direccion;
}

bool cANPA::chequearStockProtesis(cProtesis &protesis, cOrtopedia ortopedia){
    if(&protesis == nullptr){
        throw new DatoEsNullptr;
    }

    TipoProtesis tipo = protesis.get_TipoProtesisTipo();
    bool hayStock = false;

    cNoQuirurgicas *aux_NoQ = dynamic_cast<cNoQuirurgicas*> (&protesis);
    cQuirurgicas *aux_Q = dynamic_cast<cQuirurgicas*> (&protesis);

    if(aux_NoQ != nullptr){ //si es No Quirurgica

        switch (tipo) {
        case SuperiorIzquierda:
            if (ortopedia.get_StockSupIzqNQ() > 0) {
                hayStock = true;
            }
            break;

        case SuperiorDerecha:
            if (ortopedia.get_StockSupDerNQ() > 0) {
                hayStock = true;
            }
            break;

        case InferiorIzquierda:
            if (ortopedia.get_StockInfIzqNQ() > 0) {
                hayStock = true;
            }
            break;

        case InferiorDerecha:
            if (ortopedia.get_StockInfDerNQ() > 0) {
                hayStock = true;
            }
            break;

        default:
            hayStock = false;
        }
    }

    else if(aux_Q != nullptr){ //si es Quirurgica

        switch (tipo) {
        case SuperiorIzquierda:
            if (ortopedia.get_StockSupIzqQ() > 0) {
                hayStock = true;
            }
            break;

        case SuperiorDerecha:
            if (ortopedia.get_StockSupDerQ() > 0) {
                hayStock = true;
            }
            break;

        case InferiorIzquierda:
            if (ortopedia.get_StockInfIzqQ() > 0) {
                hayStock = true;
            }
            break;

        case InferiorDerecha:
            if (ortopedia.get_StockInfDerQ() > 0) {
                hayStock = true;
            }
            break;

        default:
            hayStock = false;
        }

    }

    return hayStock;

}


bool cANPA::solicitar_protesis_fabricante(){
    bool estadoSolicitud= false;
    cFabricante fabricante;

    estadoSolicitud = fabricante.darRtaSobreProtesis();

    return estadoSolicitud;
}

void cANPA::Entregar_Protesis(cPaciente paciente, cProtesis &protesisPaciente, cOrtopedia ortopedia){ //le entrega la protesis al paciente, usa la sobrecarga del = para asignarle la protesis
    if(&protesisPaciente == nullptr){
        throw new DatoEsNullptr;
    }

    list<cRegistrosANPA*>:: iterator it = ListaRegistros.begin();

    while (it != ListaRegistros.end()){
        if(paciente.get_permisoprotesis()){ //si el paciente tiene permiso para hacerse la protesis
            if(paciente.get_protesis() == protesisPaciente){ //si son la misma protesis
                try{
                    if(chequearStockProtesis(protesisPaciente, ortopedia)){//si hay stock de la protesis
                        try{
                            paciente.set_protesis(protesisPaciente);
                            (*it)->set_FechaEntrega(QDate::currentDate()); //la fecha de entrega es la de hoy
                        }catch(ErrorIgual *e){
                            cout<<e->what()<<endl;
                            delete e;
                        }
                    }
                    else if(solicitar_protesis_fabricante()){ //si no hay stock le pido al fabricante, si me dijo que me lo hace:
                        try{
                            paciente.set_protesis(protesisPaciente);
                            (*it)->set_FechaEntrega(QDate::currentDate());
                        }catch(ErrorIgual *e){
                            cout<<e->what()<<endl;
                            delete e;
                        }
                    }
                    else{
                        throw new NoPermiso;
                    }
                } catch(DatoEsNullptr *e){
                    throw e;
                }

            }
        }

        it++;
    }

    return;

}

void cANPA::AgregarRegistroPaciente(cRegistrosANPA pacienteNuevo){ //usa sobrecarga del ==, se usa en la sobrecarga del +
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



cPaciente cANPA::BuscarPacXHospital(string DNIPaciente){ //usa sobrecarga del ==
    list<cHospital*>:: iterator it = ListaHospitales.begin();
    list <cRegistrosANPA*>:: iterator itRegistros = ListaRegistros.begin();
    bool encontrado = false;
    list<cPaciente*>:: iterator itPacientes;

    while(it!= ListaHospitales.end() && itRegistros != ListaRegistros.end()){
        if((*it)->get_Nombre() == (*itRegistros)->get_Hospital()){ //si son el mismo hospital
            itPacientes = (*it)->get_BeginListaPacientes(); //recorro la lista de pacientes del hospital

            while(itPacientes!= (*it)->get_EndListaPacientes()){
                if(DNIPaciente == (*itPacientes)->get_DNI()){ // si es el mismo DNI
                    encontrado = true;
                    break;
                }
            }

        }

        it++;
    }

    if(encontrado == false){
        throw new PacNoEncontrado;
    }

    return *(*itPacientes);
}//Buscar pacientes que ya poseen prótesis según el hospital.

cPaciente cANPA::BuscarPacXProtesis(cProtesis protesisPaciente){
    list <cRegistrosANPA*>:: iterator itRegistros = ListaRegistros.begin();
    bool encontrado = false;
    string auxDNI;
    cPaciente* auxPac = nullptr;


    while(itRegistros != ListaRegistros.end()){
        if( (*itRegistros)->get_PiezaOrtopedica() == protesisPaciente){ //si la protesis que se busca es la del paciente
            encontrado = true;
            auxDNI = (*itRegistros)->get_DNIPaciente(); //me guardo el DNI porque lo tengo que buscar en la lista de hospitales para tener el cPaciente
            break;
        }
        itRegistros++;
    }

    if(encontrado){
        try {
            auxPac = new cPaciente(BuscarPacXHospital(auxDNI));
        } catch (PacNoEncontrado *e) {
            delete auxPac; //lo borro porque como se lanzo una excepcion no se va a usar
            throw *e; // Relanzo la excepción
        }

    }
    else{

       throw new PacNoEncontrado;
    }

    cPaciente pacienteEncontrado = *auxPac; // creo un cPaciente a partir del puntero
    delete auxPac; //libero memoria

    return pacienteEncontrado;
}


const string cANPA::to_string() const{
    stringstream salida;
    list<cHospital*>::const_iterator it = ListaHospitales.begin();
    list<cRegistrosANPA*>::const_iterator it2 = ListaRegistros.begin();
    salida << "Direccion ANPA:"<< this->direccion<<endl
           <<"Lista Hospitales: "<< endl;

    while (it != ListaHospitales.end()) {
       salida << **it <<endl; // Desreferencia el puntero y utiliza sobrecarga del operador <<
       it++;
    }

    salida << "Lista Registros ANPA:"<< endl;
    while (it2 != ListaRegistros.end()) {
       salida << **it2 <<endl; // Desreferencia el puntero y utiliza sobrecarga del operador <<
       it2++;
    }
    //FALTAN LISTAS REGISTROS Y HOSPITALES
    return salida.str();
}

void cANPA::imprimir(){
    cout << this->to_string() << endl;

    return;
}

cANPA::~cANPA(){}


void cANPA::operator+(cRegistrosANPA &registroNuevo){
    if(&registroNuevo == nullptr){
       throw new DatoEsNullptr;
    }

    this->AgregarRegistroPaciente(registroNuevo);
    return;
}


void cANPA::operator-(cRegistrosANPA &registroBorrar){
    if(&registroBorrar == nullptr){
       throw new DatoEsNullptr;
    }
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

cRegistrosANPA& cANPA::operator[](unsigned int idx){
    list<cRegistrosANPA*>::iterator it= this->ListaRegistros.begin();
    unsigned int cont = 0;

    while(cont<idx && it!= this->ListaRegistros.end()){
        it++;
        cont++;
    }

    return **it;
}

void cANPA::operator+(cHospital &HospitalNuevo){
    if(&HospitalNuevo == nullptr){
        throw new DatoEsNullptr;
    }

    list<cHospital*>::iterator it = this->ListaHospitales.begin();
    bool encontrado = false;

    while(it!= this->ListaHospitales.end()){
        if(HospitalNuevo == *(*it)) //sobrecarga del == de cHospital
            encontrado = true;
        it++;
    }

    if(encontrado == false){
        this->ListaHospitales.push_back(&HospitalNuevo);
        cANPA::CantidadHospitales++;
    }//si el hospital no esta en la lista previamente


}

void cANPA::operator-(cHospital &HospitalBorrar){
    if(&HospitalBorrar == nullptr){
        throw new DatoEsNullptr;
    }


    list<cHospital*>::iterator it = this->ListaHospitales.begin();
    bool encontrado = false;

    while(it != this->ListaHospitales.end()){
        if(*(*it)==HospitalBorrar){ //sobrecarga del ==
            encontrado = true;
            break;
        }

        it++;
    }

    if(encontrado == true){
        this->ListaHospitales.erase(it);
        cANPA::CantidadHospitales--;
    }


    return;

}

cHospital& cANPA::getHospital(unsigned int idx){
    list<cHospital*>::iterator it= this->ListaHospitales.begin();
    unsigned int cont = 0;

    while(cont<idx && it!= this->ListaHospitales.end()){
        it++;
        cont++;
    }

    return **it;
}

int cANPA::CantidadHospitales = 0;
