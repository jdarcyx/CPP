#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"
#include <ctime>
#include <QTimer>
#include <cstdbool>
#include <iostream>
#include "sobre.h"

#define LED_D "QLineEdit { background-color: white }"
#define LED_L "QLineEdit { background-color: red }"

JanelaPrincipal::JanelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);

    QTimer *t = new QTimer(this);
    connect(t,&QTimer::timeout,this,QOverload<>::of(&JanelaPrincipal::ligarBits));
    t->start(500);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

int* JanelaPrincipal::pegarBits ()
{
    int *bits = new int[4];
    time(&this->timer);
    this->horario_local = localtime(&this->timer);

    *bits = this->horario_local->tm_hour;
    *(bits+1) = this->horario_local->tm_min;

    *(bits+2) = this->horario_local->tm_mday;
    *(bits+3) = this->horario_local->tm_mon;

    return bits;
}


void JanelaPrincipal::acender(QLineEdit *e)
{
    e->setStyleSheet(LED_L);
}

void JanelaPrincipal::apagar(QLineEdit *e)
{
    e->setStyleSheet(LED_D);
}

void JanelaPrincipal::ligarBits()
{
    int *bits = this->pegarBits();
    bool dado = this->ui->rb_hora->QAbstractButton::isChecked();

    if (dado) // HORA
    {
        // DIA
        (*bits & 1)?this->acender(this->ui->edt_h_1):this->apagar(this->ui->edt_h_1);
        (*bits & 2)?this->acender(this->ui->edt_h_2):this->apagar(this->ui->edt_h_2);
        (*bits & 4)?this->acender(this->ui->edt_h_4):this->apagar(this->ui->edt_h_4);
        (*bits & 8)?this->acender(this->ui->edt_h_8):this->apagar(this->ui->edt_h_8);
        (*bits & 16)?this->acender(this->ui->edt_h_16):this->apagar(this->ui->edt_h_16);
        (*bits & 32)?this->acender(this->ui->edt_h_32):this->apagar(this->ui->edt_h_32);

        // MÊS
        (*(bits+1) & 1)?this->acender(this->ui->edt_m_1):this->apagar(this->ui->edt_m_1);
        (*(bits+1) & 2)?this->acender(this->ui->edt_m_2):this->apagar(this->ui->edt_m_2);
        (*(bits+1) & 4)?this->acender(this->ui->edt_m_4):this->apagar(this->ui->edt_m_4);
        (*(bits+1) & 8)?this->acender(this->ui->edt_m_8):this->apagar(this->ui->edt_m_8);
        (*(bits+1) & 16)?this->acender(this->ui->edt_m_16):this->apagar(this->ui->edt_m_16);
        (*(bits+1) & 32)?this->acender(this->ui->edt_m_32):this->apagar(this->ui->edt_m_32);
    }
    else // DATA
    {
        // HORA
        (*(bits+2) & 1)?this->acender(this->ui->edt_h_1):this->apagar(this->ui->edt_h_1);
        (*(bits+2) & 2)?this->acender(this->ui->edt_h_2):this->apagar(this->ui->edt_h_2);
        (*(bits+2) & 4)?this->acender(this->ui->edt_h_4):this->apagar(this->ui->edt_h_4);
        (*(bits+2) & 8)?this->acender(this->ui->edt_h_8):this->apagar(this->ui->edt_h_8);
        (*(bits+2) & 16)?this->acender(this->ui->edt_h_16):this->apagar(this->ui->edt_h_16);
        (*(bits+2) & 32)?this->acender(this->ui->edt_h_32):this->apagar(this->ui->edt_h_32);

        // MINUTO
        (*(bits+3) & 1)?this->acender(this->ui->edt_m_1):this->apagar(this->ui->edt_m_1);
        (*(bits+3) & 2)?this->acender(this->ui->edt_m_2):this->apagar(this->ui->edt_m_2);
        (*(bits+3) & 4)?this->acender(this->ui->edt_m_4):this->apagar(this->ui->edt_m_4);
        (*(bits+3) & 8)?this->acender(this->ui->edt_m_8):this->apagar(this->ui->edt_m_8);
        (*(bits+3) & 16)?this->acender(this->ui->edt_m_16):this->apagar(this->ui->edt_m_16);
        (*(bits+3) & 32)?this->acender(this->ui->edt_m_32):this->apagar(this->ui->edt_m_32);
    }

    delete[] bits;

}

void JanelaPrincipal::on_btnsobre_clicked()
{
    Sobre *s = new Sobre();
    s->exec();
}
