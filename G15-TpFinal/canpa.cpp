#include "canpa.h"


cANPA::cANPA(string direccion, list<cRegistrosANPA*> listaRegistros){ //constructor
    this->direccion = direccion;
    this->ListaRegistros = listaRegistros;
}

list<cRegistrosANPA*> cANPA::get_ListaRegistros(){
    return this->ListaRegistros;
}

const string cANPA::get_direccion(){
    return this->direccion;
}


void cANPA::Entregar_Protesis(cPaciente paciente, cProtesis protesisPaciente){ //le entrega la protesis al paciente, usa la sobrecarga del = para asignarle la protesis
    //HACER CODIGO

}

void cANPA::AgregarPaciente(cPaciente pacienteNuevo){ //usa sobrecarga del +
    //HACER CODIGO
}


cPaciente cANPA::BuscarPacXProtesis(cProtesis protesisPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

}


cPaciente cANPA::BuscarPacXHospital(cHospital hospitalPaciente){ //usa sobrecarga del ==
    //HACER CODIGO

}

const string cANPA::ListarRegistros(){

    list<cRegistrosANPA*>::iterator it = ListaRegistros.begin();
    stringstream salidaLista;

    while (it != ListaRegistros.end()) {
        salidaLista << "DNI Paciente: " << (*it)->get_DNIPaciente() << endl
                    << "Hospital: " << (*it)->get_Hospital()<<endl
                    << "Medico: " << (*it)->get_Medico()<<endl
                    << "Fecha Solicitud: " << (*it)->get_FechaSolicitud().toString().toStdString() << endl
                    << "Fecha Entrega: " << (*it)->get_FechaEntrega().toString().toStdString() << endl
                    << "Fecha Entrega Estimada: " << (*it)->get_FechaEntregaEstimada().toString().toStdString() << endl;
            /*
             * método toString() de la clase QDate convierte fecha a string
             * toStdString() convierte a std::string (tipo que usa  el stringstream
             *
             */

        ++it;
    }

    return salidaLista.str();
}

const string cANPA::to_string(){
    stringstream salida;
    salida << "Direccion ANPA:"<< this->direccion<<endl
           << this->ListarRegistros()<<endl;

    return salida.str();
}

void cANPA::imprimir(){
    cout << this->to_string() << endl;
    return;
}


cANPA::~cANPA(){}
