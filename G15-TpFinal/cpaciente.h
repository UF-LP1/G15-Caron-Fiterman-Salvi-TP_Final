#ifndef CPACIENTE_H
#define CPACIENTE_H
#include "cpersona.h" //librerias ya incluidas en persona.h
#include "cprotesis.h"


class cPaciente: public cPersona
{
public:
    cPaciente(string nombre, string apellido, string dni, QDateTime fechaNac, string telefono, list <string> alergias, string HospitAlatentido, float RadioMiembro, bool PermisoProtesis, cProtesis Protesis);

    void set_telefono(string telefono);
    const string get_telefono();

    void set_alergias(list<string> alergias);
    const list <string> get_alergias();

    void set_hospitalatendido(string hospitalatendido);
    const string get_hospitalatendido();

    void set_radio(float radio);
    const float get_radiomiembro();

    void set_permisoprotesis(bool permiso);
    const bool get_permisoprotesis();

    const QDateTime get_fechanac();

    const string to_string();
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
