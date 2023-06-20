#ifndef CPERSONA_H
#define CPERSONA_H
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <QDateTime>
using namespace std;

class cPersona
{
    public:
        cPersona(string nombre,string apellido,string dni);
        const string get_nombre() const;
        const string get_apellido() const;
        const string get_DNI() const;

        virtual const string to_string() const;
        virtual void imprimir();

       virtual ~cPersona();

    protected:
        const string Nombre;
        const string Apellido;
        const string DNI;
};

#endif // CPERSONA_H
