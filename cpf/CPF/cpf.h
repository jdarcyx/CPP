#ifndef CPF_H
#define CPF_H

#include <QApplication>
#include <cstdbool>

#define TCSD 9
#define TC1D TCSD+1
#define TCPF TC1D+1
#define ASCII_OFFSET 48
#define MIN_RAND_V 000000001
#define MAX_RAND_V 999999999

bool cpfValido (std::string cpf);
std::string *gerarCpf (int qtde);

#endif // CPF_H
