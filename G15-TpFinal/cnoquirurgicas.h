#ifndef CNOQUIRURGICAS_H
#define CNOQUIRURGICAS_H

#include "cprotesis.h"


class cNoQuirurgicas : public cProtesis
{
    public:
        cNoQuirurgicas(float largo, float radio, QDate fechaFabricacion, string fabricante, TipoProtesis infoProtesis , string material, string sujecion);
        cNoQuirurgicas(const cNoQuirurgicas &copia); //constructor por copia

        const string get_material()const;
        void set_material(string Material);

        void cambiarSujecion(string nuevaSujecion); //es como un set
        const string get_sujecion()const;

        ~cNoQuirurgicas();

    private:
        string sujecion;


};

#endif // CNOQUIRURGICAS_H
