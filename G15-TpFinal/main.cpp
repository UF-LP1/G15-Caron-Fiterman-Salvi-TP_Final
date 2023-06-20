
#include <QApplication>
#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <QDate>
using namespace std;

#include "canpa.h"
#include "cortopedia.h"
#include "cfabricante.h"

int main()
{
    cout<<"hola"<<endl;


    cProtesis protesisPrueba(10.5, 3.2, QDate(2023, 6, 18), "Fabricante A", TipoProtesis::SuperiorIzquierda, "Material X");

    cout<<protesisPrueba<<endl;

    return 0;
}
