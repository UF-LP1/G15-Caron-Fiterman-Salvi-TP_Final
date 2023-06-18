#include "cpaciente.h"

cPaciente::cPaciente(string nombre, string apellido, string dni, QDateTime fechaNac, string telefono, list <string> alergias, string HospitAlatentido, float RadioMiembro, bool PermisoProtesis, cProtesis Protesis)
    : cPersona(nombre,apellido,dni), FechaNac(fechaNac), Protesis(Protesis){
    this->Telefono = telefono;
    this->Alergias = alergias;
    this->HospitalAtendido = HospitAlatentido;
    this->RadioMiembro = RadioMiembro;
    this->PermisoProtesis = PermisoProtesis;
}

void cPaciente::set_telefono(string telefono){
    this->Telefono = telefono;
    return;
}
const string cPaciente::get_telefono(){
    return this->Telefono;
}


void cPaciente::set_alergias(list<string> alergias){
    this->Alergias=alergias;
    return;
}
const list <string> cPaciente::get_alergias(){
    return this->Alergias;
}

void cPaciente::set_hospitalatendido(string HospitalAtendido){
    this->HospitalAtendido = HospitalAtendido;
    return;
}
const string cPaciente::get_hospitalatendido(){
    return this->HospitalAtendido;
}


void cPaciente::set_radio(float radio){
    this->RadioMiembro = radio;
    return;
}
const float cPaciente::get_radiomiembro(){
    return this->RadioMiembro;
}


void cPaciente::set_permisoprotesis(bool permiso){
    this->PermisoProtesis = permiso;
    return;
}
const bool cPaciente::get_permisoprotesis(){
    return this->PermisoProtesis;
}

const QDateTime cPaciente::get_fechanac(){
    return this->FechaNac;
}

const string cPaciente::ListarAlergias(){
    list<string>::iterator it = Alergias.begin();
    stringstream salidaLista;

    while (it != Alergias.end()) {
        salidaLista << *it << endl; //imprime la alergia
        ++it;
    } //recorro toda la lista

    return salidaLista.str();
}

const string cPaciente::to_string(){
    stringstream salida;
    salida << cPersona::to_string()<<endl //usa el to_string de cPersona
           << "Fecha Nacimiento: "<< this->get_fechanac().toString().toStdString()<<endl
           << "Telefono: " << this->get_telefono()<<endl
           << "Alergias: " << this->ListarAlergias()<<endl //lista todas las alergias
           << "Hospital Atendido: " << this->get_hospitalatendido()<<endl
           << "Radio Miembro: " << this->get_radiomiembro()<<endl
           << "Permiso Protesis: "<< this->get_permisoprotesis() <<endl
           << "Protesis: " << this->Protesis.to_string()<<endl; //usa el to_string de protesis

    return salida.str();
}

void cPaciente::imprimir(){
    cout << this->to_string() << endl;
    return;
}

cPaciente::~cPaciente(){}
