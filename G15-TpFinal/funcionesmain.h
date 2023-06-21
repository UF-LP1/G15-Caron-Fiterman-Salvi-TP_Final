#ifndef FUNCIONESMAIN_H
#define FUNCIONESMAIN_H
#include <QApplication>
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <QDate>
#include <QRandomGenerator> //libreria random QT
using namespace std;
#include "canpa.h"
#include "cortopedia.h"
#include "cfabricante.h"

class FuncionesMain
{
public:
    FuncionesMain();

    static float ArrRadio[15];

    static string ArrAlergias[6];

    static string ArrMateriales[6];

    static string ArrNombres[10];

    static string ArrApellido [10];

    static string ArrDNI[10];

    static string ArrMatricula[10];

    static string ArrNroHabilitacion[10];

    static string ArrDire[10];

    static float ArrLargo[15];

    static string ArrHospitales[4];

    static QDate ArrFecha[10];

    static string ArrTelefono[10];

    static string ArrOrto[3];

    static string ArrFabri[3];

    static cPaciente crearPaciente(cProtesis& Protesis);

    static cNoQuirurgicas crearProtesisNQ();
    static cQuirurgicas crearProtesisQ();

    static cHospital crearHospital();

    static cMedico crearMedico();

    static cRegistrosANPA crearRegistro(cProtesis piezaOrtopedica);

    static cOrtopedia crearOrtopedia();

    static cFabricante crearfabricante();


};



#endif // FUNCIONESMAIN_H
