#ifndef CREGISTROSANPA_H
#define CREGISTROSANPA_H
#include <string>
#include <iostream>
#include <list>
#include <QDate>
#include <sstream>
using namespace std;

enum EstadoProtesis {Entregada = 1, Solicitada};

class cRegistrosANPA
{
    public:
        cRegistrosANPA(string DNI, string hospital, string medico, QDate FSolicitud, QDate FEntrega, QDate FEntregaEstimada, string pieza, EstadoProtesis estado);
        ~cRegistrosANPA();

        const string get_DNIPaciente() const;

        const string get_Hospital() const;
        void set_Hospital(string hospital);

        const string get_Medico() const;
        void set_Medico(string medico);


        const string get_PiezaOrtopedica() const;
        void set_PiezaOrtopedica(string pieza);

        const QDate get_FechaSolicitud() const;
        void set_FechaSolicitud(QDate solicitud);

        const QDate get_FechaEntrega() const;
        void set_FechaEntrega(QDate entrega);

        const QDate get_FechaEntregaEstimada() const;
        void set_FechaEntregaEstimada(QDate entregaEstimada);

        const EstadoProtesis get_EstadoProtesis() const;
        void set_EstadoProtesis(EstadoProtesis estado);

        const string to_string() const;
        void imprimir();

        bool operator==(const cRegistrosANPA &RegistroAComparar);
        friend ostream& operator<<(ostream& os, const cRegistrosANPA& registro);

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

ostream& operator<<(ostream& os, const cRegistrosANPA& registro);

#endif // CREGISTROSANPA_H
