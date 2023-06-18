#ifndef CMEDICO_H
#define CMEDICO_H
#include "cpaciente.h"
#include "cprotesis.h"


class cMedico:public cPersona
{
public:
    cMedico(string nombre,string apellido, string dni,string matricula);

    const string get_matricula();

    void dar_permiso_protesis(cPaciente paciente, cProtesis prote);
    bool solicitar_protesis_fabricante(cProtesis prote);

    const string to_string();
    void imprimir();

    ~cMedico();


protected:
    const string Matricula;
};

#endif // CMEDICO_H
