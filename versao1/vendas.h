#ifndef VENDAS_H
#define VENDAS_H

#include <iostream>

#include "data.h"


enum class Forma_de_Pagamento {Cartao_credito, Cartao_debito, Dinheiro};

class Venda{
    friend std::ostream &operator<< (std::ostream &, const Venda & );

    Forma_de_Pagamento formapagamento;
    void print_forma_de_pagamento();
    Data data_de_venda;
    float valor;
    unsigned int parcelas = 1;

    friend class Pagamento;

    //Tratamento de estoque

public:
    Venda(Forma_de_Pagamento formapagamento, Data data_de_venda, float valor, unsigned int parcelas = 1);

    Venda(){}
        
};


class Pagamento{
protected:
    Venda v;

public:
    Pagamento(){};
    Pagamento(Venda v);

    virtual void pagar();

};


class Dinheiro: public Pagamento{
public:
    Dinheiro(){};

    void pagar(Data data_de_pfmt, float valor);

};

class Cartao_Debito: public Pagamento{
public:
    void pagar();

};

class Cartao_Credito: public Pagamento{
public:
    void pagar();
};

#endif