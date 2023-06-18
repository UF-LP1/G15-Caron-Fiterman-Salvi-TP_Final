#ifndef CORTOPEDIA_H
#define CORTOPEDIA_H
using namespace std;

#include "cprotesis.h"

class cOrtopedia
{
    public:
        cOrtopedia(string nombre, string direccion, list<cProtesis*> ListaProtesis);
        const string get_nombre();
        const string get_direccion();
        const list <cProtesis*> get_ListaProtesis();
        void set_ListaProtesis(list <cProtesis*> listaNueva);

        const string to_string();
        void imprimir();

        ~cOrtopedia();

        static int StockSupIzqQ;
        static int StockSupDerQ;
        static int StockInfIzqQ;
        static int StockInfDerQ;
        static int StockSupIzqNQ;
        static int StockSupDerNQ;
        static int StockInfIzqNQ;
        static int StockInfDerNQ; //son publicos para que las otras clases puedan acceder

    private:
        const string Nombre;
        const string Direccion;
        list <cProtesis*> ListadoProtesis;


        //FALTA STOCK!!!!!!!!!!

};

#endif // CORTOPEDIA_H
