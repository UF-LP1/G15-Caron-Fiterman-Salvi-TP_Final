#ifndef CQUIRURGICAS_H
#define CQUIRURGICAS_H

#include "cprotesis.h"
class cPaciente;

class cQuirurgicas : public cProtesis
{
    public:
        cQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis , string material);
        cQuirurgicas(const cQuirurgicas &copia); //constructor por copia

        const string get_material()const;
        void set_material(string Material);

        void ajustarImplante(float radio, float largo);
        //usa el to_string e imprimir de cProtesis, como son iguales no los hicimos virtual
        ~cQuirurgicas();


};

#endif // CQUIRURGICAS_H
