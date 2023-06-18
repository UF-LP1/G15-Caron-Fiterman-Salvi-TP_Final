#ifndef CREGISTROSANPA_H
#define CREGISTROSANPA_H
#include <string>
#include <iostream>
#include <list>
#include <QDate>
using namespace std;

enum EstadoProtesis {Entregada = 1, Solicitada};

class cRegistrosANPA
{
    public:
        cRegistrosANPA(string DNI, string hospital, string medico, QDate FSolicitud, QDate FEntrega, QDate FEntregaEstimada, string pieza, EstadoProtesis estado);
        ~cRegistrosANPA();

        const string get_DNIPaciente();

        const string get_Hospital();
        void set_Hospital(string hospital);

        const string get_Medico();
        void set_Medico(string medico);


        const string get_PiezaOrtopedica();
        void set_PiezaOrtopedica(string pieza);

        const QDate get_FechaSolicitud();
        void set_FechaSolicitud(QDate solicitud);

        const QDate get_FechaEntrega();
        void set_FechaEntrega(QDate entrega);

        const QDate get_FechaEntregaEstimada();
        void set_FechaEntregaEstimada(QDate entregaEstimada);

        const EstadoProtesis get_EstadoProtesis();
        void set_EstadoProtesis(EstadoProtesis estado);

        const string to_string();
        void imprimir();

    private:
        const string DNIPaciente;
        string Hospital;
        string Medico;
        QDate FechaSolicitud;
        QDate FechaEntrega;
        QDate FechaEntregaEstimada;
        string piezaOrtopedica;
        EstadoProtesis estadoProtesis;

};

#endif // CREGISTROSANPA_H
