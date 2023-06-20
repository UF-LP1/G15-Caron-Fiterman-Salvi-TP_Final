#ifndef CORTOPEDIA_H
#define CORTOPEDIA_H
using namespace std;

#include "cprotesis.h"
#include "chospital.h"

class cOrtopedia
{
    public:
        cOrtopedia(string nombre, string direccion, list<cProtesis*> ListaProtesis);
        const string get_nombre();
        const string get_direccion();
        const list <cProtesis*> get_ListaProtesis();
        void set_ListaProtesis(list <cProtesis*> listaNueva);

        void operator+(cProtesis &ProtesisNueva);
        void operator-(cProtesis &ProtesisBorrar);
        const string ListarProtesis() const;

        const string to_string();
        void imprimir();

        ~cOrtopedia();

        static unsigned int StockSupIzqQ;
        static unsigned int StockSupDerQ;
        static unsigned int StockInfIzqQ;
        static unsigned int StockInfDerQ;
        static unsigned int StockSupIzqNQ;
        static unsigned int StockSupDerNQ;
        static unsigned int StockInfIzqNQ;
        static unsigned int StockInfDerNQ; //son publicos para que las otras clases puedan acceder y modificarlos
                                           //ej: cuando le asignan la protesis a un paciente se tiene que restar

    private:
        const string Nombre;
        const string Direccion;
        list <cProtesis*> ListadoProtesis;

};

#endif // CORTOPEDIA_H
