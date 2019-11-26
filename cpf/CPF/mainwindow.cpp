#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cpf.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLineEdit *edt = this->ui->edtcpfchecar;

    connect(this->ui->btncpfchecar,SIGNAL(clicked()),this,SLOT(btncpfchecar()));
    connect(edt,SIGNAL(returnPressed()),this,SLOT(btncpfchecar()));
    connect(this->ui->btncpfgerar,SIGNAL(clicked()),this,SLOT(btncpfgerar()));

    edt->setFocus();
    edt->setCursorPosition(0);

    edt = nullptr;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btncpfchecar (void)
{
    QMessageBox msg;
    QLineEdit *edt = this->ui->edtcpfchecar;

    msg.setText("CPF Inválido!");
    msg.setButtonText(QMessageBox::Ok,"OK");
    msg.setIcon(QMessageBox::Critical);

    if (this->ui->edtcpfchecar->text().toStdString().size() == 14)
        if (cpfValido(this->ui->edtcpfchecar->text().toStdString()))
        {
            msg.setText("CPF Válido!");
            msg.setIcon(QMessageBox::Information);
        }
    edt->setCursorPosition(0);
    msg.exec();

    edt = nullptr;
}

void MainWindow::btncpfgerar (void)
{
    QSpinBox *sb = this->ui->sbcpfquantidade;
    QPlainTextEdit *te = this->ui->tecpfgerado;
    std::string *ret = gerarCpf(sb->value());

    te->setPlainText("");
    for (int i = 0;i < sb->value(); i++)
        te->appendPlainText(QString::fromStdString(*(ret+i)));

    sb = nullptr;
    te = nullptr;
    delete[] ret;
    ret = nullptr;
}
