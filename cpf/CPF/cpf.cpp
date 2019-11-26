#include <QApplication>
#include <stdbool.h>
#include <cstdlib>
#include "cpf.h"
#include <iostream>
#include <random>
#include <string>


int *dgCalc (std::string cpf)
{
    int *acpf = new int[TCPF];
    int *dg = new int[2];
    std::string aux;

    *(acpf+TCSD) = 0;
    *(acpf+TC1D) = 0;

    for (size_t i = 0;i < cpf.size();i++)
        if ((cpf[i] != '.') && (cpf[i] != '-'))
            aux.append(1, cpf[i]);

    *dg = -1;
    *(dg+1) = -1;

    if (aux.size() != TCSD)
    {
        delete[] acpf;
        return dg;
    }

    for (size_t i = 0;i<aux.size();i++)
        *(acpf+i) = aux.at(i) - ASCII_OFFSET;

    // 1º DV
    for (int i = 0;i < TCSD;i++)
        *(acpf+TCSD) += *(acpf+i) * (i+1);

    *(acpf+TCSD) %= 11;
    if (*(acpf+TCSD) == 10) *(acpf+TCSD) = 0;

    // 2º DV
    for (int i = 0;i < TC1D;i++)
        *(acpf+TC1D) += *(acpf+i) * i;

    *(acpf+TC1D) %= 11;
    if (*(acpf+TC1D) == 10) *(acpf+TC1D) = 0;

    // Retorno
    *dg = *(acpf+9);
    *(dg+1) = *(acpf+10);

    delete[] acpf;
    acpf = nullptr;

    return dg;
}

bool cpfValido (std::string cpf)
{
    int *dg = dgCalc(cpf.substr(0,cpf.size()-2));
    return (*dg == (cpf.at(12) - ASCII_OFFSET)) && (*(dg+1) == (cpf.at(13) - ASCII_OFFSET));
}

int32_t numeroAleatorio (void)
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(MIN_RAND_V, MAX_RAND_V);

    return distr(eng);
}

std::string *gerarCpf (int qtde)
{
    std::string *p, *ret = new std::string[qtde];
    std::string tmp;
    int *dg;

    for (int i = 0;i < qtde;i++)
    {
        do {
            tmp = std::to_string(numeroAleatorio());
        } while (tmp.size() < TCSD);

        *(ret+i) = tmp;
        p = (ret+i);
        dg = dgCalc(*p);
        p->append(std::to_string(*dg));
        p->append(std::to_string(*(dg+1)));

    }

    p = nullptr;
    delete[] dg;
    return ret;
}

