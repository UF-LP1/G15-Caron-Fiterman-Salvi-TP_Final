#include "cpaciente.h"

cPaciente::cPaciente(string nombre, string apellido, string dni, QDate fechaNac, string telefono, string Medico, list <string> alergias, string HospitAlatentido, float RadioMiembro, bool PermisoProtesis, cProtesis Protesis)
    : cPersona(nombre,apellido,dni), FechaNac(fechaNac), Protesis(Protesis){
    this->Telefono = telefono;
    this->MatriculaMedico = Medico;
    this->Alergias = alergias;
    this->HospitalAtendido = HospitAlatentido;
    this->RadioMiembro = RadioMiembro;
    this->PermisoProtesis = PermisoProtesis;
}

void cPaciente::set_telefono(string telefono){
    this->Telefono = telefono;
    return;
}
const string cPaciente::get_telefono()const{
    return this->Telefono;
}

void cPaciente::set_Medico(string Medico){
    this->MatriculaMedico = Medico;
    return;
}
const string cPaciente::get_Medico()const{
    return this->MatriculaMedico;
}

void cPaciente::set_alergias(list<string> alergias){
    this->Alergias=alergias;
    return;
}
const list <string> cPaciente::get_alergias() const{
    return this->Alergias;
}

void cPaciente::set_hospitalatendido(string HospitalAtendido){
    this->HospitalAtendido = HospitalAtendido;
    return;
}
const string cPaciente::get_hospitalatendido()const{
    return this->HospitalAtendido;
}


void cPaciente::set_radio(float radio){
    this->RadioMiembro = radio;
    return;
}
const float cPaciente::get_radiomiembro() const{
    return this->RadioMiembro;
}


void cPaciente::set_permisoprotesis(bool permiso){
    this->PermisoProtesis = permiso;
    return;
}
const bool cPaciente::get_permisoprotesis() const{
    return this->PermisoProtesis;
}

void cPaciente::set_protesis(cProtesis protesis){
    try{
        this->Protesis = protesis; //usa la sobrecarga del = de cProtesis
    } catch(ErrorIgual *e){
        throw e;
    }
    return;
}
const cProtesis cPaciente::get_protesis() const{
    return this->Protesis;
}

const QDate cPaciente::get_fechanac() const{
    return this->FechaNac;
}


 const string& cPaciente::operator[](unsigned int idx) {
    list<string>::const_iterator it = this->Alergias.begin();
    unsigned int cont = 0;

    while (cont < idx && it != this->Alergias.end()) {
        it++;
        cont++;
    }
    return *it;
}


const string cPaciente::to_string() const{
    stringstream salida;
    list<string>::const_iterator it = Alergias.begin();

    salida << cPersona::to_string()<<endl //usa el to_string de cPersona
           << "Fecha Nacimiento: "<< this->get_fechanac().toString().toStdString()<<endl
           << "Telefono: " << this->get_telefono()<<endl
           << "Medico:" << this->get_Medico()<<endl
           << "Alergias: " << endl;

    while (it != Alergias.end()) {
        salida << *it <<endl;
        it++;
    }

    salida << "Hospital Atendido: " << this->get_hospitalatendido()<<endl
           << "Radio Miembro: " << this->get_radiomiembro()<<endl
           << "Permiso Protesis: "<< this->get_permisoprotesis() <<endl
           << "Protesis: " << this->Protesis.to_string()<<endl; //usa el to_string de protesis

    return salida.str();
}

void cPaciente::imprimir(){
    cout << this->to_string() << endl;
    return;
}


bool cPaciente::operator==(const cPaciente &PacienteAComparar){

    if(&PacienteAComparar == nullptr){
        throw new DatoEsNullptr;
    }

    return(this->Nombre == PacienteAComparar.Nombre &&
       this->Apellido == PacienteAComparar.Apellido &&
       this->DNI == PacienteAComparar.DNI &&
       this->FechaNac.toString() == PacienteAComparar.FechaNac.toString() &&
       this->Telefono == PacienteAComparar.Telefono &&
       this->HospitalAtendido == PacienteAComparar.HospitalAtendido &&
       this->RadioMiembro == PacienteAComparar.RadioMiembro &&
       this->PermisoProtesis == PacienteAComparar.PermisoProtesis &&
       this->Protesis == PacienteAComparar.Protesis &&
       this->get_alergias() == PacienteAComparar.get_alergias());
}

ostream& operator<<(ostream& os, const cPaciente& paciente) {
    if(&paciente == nullptr){
        throw new DatoEsNullptr;
    }
    os << paciente.to_string(); // usa función to_string() de cPaciente
    return os;
}

void cPaciente::operator+(string &AlergiaNueva){
    if(&AlergiaNueva == nullptr){
        throw new DatoEsNullptr;
    }

    list<string>::iterator it = this->Alergias.begin();
    bool encontrado = false;


    while(it != this->Alergias.end()){
        if(AlergiaNueva == *it)
            encontrado = true; //ya existe esa alergia en la lista
        it++;
    }

    if(encontrado == false) //si el paciente no esta en la lista previamente, lo agrego
        this->Alergias.push_back(AlergiaNueva);

    return;
}

void cPaciente::operator-(string &AlergiaBorrar){
    if(&AlergiaBorrar == nullptr){
        throw new DatoEsNullptr;
    }

    list<string>::iterator it = this->Alergias.begin();
    bool encontrado = false;


    while(it != this->Alergias.end()){
        if(AlergiaBorrar == *it)
            encontrado = true; //ya existe esa alergia en la lista
        it++;
    }

    if(encontrado == true)
        this->Alergias.erase(it);

    return;
}

cPaciente::~cPaciente(){}
