#ifndef CFABRICANTE_H
#define CFABRICANTE_H
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <QRandomGenerator> //libreria random QT
using namespace std;

class cFabricante
{
    public:
        cFabricante(string nombre, string direccion, string numeroHabilitacion);
        cFabricante();
        string get_nombre();
        string get_direccion();
        string get_NroHabilitacion();

        const string to_string();
        void imprimir();

        bool darRtaSobreProtesis();

        ~cFabricante();

    private:
        const string nombre;
        const string direccion;
        const string numeroHabilitacion;


};

#endif // CFABRICANTE_H
