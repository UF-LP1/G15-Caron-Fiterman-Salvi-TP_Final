#ifndef CPACIENTE_H
#define CPACIENTE_H
#include"cpersona.h"
#include <string>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <QDateTime>
using namespace std;

class cPaciente: public cPersona
{
public:
    cPaciente(string nombre,string apellido, string dni,QDateTime fechaNac,string telefono,list <string> alergias, string hospitalatentido, float radiomiembro, bool permisoprotesis, cProtesis protesis);
    void set_telefono(string telefono);
    void set_alergias(list<string> alergias);
    void set_hospitalatendido(string hospitalatendido);
    void set_radio(float radio);
    void set_permisoprotesis(bool permiso);
    const QDateTime get_fechanac();
    string get_telefono();
    list <string> get_alergias();
    string get_hospitalatendido();
    const float get_radiomiembro();
    const bool get_permisoprotesis();
    const string  to_string();
    void imprimir();
     ~cPaciente();
protected:
    const QDateTime FechaNac;
    string Telefono;
    list <string> Alergias;
    string HospitalAtendido;
    float RadioMiembro;
    bool PermisoProtesis;
    cProtesis Protesis;

};

#endif // CPACIENTE_H
