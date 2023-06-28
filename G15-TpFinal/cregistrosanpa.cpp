#include "cregistrosanpa.h"

cRegistrosANPA::cRegistrosANPA(string DNI, string hospital, string medico, QDate FSolicitud, QDate FEntrega, QDate FEntregaEstimada, cProtesis pieza, EstadoProtesis estado)
    : DNIPaciente(DNI), piezaOrtopedica(pieza)
{
    this->Hospital = hospital;
    this->Medico = medico;
    this->FechaSolicitud = FSolicitud;
    this->FechaEntrega = FEntrega;
    this->FechaEntregaEstimada = FEntregaEstimada;
    this->estadoProtesis = estado;
}

const string cRegistrosANPA::get_DNIPaciente() const {
    return this->DNIPaciente;
}

const string cRegistrosANPA::get_Hospital() const{
    return this->Hospital;
}
void cRegistrosANPA::set_Hospital(string hospital){
    this->Hospital = hospital;
    return;
}

const string cRegistrosANPA::get_Medico() const{
    return this->Medico;
}
void cRegistrosANPA::set_Medico(string medico){
    this->Medico = medico;
    return;
}


const cProtesis cRegistrosANPA::get_PiezaOrtopedica()const{
    return this->piezaOrtopedica;
}
void cRegistrosANPA::set_PiezaOrtopedica(cProtesis pieza){
    this->piezaOrtopedica = pieza;
    return;
}

const QDate cRegistrosANPA::get_FechaSolicitud() const{
    return this->FechaSolicitud;
}
void cRegistrosANPA::set_FechaSolicitud(QDate solicitud){
    this->FechaSolicitud = solicitud;
}

const QDate cRegistrosANPA::get_FechaEntrega() const{
    return this->FechaEntrega;
}
void cRegistrosANPA::set_FechaEntrega(QDate entrega){
    this->FechaEntrega = entrega;
    return;
}

const QDate cRegistrosANPA::get_FechaEntregaEstimada() const{
    return this->FechaEntregaEstimada;
}
void cRegistrosANPA::set_FechaEntregaEstimada(QDate entregaEstimada){
    this->FechaEntregaEstimada = entregaEstimada;
    return;
}

const string cRegistrosANPA::get_EstadoProtesis() const{
    switch (this->estadoProtesis) {
    case Entregada:
        return "Entregada";

    case Solicitada:
        return "Solicitada";

    default:
        return "Estado Protesis Desconocido";
    }

}

void cRegistrosANPA::set_EstadoProtesis(EstadoProtesis estado){
    this->estadoProtesis = estado;
    return;
}

const string cRegistrosANPA:: to_string() const {
    stringstream salidaLista;
    salidaLista << "DNI Paciente: " << this->DNIPaciente << endl
                << "Hospital: " << this->Hospital<<endl
                << "Medico: " << this->get_Medico()<<endl
                << "Fecha Solicitud: " << this->get_FechaSolicitud().toString().toStdString() << endl
                << "Fecha Entrega: " << this->get_FechaEntrega().toString().toStdString() << endl
                << "Fecha Entrega Estimada: " << this->get_FechaEntregaEstimada().toString().toStdString() << endl
                << "Estado Protesis"<< this->get_EstadoProtesis()<<endl
                << "Protesis: "<< this->piezaOrtopedica.to_string();

             /*
             * método toString() de la clase QDate convierte fecha a string,
             * toStdString() convierte a std::string (tipo que usa el stringstream)
             *
             */
    return salidaLista.str();
}

void cRegistrosANPA::imprimir(){
    cout << this->to_string() << endl;
}


cRegistrosANPA::~cRegistrosANPA(){}

bool cRegistrosANPA::operator==(const cRegistrosANPA &RegistroAComparar){
    if(&RegistroAComparar == nullptr){
        throw new DatoEsNullptr;
    }

    return (this->DNIPaciente == RegistroAComparar.DNIPaciente &&
       this->Hospital == RegistroAComparar.Hospital &&
       this->Medico == RegistroAComparar.Medico &&
       this->FechaSolicitud.toString() == RegistroAComparar.FechaSolicitud.toString() &&
       this->FechaEntrega.toString() == RegistroAComparar.FechaEntrega.toString() &&
       this->FechaEntregaEstimada.toString() == RegistroAComparar.FechaEntregaEstimada.toString() &&
       this->piezaOrtopedica == RegistroAComparar.piezaOrtopedica &&
       this->estadoProtesis == RegistroAComparar.estadoProtesis);
}


ostream& operator<<(ostream& os, const cRegistrosANPA& registroImprimir){
    os<< registroImprimir.to_string()<<endl;
    return os;
}


