#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>
#include <QLineEdit>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class JanelaPrincipal; }
QT_END_NAMESPACE

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    JanelaPrincipal(QWidget *parent = nullptr);
    ~JanelaPrincipal();

private slots:
    void on_btnsobre_clicked();

private:
    Ui::JanelaPrincipal *ui;
    time_t timer;
    struct tm *horario_local;

    void acender(QLineEdit *e);
    void apagar(QLineEdit *e);
    int* pegarBits ();
    void ligarBits();

};
#endif // JANELAPRINCIPAL_H
