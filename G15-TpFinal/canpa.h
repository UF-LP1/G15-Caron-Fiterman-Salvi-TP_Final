#ifndef CANPA_H
#define CANPA_H
#include <string>
#include <iostream>
#include <list>
#include <sstream>
using namespace std;

#include "cregistrosanpa.h"
#include "chospital.h"



class cANPA
{
    public:
        cANPA(string direccion, list<cRegistrosANPA*> listaRegistros); //constructor

        list<cRegistrosANPA*> get_ListaRegistros();
        const string get_direccion();

        void Entregar_Protesis(cPaciente paciente, cProtesis protesisPaciente); //le entrega la protesis al paciente, usa la sobrecarga del = para asignarle la protesis
        void AgregarPaciente(cPaciente pacienteNuevo); //usa sobrecarga del +
        cPaciente BuscarPacXProtesis(cProtesis protesisPaciente); //usa sobrecarga del ==
        cPaciente BuscarPacXHospital(cHospital hospitalPaciente); //usa sobrecarga del ==

        const string ListarRegistros();
        const string to_string();
        void imprimir();

        ~cANPA();


    private:
        string direccion;
        list<cRegistrosANPA*> ListaRegistros;

};

#endif // CANPA_H
