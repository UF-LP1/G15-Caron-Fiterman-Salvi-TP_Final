#ifndef CPROTESIS_H
#define CPROTESIS_H
#include <string>
#include <iostream>
#include <list>
#include <QDate>
#include <sstream>
#include <customexceptions.h>
class cPaciente;

using namespace std;

enum TipoProtesis {SuperiorIzquierda = 1, SuperiorDerecha, InferiorIzquierda, InferiorDerecha};

class cProtesis
{
    public:
        cProtesis(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis, string material);
        cProtesis(const cProtesis &copia); //constructor por copia

        const float get_largo() const;
        void set_largo(float Largo);

        const float get_radio() const;
        void set_radio(float Radio);

        const QDate get_fechaFabricacion() const;
        void set_fechaFabricacion(QDate fecha);

        const string get_fabricante() const;
        void set_fabricante(string fabricante);

        const string get_tipoProtesis() const; //devuelve como string
        const TipoProtesis get_TipoProtesisTipo() const; //devuelve el int
        void set_tipoProtesis(TipoProtesis tipo);

        virtual const string get_material() const;
        virtual void set_material(string Material);

        bool operator==(const cProtesis &ProtesisAComparar) const; //sobrecarga del ==
        void operator=(const cProtesis& protesis); //sobrecarga del =

        friend ostream& operator<<(ostream& os, const cProtesis& ProtesisImprimir);


        const string to_string() const;
        void imprimir();

        virtual ~cProtesis();

    protected:
        float Largo;
        float Radio;
        QDate fechaFabricacion; // mm/dd/yyyy
        string Fabricante;
        TipoProtesis InfoProtesis;
        string Material;
};


#endif // CPROTESIS_H
