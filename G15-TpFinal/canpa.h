#ifndef CANPA_H
#define CANPA_H

#include "cregistrosanpa.h"
#include "chospital.h"



class cANPA
{
    public:
    cANPA(string direccion, list<cRegistrosANPA*> listaRegistros, list<cHospital*> listaHospitales); //constructor

        list<cRegistrosANPA*> get_ListaRegistros() const;
        list<cHospital*> get_ListaHospitales() const;
        const string get_direccion() const;



        void Entregar_Protesis(cPaciente paciente, cProtesis protesisPaciente);
        // le entrega la protesis al paciente, usa la sobrecarga del = para asignarle la protesis
        // Se debe utilizar la sobrecarga del operador "==" para verificar si la prótesis en stock
        // es la que el paciente necesita.
        void AgregarRegistroPaciente(cRegistrosANPA pacienteNuevo); //usa sobrecarga del +
       // cProtesis BuscarProtesisXOrtopedia(cOrtopedia protesisPaciente); //usa sobrecarga del ==
        cPaciente BuscarPacXHospital(cHospital hospitalPaciente); //usa sobrecarga del ==

        const string ListarRegistros() const;
        const string ListarHospitales() const;

        const string to_string() const;
        void imprimir();

        void operator+(cRegistrosANPA &registroNuevo);
        void operator-(cRegistrosANPA &registroBorrar);

        void operator+(cHospital &HospitalNuevo);
        void operator-(cHospital &HospitalBorrar);


        ~cANPA();
//Imprimir un listado de pacientes y prótesis.

    private:
        const string direccion;
        list<cRegistrosANPA*> ListaRegistros;
        list<cHospital*> ListaHospitales;


};

#endif // CANPA_H
