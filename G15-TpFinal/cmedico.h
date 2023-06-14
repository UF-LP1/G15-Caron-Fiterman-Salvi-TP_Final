#ifndef CMEDICO_H
#define CMEDICO_H
#include "cpersona.h"
#include <string>
using namespace std;

class cMedico:public cPersona
{
public:
    cMedico(string nombre,string apellido, string dni,string matricula);
    const string get_matricula();
    void dar_permiso_protesis(cliente,protesis);
    bool solicitar_protesis_fabricante(protesis);
    const string to_string();
    void imprimir();
    ~cMedico();
protected:
    const string Matricula;
};

#endif // CMEDICO_H
