#include "sobre.h"
#include "ui_sobre.h"

Sobre::Sobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sobre)
{
    ui->setupUi(this);
}

Sobre::~Sobre()
{
    delete ui;
}

void Sobre::on_btnok_clicked()
{
    this->close();

}
