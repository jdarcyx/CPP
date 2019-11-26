#include "str2hex.h"
#include <string>
#include <QApplication>
#include <iostream>

void modHexStr (QString *p) {
    QString aux = "";
    int tam = p->size();

    p->append("{");

    for (int i = 0;i < tam;i++) {
        aux.sprintf(" 0x%2X", p->at(i));
        p->append(aux);
        if (i < tam-1)
            p->append(0x2c);
    }

    p->remove(0,tam);
    p->append(", 0x00 }");

}
