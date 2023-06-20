#ifndef CPACIENTE_H
#define CPACIENTE_H
#include "cpersona.h" //librerias ya incluidas en persona.h
#include "cnoquirurgicas.h"
#include "cquirurgicas.h"


class cPaciente: public cPersona
{
public:
    cPaciente(string nombre, string apellido, string dni, QDateTime fechaNac, string telefono, list <string> alergias, string HospitAlatentido, float RadioMiembro, bool PermisoProtesis, cProtesis Protesis);

    void set_telefono(string telefono);
    const string get_telefono() const;

    void set_alergias(list<string> alergias);
    const list <string> get_alergias() const;

    void set_hospitalatendido(string hospitalatendido);
    const string get_hospitalatendido() const;

    void set_radio(float radio);
    const float get_radiomiembro() const;

    void set_permisoprotesis(bool permiso);
    const bool get_permisoprotesis() const;

    void set_protesis(cProtesis protesis);
    const cProtesis get_protesis() const;

    const QDateTime get_fechanac() const;

    string ListarAlergias() const;
    const string to_string() const;
    void imprimir();

    bool operator==(const cPaciente &PacienteAComparar);

    friend ostream& operator<<(ostream& os, const string& PacienteImprimir);
    void operator+(string &AlergiaNueva); //sobrecargas de alergias
    void operator-(string &AlergiaBorrar);

    ~cPaciente();


protected:
    const QDateTime FechaNac;
    string Telefono;
    list <string> Alergias;
    string HospitalAtendido;
    float RadioMiembro; // 0 si no tiene nada amputado
    bool PermisoProtesis;
    cProtesis Protesis;

};

ostream& operator<<(ostream& os, const cPaciente& PacienteImprimir);


#endif // CPACIENTE_H
