
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

    //pac
    cPaciente *Paciente1 = new cPaciente(FuncionesMain::crearPaciente(*Protesis1));

    //pac 2
    cPaciente *Paciente2 = new cPaciente(FuncionesMain::crearPaciente(*Protesis2));

    //pac 3
    cPaciente *Paciente3 = new cPaciente(FuncionesMain::crearPaciente(*Protesis3));

    //pac 4
    cPaciente *Paciente4 = new cPaciente(FuncionesMain::crearPaciente(*Protesis4));


    /////////// CREO MEDICOS ///////////
    //Med 1
    cMedico *Medico1 = new cMedico(FuncionesMain::crearMedico());

    //Med 2
    cMedico *Medico2 = new cMedico(FuncionesMain::crearMedico());

    //Med 3
    cMedico *Medico3 = new cMedico(FuncionesMain::crearMedico());

    //Med 4
    cMedico *Medico4 = new cMedico(FuncionesMain::crearMedico());


    /////////// CREO HOSPITALES ///////////

    //Hosp 1
    cHospital *Hospital1 = new cHospital(FuncionesMain::crearHospital());

    *Hospital1+(*Paciente1); //agrego los pac a la lista
    *Hospital1+(*Paciente3);
    *Hospital1+(*Paciente4);

    *Hospital1+(*Medico1); //agrego los med a la lista
    *Hospital1+(*Medico2);
    *Hospital1+(*Medico4);

    //Hosp 2
    cHospital *Hospital2 = new cHospital(FuncionesMain::crearHospital());

    *Hospital2+(*Paciente1);
    *Hospital2+(*Paciente3);
    *Hospital2+(*Paciente2);
    *Hospital2+(*Paciente3); //no lo deberia agregar porque ya esta en la lista
    *Hospital2+(*Paciente4);

    *Hospital1+(*Medico1);
    *Hospital1+(*Medico3);
    *Hospital1+(*Medico1); //no lo deberia agregar porque ya esta en la lista
    *Hospital1+(*Medico4);

     /////////// CREO REGISTROS ANPA ///////////

    //Reg 1
    cRegistrosANPA *RegistroANPA1 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis1));

    //Reg 2
    cRegistrosANPA *RegistroANPA2 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis2));

    //Reg 3
    cRegistrosANPA *RegistroANPA3 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis3));

    //Reg 4
    cRegistrosANPA *RegistroANPA4 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis4));


    /////////// CREO ANPA ///////////

    cANPA* ANPA = new cANPA("Acoyte 2456");

    *ANPA+(*RegistroANPA1); //agrego todos los registros
    *ANPA+(*RegistroANPA2);
    *ANPA+(*RegistroANPA3);
    *ANPA+(*RegistroANPA4);

    *ANPA+(*Hospital1); //agrego todos los hospitales
    *ANPA+(*Hospital2);

    /////////// CREO ORTOPEDIAS ///////////

    //ortopedia 1
    cOrtopedia *Ortopedia1 = new cOrtopedia(FuncionesMain::crearOrtopedia());

    //ortopedia 2
    cOrtopedia *Ortopedia2 = new cOrtopedia(FuncionesMain::crearOrtopedia());

    /////////// CREO FABRICANTE ///////////

    //fabri 1
     cFabricante *Fabricante1 = new cFabricante(FuncionesMain::crearfabricante());

    //fabri 2
    cFabricante *Fabricante2 = new cFabricante(FuncionesMain::crearfabricante());


    //HACER FUNCIONES PROBANDOOOO

    delete Protesis1;
    delete Protesis2;
    delete Protesis3;
    delete Protesis4;

    delete Paciente1;
    delete Paciente2;
    delete Paciente3;
    delete Paciente4;

    delete Medico1;
    delete Medico2;
    delete Medico3;
    delete Medico4;

    delete Hospital1;
    delete Hospital2;

    delete RegistroANPA1;
    delete RegistroANPA2;
    delete RegistroANPA3;
    delete RegistroANPA4;

    delete ANPA;

    delete Ortopedia1;
    delete Ortopedia2;

    delete Fabricante1;
    delete Fabricante2;

    return 0;
}
