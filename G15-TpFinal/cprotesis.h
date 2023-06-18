#ifndef CPROTESIS_H
#define CPROTESIS_H
#include <string>
#include <iostream>
#include <list>
#include <QDate>
using namespace std;

 enum TipoProtesis {SuperiorIzquierda = 1, SuperiorDerecha, InferiorIzquierda, InferiorDerecha};

class cProtesis
{
    public:
        cProtesis(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis, string material);
        cProtesis(const cProtesis &copia); //constructor por copia
        const float get_largo();
        void set_largo(float Largo);

        const float get_radio();
        void set_radio(float Radio);

        const QDate get_fechaFabricacion();
        void set_fechaFabricacion(QDate fecha);

        const string get_fabricante();
        void set_fabricante(string fabricante);

        const TipoProtesis get_tipoProtesis();
        void set_tipoProtesis(TipoProtesis tipo);

        virtual const string get_material();
        virtual void set_material(string Material);

        const string to_string();
        void imprimir();

        ~cProtesis();

    protected:
        float Largo;
        float Radio;
        QDate fechaFabricacion; // mm/dd/yyyy
        string Fabricante;
        TipoProtesis InfoProtesis;
        string Material;
};

#endif // CPROTESIS_H
