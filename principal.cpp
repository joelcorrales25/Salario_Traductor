#include "principal.h"
#include "ui_principal.h"

#include <QMessageBox>
#include <QtDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Conectar objetos
    connect(ui->actionCalcular, SIGNAL(triggered()),
            this, SLOT(on_cmdCalc_clicked()));
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_cmdCalc_clicked()
{
    this->calcular();
}

void Principal::on_actionCalcular_triggered()
{
    this->on_cmdCalc_clicked();
}

void Principal::calcular()
{
    //Obtener el nombre
    QString nombre = ui->inNombre->text();
    //valida que el nombre no este vacio
    if(nombre.isEmpty())
    {
        QMessageBox::warning(this, tr("Salarios"), tr("No has proporcionado el nombre del obrero"));
        return;
    }
    //Obtiene horas
    int horas = ui->inHoras->value();
    //Obtiene la jornada
    char jornada = '\0';
    if(ui->inMatutina->isChecked())
        jornada = 'M';
    else if(ui->inVespertina->isChecked())
        jornada = 'V';
    else if(ui->inNocturna->isChecked())
        jornada = 'N';
    Obrero *ob = new Obrero(nombre, horas, jornada);
    CalculoSalario *s1 = new CalculoSalario(*ob);
    s1->calcular();
    ui->outResultado->appendPlainText(tr("%1").arg(s1->resultado()));
    this->borrar();
}

void Principal::borrar()
{
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->inNombre->setFocus();
}

void Principal::nuevo()
{
    ui->outResultado->clear();
}

void Principal::guardarArchivo()
{
    QString texto= ui->outResultado->toPlainText();
    if(control.guardarControlador(texto)){
        ui->statusbar->showMessage(tr("Datos almacenados"));
    }
}

void Principal::abrirArchivo()
{
    ui->outResultado->appendPlainText(tr("%1").arg(control.abrirControlador()));

}

void Principal::on_actionNuevo_triggered()
{
    this->nuevo();
}

void Principal::on_actionAcerca_de_triggered()
{
    Acerca *acercaDe = new Acerca(this);
    acercaDe->setVersion(VERSION);
    acercaDe->show();
}

void Principal::on_actionGuardar_triggered()
{
    this->guardarArchivo();
}

void Principal::on_actionAbrir_triggered()
{
    this->abrirArchivo();
}

