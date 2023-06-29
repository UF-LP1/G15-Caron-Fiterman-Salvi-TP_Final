#ifndef CORTOPEDIA_H
#define CORTOPEDIA_H
using namespace std;
#include "cnoquirurgicas.h"
#include "cquirurgicas.h"

class cOrtopedia
{
    public:
        cOrtopedia(string nombre, string direccion, list<cProtesis*> ListaProtesis,unsigned int StockSupIzqQ, unsigned int StockSupDerQ,
                   unsigned int StockInfIzqQ, unsigned int StockInfDerQ, unsigned int StockSupIzqNQ,
                   unsigned int StockSupDerNQ,unsigned int StockInfIzqNQ, unsigned int StockInfDerNQ);

        cOrtopedia(string nombre, string direccion,unsigned int StockSupIzqQ, unsigned int StockSupDerQ,
                  unsigned int StockInfIzqQ, unsigned int StockInfDerQ, unsigned int StockSupIzqNQ,
                  unsigned int StockSupDerNQ,unsigned int StockInfIzqNQ, unsigned int StockInfDerNQ);
        const string get_nombre();
        const string get_direccion();
        const list <cProtesis*> get_ListaProtesis();
        void set_ListaProtesis(list <cProtesis*> listaNueva);

        const unsigned int get_StockSupIzqQ() const;
        void  set_StockSupIzqQ(unsigned int StockSupIzqQ);
        const unsigned int get_StockSupDerQ() const;
        void  set_StockSupDerQ(unsigned int StockSupDerQ);
        const unsigned int get_StockInfIzqQ() const;
        void  set_StockInfIzqQ(unsigned int StockInfIzqQ);
        const unsigned int get_StockInfDerQ() const;
        void  set_StockInfDerQ(unsigned int StockInfDerQ);
        const unsigned int get_StockSupIzqNQ() const;
        void  set_StockSupIzqNQ(unsigned int StockSupIzqNQ);
        const unsigned int get_StockSupDerNQ() const;
        void  set_StockSupDerNQ(unsigned int StockSupDerNQ);
        const unsigned int get_StockInfIzqNQ() const;
        void  set_StockInfIzqNQ(unsigned int StockInfIzqNQ);
        const unsigned int get_StockInfDerNQ() const;
        void  set_StockInfDerNQ(unsigned int StockInfDerNQ);
        void operator+(cProtesis &ProtesisNueva);
        void operator-(cProtesis &ProtesisBorrar);

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
