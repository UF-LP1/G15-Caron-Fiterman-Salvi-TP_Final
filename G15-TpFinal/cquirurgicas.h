#ifndef CQUIRURGICAS_H
#define CQUIRURGICAS_H

#include "cprotesis.h"

class cQuirurgicas : public cProtesis
{
    public:
        cQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis , string material);
        cQuirurgicas(const cQuirurgicas &copia); //constructor por copia
        const string get_material();
        void set_material(string Material);

        ~cQuirurgicas();


};

#endif // CQUIRURGICAS_H
