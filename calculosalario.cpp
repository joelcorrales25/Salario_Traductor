#include "calculosalario.h"

QString CalculoSalario::getJornada()
{
    QString str;
    switch(trabajador->jornada())
    {
    case 'V':
        str = tr("Vespertina");
        break;
    case 'M':
        str = tr("Matutina");
        break;
    case 'N':
        str = tr("Nocturna");
        break;
    }
    return str;
}
CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent)
{

}
CalculoSalario::CalculoSalario(Obrero &trabajador)
{
    this->trabajador = &trabajador;
}

QString CalculoSalario::resultado()
{
    QString str;
    str = tr("Obrero ") + trabajador->nombreObrero() + "\n";
    str += tr("Horas: ") + QString::number(trabajador->horasAsignadas()) + "\n";
    str += tr("Jornada: ") + getJornada() + "\n";
    str += tr("Salario Bruto: $") + QString::number(m_salarioBruto) + "\n";
    str += tr("Descuento: $") + QString::number(m_descuento) + "\n";
    str += tr("Salario Neto: $") + QString::number(m_salarioNeto) + "\n\n";
    return str;
}

void CalculoSalario::calcular()
{
    float valorHora = 0;
    switch(trabajador->jornada())
    {
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }

    m_salarioBruto = trabajador->horasAsignadas() * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO/100;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

float CalculoSalario::salarioBruto() const
{
    return m_salarioBruto;
}

float CalculoSalario::descuento() const
{
    return m_descuento;
}

float CalculoSalario::salarioNeto() const
{
    return m_salarioNeto;
}

bool CalculoSalario::guardarControlador(QString texto)
{
    if(trabajador->guardar(texto)){

        return true;
    }else{
        QMessageBox::warning(nullptr, tr("Salarios"), tr("No se puede guardar el archivo"));
        return false;
    }
}

QString CalculoSalario::abrirControlador()
{
    return trabajador->abrir();

}
