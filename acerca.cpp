#include "acerca.h"
#include "ui_acerca.h"

Acerca::Acerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca)
{
    ui->setupUi(this);
    ui->outVersion->setText(tr(("Version: %1")).arg(VERSION));
}

Acerca::~Acerca()
{
    delete ui;
}

void Acerca::setVersion(const QString &value)
{
    version = value;
    ui->outVersion->setText(tr("Version: %1").arg(version));
}
