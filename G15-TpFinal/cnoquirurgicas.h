#ifndef CNOQUIRURGICAS_H
#define CNOQUIRURGICAS_H

#include "cprotesis.h"


class cNoQuirurgicas : public cProtesis
{
    public:
        cNoQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis , string material);
        cNoQuirurgicas(const cNoQuirurgicas &copia); //constructor por copia

        const string get_material()const;
        void set_material(string Material);

        //usa el to_string e imprimir de cProtesis, como son iguales no los hicimos virtual

        ~cNoQuirurgicas();


};

#endif // CNOQUIRURGICAS_H
