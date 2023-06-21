
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
        if(Protesis1==nullptr){
            return 1;
        }
    //prot 2
    cQuirurgicas *Protesis2 = new cQuirurgicas(FuncionesMain::crearProtesisQ());
        if(Protesis2==nullptr){
            return 1;
        }
    //prot 3
    cNoQuirurgicas *Protesis3 = new cNoQuirurgicas(FuncionesMain::crearProtesisNQ());
        if(Protesis3==nullptr){
            return 1;
        }

    //prot 4
    cQuirurgicas *Protesis4 = new cQuirurgicas(FuncionesMain::crearProtesisQ());
        if(Protesis4==nullptr){
            return 1;
        }


    /////////// CREO PACIENTES ///////////

    //pac 1
    cPaciente *Paciente1 = new cPaciente(FuncionesMain::crearPaciente(*Protesis1));
        if(Paciente1==nullptr){
            return 1;
        }

    //pac 2
    cPaciente *Paciente2 = new cPaciente(FuncionesMain::crearPaciente(*Protesis2));
        if(Paciente2==nullptr){
            return 1;
        }

    //pac 3
    cPaciente *Paciente3 = new cPaciente(FuncionesMain::crearPaciente(*Protesis3));
        if(Paciente3==nullptr){
            return 1;
        }

    //pac 4
    cPaciente *Paciente4 = new cPaciente(FuncionesMain::crearPaciente(*Protesis4));
        if(Paciente4==nullptr){
            return 1;
        }


    /////////// CREO MEDICOS ///////////
    //Med 1
    cMedico *Medico1 = new cMedico(FuncionesMain::crearMedico());
        if(Medico1==nullptr){
             return 1;;
        }

    //Med 2
    cMedico *Medico2 = new cMedico(FuncionesMain::crearMedico());
        if(Medico2==nullptr){
             return 1;;
        }
    //Med 3
    cMedico *Medico3 = new cMedico(FuncionesMain::crearMedico());
        if(Medico3==nullptr){
             return 1;;
        }
    //Med 4
    cMedico *Medico4 = new cMedico(FuncionesMain::crearMedico());
        if(Medico4==nullptr){
             return 1;;
        }

    /////////// CREO HOSPITALES ///////////

    //Hosp 1
    cHospital *Hospital1 = new cHospital(FuncionesMain::crearHospital());
        if(Hospital1==nullptr){
             return 1;;
        }

    *Hospital1+(*Paciente1); //agrego los pac a la lista
    *Hospital1+(*Paciente3);
    *Hospital1+(*Paciente4);

    *Hospital1+(*Medico1); //agrego los med a la lista
    *Hospital1+(*Medico2);
    *Hospital1+(*Medico4);

    //Hosp 2
    cHospital *Hospital2 = new cHospital(FuncionesMain::crearHospital());
    if(Hospital2==nullptr){
             return 1;;
    }

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
   //cRegistrosANPA *RegistroANPA1 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis1));

    //Reg 2
   // cRegistrosANPA *RegistroANPA2 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis2));

    //Reg 3
   // cRegistrosANPA *RegistroANPA3 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis3));

    //Reg 4
   // cRegistrosANPA *RegistroANPA4 = new cRegistrosANPA(FuncionesMain::crearRegistro(*Protesis4));

    cRegistrosANPA *RegistroANPA1 = new cRegistrosANPA("83745129", "Hospital Favaloro","A8X2F6G4",  QDate(2022, 2, 13),QDate(2023, 6, 27), QDate(2022, 7, 11),*Protesis1, EstadoProtesis::Entregada);
    cRegistrosANPA *RegistroANPA2 = new cRegistrosANPA("65829317", "Hospital Italiano","D9V4N7P2", QDate(2021, 10, 31),QDate(2022, 7, 15), QDate(2023, 4, 2),*Protesis1, EstadoProtesis::Entregada);
    cRegistrosANPA *RegistroANPA3 = new cRegistrosANPA("91037462", "Hospital Italiano","F7U3T9W5", QDate(2022, 7, 15),QDate(2022, 7, 15), QDate(2022, 7, 11),*Protesis1, EstadoProtesis::Entregada);
    cRegistrosANPA *RegistroANPA4 = new cRegistrosANPA("75392048", "Hospital Aleman","H1Z5W7R4", QDate(2021, 10, 31),QDate(2022, 7, 15), QDate(2023, 4, 2),*Protesis1, EstadoProtesis::Entregada);

    if(RegistroANPA1==nullptr ||RegistroANPA2==nullptr || RegistroANPA3==nullptr || RegistroANPA4==nullptr){
             return 1;;
    }
    /////////// CREO ANPA ///////////

    cANPA* ANPA = new cANPA("Acoyte 2456");
    if(ANPA==nullptr){
             return 1;;
    }

    *ANPA+(*RegistroANPA1); //agrego todos los registros
    *ANPA+(*RegistroANPA2);
    *ANPA+(*RegistroANPA3);
    *ANPA+(*RegistroANPA4);

    *ANPA+(*Hospital1); //agrego todos los hospitales
    *ANPA+(*Hospital2);

    /////////// CREO ORTOPEDIAS ///////////

    //ortopedia 1
    cOrtopedia *Ortopedia1 = new cOrtopedia(FuncionesMain::crearOrtopedia());
    if(Ortopedia1==nullptr){
             return 1;;
    }
    //ortopedia 2
    cOrtopedia *Ortopedia2 = new cOrtopedia(FuncionesMain::crearOrtopedia());
    if(Ortopedia2==nullptr){
             return 1;;
    }
    /////////// CREO FABRICANTE ///////////

    //fabri 1
     cFabricante *Fabricante1 = new cFabricante(FuncionesMain::crearfabricante());
    if(Fabricante1==nullptr){
             return 1;;
    }
    //fabri 2
    cFabricante *Fabricante2 = new cFabricante(FuncionesMain::crearfabricante());
    if(Fabricante2==nullptr){
             return 1;;
    }


    /////////// PRUEBO FUNCIONES ///////////

    //funciones ANPA
    bool aux;
    try{
        aux=ANPA->chequearStockProtesis(*Protesis3);
        cout<<"Stock: "<<aux<<endl;

        aux=ANPA->chequearStockProtesis(*Protesis4);
        cout<<"Stock: "<<aux<<endl; //es un bool, imprime 0 o 1

        ANPA->Entregar_Protesis(*Paciente2,*Protesis1); //si no tira exception esta ok
        ANPA->imprimir();

        cout<<"EN PAC 5"<<endl;
        cPaciente *Paciente5 = new cPaciente(ANPA->BuscarPacXHospital("54289637"));
        cout<<*Paciente5<<endl;

        cout<<"EN PAC 6"<<endl;
        cPaciente *Paciente6 = new cPaciente(ANPA->BuscarPacXHospital("83745129"));
        cout<<*Paciente6<<endl;

    }catch(PacNoEncontrado *e){
        cout<<e->what()<<endl;
        delete e;
    }


    //funciones medico
    Medico1->dar_permiso_protesis(*Paciente2);
    Medico3->dar_permiso_protesis(*Paciente1);
    Medico4->imprimir();

    //funciones fabricante
    Fabricante1->imprimir();
    aux=Fabricante2->darRtaSobreProtesis();
    cout<< "rta protesis:"<<aux<<endl;

    //funciones hospital
    *Hospital1-(*Medico4); //elimino el medico4 de la lista de medicos en hosp
    *Hospital1-(*Paciente2); //idem pero para paciente
        if(Hospital1==Hospital2){
            cout<<"hospitales son iguales"<<endl;
        }
        else{
            cout<<"hospitales no iguales"<<endl;
        }

    //funciones protesis
        try{
             *Protesis2 = *Protesis4;
        }catch(ErrorIgual *e){
             cout<<e->what()<<endl;
             delete e;
        }

        Protesis1->imprimir();




    //Funciones paciente
    Paciente3->imprimir(); //usa el de la protesis tambien


    //funciones RegANPA
    if(RegistroANPA1 == RegistroANPA3){
        cout<<"los registros son iguales"<<endl;
    }
    else{
         cout<<"los registros no son iguales"<<endl;
    }

    /////////// BORRO MEM DINAMICA ///////////


    delete Protesis1;
    delete Protesis2;
    delete Protesis3;
    delete Protesis4;

    delete Paciente1;
    delete Paciente2;
    delete Paciente3;
    delete Paciente4;
    //delete Paciente5;
    //delete Paciente5;



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
