#ifndef CHOSPITAL_H
#define CHOSPITAL_H
#include <string>
#include <iostream>
#include <list>
#include <QDateTime>
#include <sstream>
using namespace std;

#include "cpaciente.h"
#include "cmedico.h"

class cHospital
{
    public:
        cHospital();
        const string get_Nombre() const;
        const string get_Direccion() const;

        void set_ListaMedicos(list<cMedico*> ListaMedicos);
        const list<cMedico*> get_ListaMedicos() const;

        void set_ListaPacientes(list<cPaciente*> ListaPacientes);
        const list<cPaciente*> get_ListaPacientes() const;

        const string ListarMedicos() const;
        const string ListarPacientes() const;

        const string to_string() const;
        void imprimir();

        void operator+(cPaciente &pacienteNuevo);
        void operator-(cPaciente &pacienteBorrar);

        void operator+(cMedico &medicoNuevo);
        void operator-(cMedico &medicoBorrar);

        bool operator==(const cHospital &HospitalAComparar);

        ~cHospital();

        friend ostream& operator<<(ostream& os, const cHospital& Hospital); //sobrecarca <<


    private:
        const string Nombre;
        const string Direccion;
        list <cMedico*> ListaMedicos;
        list <cPaciente*> ListaPacientes;
};

ostream& operator<<(ostream& os, const cHospital& Hospital);

#endif // CHOSPITAL_H
