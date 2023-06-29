#include "funcionesmain.h"

FuncionesMain::FuncionesMain() {}

float FuncionesMain:: ArrRadio[15]= {0.0, 1.0, 5, 2.0, 2, 5, 3.0, 3, 5, 5.0, 5, 6.0, 6.5, 7.0, 7.5};
string FuncionesMain:: ArrAlergias[6]={"titanio", "polietileno", "aleaciones de cobalto", "fibra de carbono", "ceramica", "acero inoxidable"};
string FuncionesMain:: ArrMateriales[6]={"titanio", "polietileno", "aleaciones de cobalto", "fibra de carbono", "ceramica", "acero inoxidable"};
string FuncionesMain:: ArrNombres[10]={"Pampa", "Ezequiel", "Cindy", "Fran", "Sol", "Mailen", "Abi", "Steph", "Beatriz", "Carlos"};
string FuncionesMain:: ArrApellido [10]= {"Perez", "Lopez", "Martinez", "Guitierrez", "Fernandez", "Sanchez", "Allende", "Leal", "Salinas", "Michelli"};
string FuncionesMain:: ArrDNI[10]={"83745129", "54289637", "91037462", "65829317", "42678193", "75392048", "61938475", "28475931", "16523948", "48329657"};
string FuncionesMain:: ArrMatricula [10]= {"A8X2F6G4", "B3Y9H2K7", "C6Z5J1M3", "D9V4N7P2", "E2R6Q8S1", "F7U3T9W5", "G4X1V3Y9", "H1Z5W7R4", "I5M3K9N2", "J8L2P6Q9"};
string FuncionesMain:: ArrNroHabilitacion[10]= {"A8X2F6G4", "B3Y9H2K7", "C6Z5J1M3", "D9V4N7P2", "E2R6Q8S1", "F7U3T9W5", "G4X1V3Y9", "H1Z5W7R4", "I5M3K9N2", "J8L2P6Q9"};
string FuncionesMain:: ArrDire[10]= {"Calle Primavera 123", "Avenida del Bosque 456", "Calle Rosa Blanca 789", "Calle del Sol 321", "Avenida Principal 654", "Calle del Lago 987", "Avenida del Parque 234", "Calle del Roble 567", "Avenida del Mar 890", "Calle del Arco Iris 432"};
float FuncionesMain:: ArrLargo[15]= {0.0, 20.0, 20.5, 22.0, 22.5, 24.0, 24.5, 26.0, 26.5, 28.0, 28.5, 30.0, 30.5, 32.0, 32.5};
string FuncionesMain:: ArrHospitales [4] = {"Hospital Favaloro", "Hospital Italiano","Hospital Aleman", "Hospital Britanico"};
QDate FuncionesMain::ArrFecha[10] = {
    QDate(2022, 2, 13),
    QDate(2023, 6, 27),
    QDate(2020, 12, 4),
    QDate(2022, 7, 11),
    QDate(2023, 4, 2),
    QDate(2021, 10, 31),
    QDate(2022, 7, 15),
    QDate(2025, 3, 22),
    QDate(2023, 5, 10),
    QDate(2024, 1, 5)
};
string FuncionesMain:: ArrTelefono[10]= {"+1 555-123-4567", "+44 20 5555 6789", "+61 2 5555 1234", "+33 1 5555 9876", "+49 30 5555 4321", "+52 55 5555 7890", "+39 06 5555 2468", "+91 11 5555 1357", "+27 11 5555 8023", "+81 3 5555 5709"};
string FuncionesMain:: ArrOrto[3]= {"Ortopedia Nueva Vida", "Ortopedia Camina Hacia el Futuro", "Centro Ortopedico Privado"};
string FuncionesMain:: ArrFabri[3]= {"Meditech Solutions", "BioPro OrthoTech", "Innovex Medical Devices"};

cPaciente FuncionesMain::crearPaciente(cProtesis &Protesis){
    int randNombre= QRandomGenerator::global()->bounded(10);
    int randApe= QRandomGenerator::global()->bounded(10);
    int randDNI= QRandomGenerator::global()->bounded(10);
    int randFecha1= QRandomGenerator::global()->bounded(10);
    int randTelefono= QRandomGenerator::global()->bounded(10);
    int randMedico= QRandomGenerator::global()->bounded(10);
    int cuantasAlergias= QRandomGenerator::global()->bounded(6);

    list<string> AlergiasAux;
    for(int j=0; j<cuantasAlergias; j++){

        int randAlergia= QRandomGenerator::global()->bounded(6);
        AlergiasAux.push_back(ArrAlergias[randAlergia]);
    }

    int randHospital= QRandomGenerator::global()->bounded(4);
    int randRadio= QRandomGenerator::global()->bounded(15);
    bool randPermiso= QRandomGenerator::global()->bounded(2);

    cPaciente* Paciente1 = new cPaciente(ArrNombres[randNombre],ArrApellido[randApe], ArrDNI[randDNI],ArrFecha[randFecha1], ArrTelefono[randTelefono],ArrMatricula[randMedico],AlergiasAux,ArrHospitales[randHospital], ArrRadio[randRadio], randPermiso, Protesis);

    return *Paciente1;

}

cNoQuirurgicas FuncionesMain:: crearProtesisNQ(){
    int randLargo=QRandomGenerator::global()->bounded(15);
    int randRadio= QRandomGenerator::global()->bounded(15);
    int randFabricante=QRandomGenerator::global()->bounded(3);
    int randTipoProte=QRandomGenerator::global()->bounded(5);
    int randMaterial=QRandomGenerator::global()->bounded(6);

    TipoProtesis tipoProtesis = static_cast<TipoProtesis>(randTipoProte);


    cNoQuirurgicas *Protesis=new cNoQuirurgicas(ArrLargo[randLargo],ArrRadio[randRadio], QDate(QDate::currentDate()), ArrFabri[randFabricante], tipoProtesis, ArrMateriales[randMaterial]);

    return *Protesis;
}


cQuirurgicas FuncionesMain:: crearProtesisQ(){
    int randLargo=QRandomGenerator::global()->bounded(15);
    int randRadio= QRandomGenerator::global()->bounded(15);
    int randFabricante=QRandomGenerator::global()->bounded(3);
    int randTipoProte=QRandomGenerator::global()->bounded(5);
    int randMaterial=QRandomGenerator::global()->bounded(6);

    TipoProtesis tipoProtesis = static_cast<TipoProtesis>(randTipoProte);

    cQuirurgicas *Protesis=new cQuirurgicas(ArrLargo[randLargo],ArrRadio[randRadio], QDate(QDate::currentDate()), ArrFabri[randFabricante], tipoProtesis, ArrMateriales[randMaterial]);

    return *Protesis;
}


cHospital FuncionesMain::crearHospital(){

    int randHospital=QRandomGenerator::global()->bounded(4);
    int randDire=QRandomGenerator::global()->bounded(10);

    cHospital* Hospital1= new cHospital(ArrHospitales[randHospital],ArrDire[randDire]);

    return *Hospital1;

}


cMedico FuncionesMain::crearMedico(){

    int randNombre= QRandomGenerator::global()->bounded(10);
    int randApe= QRandomGenerator::global()->bounded(10);
    int randDNI= QRandomGenerator::global()->bounded(10);
    int randMatricula= QRandomGenerator::global()->bounded(10);

    cMedico *Medico1 = new cMedico(ArrNombres[randNombre],ArrApellido[randApe], ArrDNI[randDNI],ArrMatricula[randMatricula]);

    return *Medico1;

}

cRegistrosANPA FuncionesMain::crearRegistro(cProtesis &piezaOrtopedica){

    int randDNI = QRandomGenerator::global()->bounded(10);
    int randHos = QRandomGenerator::global()->bounded(10);
    int randMed = QRandomGenerator::global()->bounded(10);
    int randFecha1 = QRandomGenerator::global()->bounded(10);
    int randFecha2 = QRandomGenerator::global()->bounded(10);
    int randFecha3 = QRandomGenerator::global()->bounded(10);
    EstadoProtesis estado;

    cRegistrosANPA *Registro1 = new cRegistrosANPA(ArrDNI[randDNI], ArrHospitales[randHos], ArrNombres[randMed], ArrFecha[randFecha1], ArrFecha[randFecha2], ArrFecha[randFecha3], piezaOrtopedica, estado);

    return *Registro1;
}

cOrtopedia FuncionesMain::crearOrtopedia(){
    int randOrto=QRandomGenerator::global()->bounded(3);
    int randDire=QRandomGenerator::global()->bounded(10);

    unsigned int randStockSupIzqQ=QRandomGenerator::global()->bounded(10);
    unsigned int randStockSupDerQ=QRandomGenerator::global()->bounded(10);
    unsigned int randStockInfIzqQ=QRandomGenerator::global()->bounded(10);
    unsigned int randStockInfDerQ=QRandomGenerator::global()->bounded(10);

    unsigned int randStockSupIzqNQ=QRandomGenerator::global()->bounded(10);
    unsigned int randStockSupDerNQ=QRandomGenerator::global()->bounded(10);
    unsigned int randStockInfIzqNQ=QRandomGenerator::global()->bounded(10);
    unsigned int randStockInfDerNQ=QRandomGenerator::global()->bounded(10);

    cOrtopedia* Ortopedia1=new cOrtopedia(ArrOrto[randOrto],ArrDire[randDire] , randStockSupIzqQ, randStockSupDerQ,
                                            randStockInfIzqQ, randStockInfDerQ, randStockSupIzqNQ,
                                            randStockSupDerNQ, randStockInfIzqNQ, randStockInfDerNQ);

    return *Ortopedia1;
}

cFabricante FuncionesMain:: crearfabricante(){
    int randFabri=QRandomGenerator::global()->bounded(3);
    int randDire=QRandomGenerator::global()->bounded(10);
    int randN_Habi=QRandomGenerator::global()->bounded(10);

    cFabricante* Fabricante1=new cFabricante(ArrFabri[randFabri],ArrDire[randDire],ArrNroHabilitacion[randN_Habi]);

    return *Fabricante1;
}
