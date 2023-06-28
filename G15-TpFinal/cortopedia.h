#ifndef CORTOPEDIA_H
#define CORTOPEDIA_H
using namespace std;
#include "cnoquirurgicas.h"
#include "cquirurgicas.h"

class cOrtopedia
{
    public:
        cOrtopedia(string nombre, string direccion, list<cProtesis*> ListaProtesis);
        cOrtopedia(string nombre, string direccion);
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



    private:
        const string Nombre;
        const string Direccion;
        list <cProtesis*> ListadoProtesis;
        unsigned int StockSupIzqQ;
        unsigned int StockSupDerQ;
        unsigned int StockInfIzqQ;
        unsigned int StockInfDerQ;
        unsigned int StockSupIzqNQ;
        unsigned int StockSupDerNQ;
        unsigned int StockInfIzqNQ;
        unsigned int StockInfDerNQ;

};

#endif // CORTOPEDIA_H
