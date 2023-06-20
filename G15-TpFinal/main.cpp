
#include <QApplication>
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <QDate>
#include <QRandomGenerator> //libreria random QT
using namespace std;

#include "funcionesmain.h"


int main()
{

   // cANPA* ANPA = new cANPA("Acoyte 2456");

    /////////// CREO PROTESIS ///////////

    //prot 1
    cNoQuirurgicas *Protesis1 = new cNoQuirurgicas(FuncionesMain::crearProtesisNQ());

    //prot 2
    cQuirurgicas *Protesis2 = new cQuirurgicas(FuncionesMain::crearProtesisQ());

    //prot 3
    cNoQuirurgicas *Protesis3 = new cNoQuirurgicas(FuncionesMain::crearProtesisNQ());


    //prot 4
    cQuirurgicas *Protesis4 = new cQuirurgicas(FuncionesMain::crearProtesisQ());

    /////////// CREO PACIENTES ///////////

    list<cPaciente*> *ListaPac = new list<cPaciente*>;

    //pac1
    cPaciente *Paciente1 = new cPaciente(FuncionesMain::crearPaciente(*Protesis1));

    //pac 2
    cPaciente *Paciente2 = new cPaciente(FuncionesMain::crearPaciente(*Protesis2));

    //pac 3
    cPaciente *Paciente3 = new cPaciente(FuncionesMain::crearPaciente(*Protesis3));

    //pac 4
    cPaciente *Paciente4 = new cPaciente(FuncionesMain::crearPaciente(*Protesis4));


    /////////// CREO HOSPITALES ///////////

    //Hosp 1
    cHospital *Hospital1 = new cHospital(FuncionesMain::crearHospital());

    //Hospital1->ListaPacientes+*Paciente1;

    //HACER FUNCIONES PROBANDOOOO

    delete Protesis1;
    delete Protesis2;
    delete Protesis3;
    delete Protesis4;

    delete Paciente1;
    delete Paciente2;
    delete Paciente3;
    delete Paciente4;


    return 0;
}
