#ifndef CANPA_H
#define CANPA_H
#include "cregistrosanpa.h"
#include "chospital.h"
#include "cfabricante.h"
#include "cortopedia.h"
#include "cprotesis.h"



class cANPA
{
    public:
    cANPA(string direccion, list<cRegistrosANPA*> listaRegistros, list<cHospital*> listaHospitales); //constructor

        list<cRegistrosANPA*> get_ListaRegistros() const;
        list<cHospital*> get_ListaHospitales() const;
        const string get_direccion() const;
        bool chequearStockProtesis(cProtesis& protesis);
        bool solicitar_protesis_fabricante(); //le pide al fabricante que haga la protesis

        void Entregar_Protesis(cPaciente paciente, cProtesis &protesisPaciente);
        void AgregarRegistroPaciente(cRegistrosANPA pacienteNuevo); //usa sobrecarga del +

        cPaciente BuscarPacXHospital(cHospital hospitalPaciente); //usa sobrecarga del ==

        const string ListarRegistros() const;
        const string ListarHospitales() const;

        const string to_string() const;
        void imprimir();

        void operator+(cRegistrosANPA &registroNuevo);
        void operator-(cRegistrosANPA &registroBorrar);

        void operator+(cHospital &HospitalNuevo);
        void operator-(cHospital &HospitalBorrar);

        friend bool cFabricante::darRtaSobreProtesis();

        ~cANPA();
        //Imprimir un listado de pacientes y prótesis.

    private:
        const string direccion;
        list<cRegistrosANPA*> ListaRegistros;
        list<cHospital*> ListaHospitales;
        list<cRegistrosANPA*> ListaRegistrosProtesisEntregadas;
        list<cRegistrosANPA*> ListaRegistrosProtesisSolicitadas;


};

#endif // CANPA_H
