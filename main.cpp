#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Crea un objeto para manejar las traducciones
    QTranslator traduccion;

    QString lenguajeLocal = QLocale::system().name();

    QStringList lenguaje = lenguajeLocal.split("_");

    //Evaluar el idioma por defecto de la computadora
    if(lenguaje.at(0) == "ja")
    {
        traduccion.load(":/Traducciones/Traducciones/Salario_ja_JPN.qm");
    }
    else if(lenguaje.at(0) == "pt"){
        traduccion.load(":/Traducciones/Traducciones/Salario_pt_POR.qm");
    }
    else
        traduccion.load(":/Traducciones/Traducciones/Salario_es_EC.qm");

    //Establecer un idioma a la aplicación
    a.installTranslator(&traduccion);
    Principal w;
    w.show();
    return a.exec();
}
