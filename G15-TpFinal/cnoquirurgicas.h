#ifndef CNOQUIRURGICAS_H
#define CNOQUIRURGICAS_H

#include "cprotesis.h"


class cNoQuirurgicas : public cProtesis
{
    public:
        cNoQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis , string material);
        cNoQuirurgicas(const cNoQuirurgicas &copia); //constructor por copia
        const string get_material();
        void set_material(string Material);


        ~cNoQuirurgicas();


};

#endif // CNOQUIRURGICAS_H
