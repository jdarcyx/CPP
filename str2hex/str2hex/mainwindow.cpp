#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include "str2hex.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btngerar,SIGNAL(clicked()),this,SLOT(btnclicked()));
    connect(ui->edttexto,SIGNAL(returnPressed()),this,SLOT(btnclicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnclicked()
{
    QString str = this->ui->edttexto->text();
    if (str.isEmpty())
    {
        this->ui->edthex->setText("");
        return;
    }
    modHexStr(&str);
    this->ui->edthex->setText(str);
}
