#ifndef CMEDICO_H
#define CMEDICO_H
#include "cpersona.h" //librerias ya incluidas en persona.h
#include "cpaciente.h"

class cMedico:public cPersona
{
public:
    cMedico(string nombre,string apellido, string dni,string matricula);

    const string get_matricula() const;

    void dar_permiso_protesis(cPaciente paciente);

    const string to_string() const;
    void imprimir();

    bool operator==(const cMedico &MedicoAComparar);
    friend ostream& operator<<(ostream& os, const cMedico& MedicoImprimir);

    ~cMedico();


protected:
    const string Matricula;
};

ostream& operator<<(ostream& os, const cMedico& MedicoImprimir);

#endif // CMEDICO_H

