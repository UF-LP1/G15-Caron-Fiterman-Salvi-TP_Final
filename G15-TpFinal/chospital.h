#ifndef CHOSPITAL_H
#define CHOSPITAL_H
#include "cmedico.h"
#include "cpaciente.h"
#include <string>
#include <iostream>
#include <list>
#include <QDateTime>
using namespace std;

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

        const string to_string();
        void imprimir();

        ~cHospital();

    private:
        const string Nombre;
        const string Direccion;
        list <cMedico*> ListaMedicos;
        list <cPaciente*> ListaPacientes;
};

#endif // CHOSPITAL_H