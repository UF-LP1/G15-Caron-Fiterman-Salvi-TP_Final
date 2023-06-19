#ifndef CHOSPITAL_H
#define CHOSPITAL_H
#include <string>
#include <iostream>
#include <list>
#include <QDateTime>
#include <sstream>
using namespace std;

#include "cmedico.h"
#include "cpaciente.h"

class cHospital
{
    public:
        cHospital();
        const string get_Nombre();
        const string get_Direccion();

        void set_ListaMedicos(list<cMedico*> ListaMedicos);
        const list<cMedico*> get_ListaMedicos();

        void set_ListaPacientes(list<cPaciente*> ListaPacientes);
        const list<cPaciente*> get_ListaPacientes();

        const string ListarMedicos();
        const string ListarPacientes();

        const string to_string();
        void imprimir();

        void operator+(cPaciente &pacienteNuevo);
        void operator-(cPaciente &pacienteBorrar);

        void operator+(cMedico &medicoNuevo);
        void operator-(cMedico &medicoBorrar);

        ~cHospital();



    private:
        const string Nombre;
        const string Direccion;
        list <cMedico*> ListaMedicos;
        list <cPaciente*> ListaPacientes;
};

#endif // CHOSPITAL_H
