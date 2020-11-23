#ifndef CLASS_LIB_H
#define CLASS_LIB_H

#include <iostream>
#include <string.h>

class data{
public:
    data (unsigned int dia, unsigned int mes, unsigned int ano); 

    void set_dia(unsigned int dia);
    void set_mes(unsigned int mes);
    void set_ano(unsigned int ano);

    unsigned int get_dia() const;
    unsigned int get_mes() const;
    unsigned int get_ano() const;

    void print() const;

private:
    unsigned int dia = 0;
    unsigned int mes = 0;
    unsigned int ano = 0;

    void data_invalida();
    bool bissexto();
};

class lote;
class produtos;
class parque;

class bandeira;
class maquina_de_cartao;
class forma_pagamento;

class cliente;
class consiguinado;
class vendas;











   

#endif
