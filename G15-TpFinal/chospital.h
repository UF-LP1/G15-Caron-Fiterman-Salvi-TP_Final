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
        cHospital(string Nombre, string direccion);
        const string get_Nombre() const;
        const string get_Direccion() const;

        void set_ListaMedicos(list<cMedico*> ListaMedicos);
        const list<cMedico*>& get_ListaMedicos() const;

        void set_ListaPacientes(list<cPaciente*> ListaPacientes);
        const list<cPaciente*>& get_ListaPacientes() const;
        list<cPaciente*>::iterator get_BeginListaPacientes();
        list<cPaciente*>::iterator get_EndListaPacientes();

        //void ListarMedicos() const;
        //void ListarPacientes() const;

        const string to_string() const;
        void imprimir();

        void operator+(cPaciente &pacienteNuevo);
        void operator-(cPaciente &pacienteBorrar);
        cPaciente& operator[](unsigned int idx);


        void operator+(cMedico &medicoNuevo);
        void operator-(cMedico &medicoBorrar);
        cMedico& getMedico(unsigned int idx); // no deja sobrecargar dos veces el [] en la clase


        bool operator==(const cHospital &HospitalAComparar);

        ~cHospital();

        friend ostream& operator<<(ostream& os, const cHospital& Hospital); //sobrecarca <<


    private:
        const string Nombre;
        const string Direccion;
        list <cMedico*> ListaMedicos;
        list <cPaciente*> ListaPacientes;
};


#endif // CHOSPITAL_H
