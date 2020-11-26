#include "vendas.h"

#include <iostream>

std::ostream &operator<< (std::ostream &output , const Venda &sell ){
    if (sell.formapagamento == Forma_de_Pagamento::Dinheiro)
        std::cout << "Forma de pagamento: Dinheiro";
    if (sell.formapagamento == Forma_de_Pagamento::Cartao_credito)
        std::cout << "Forma de pagamento: Cartao_credito";
    if (sell.formapagamento == Forma_de_Pagamento::Cartao_debito)
        std::cout << "Forma de pagamento: Cartao_debito";
    std:: cout << std::endl;

    std::cout << "Data da venda: " << sell.data_de_venda
        << "Valor: " << sell.valor << std::endl
        << "Parcelas: " << sell.parcelas << std::endl;

    return output;
}

Venda::Venda (Forma_de_Pagamento formapagamento, Data data_de_venda, float valor, unsigned int parcelas){
    this->formapagamento = formapagamento;
    this->data_de_venda = data_de_venda;
    this->valor = valor;
    this->parcelas = parcelas;
}

void Venda::print_forma_de_pagamento(){
    if (formapagamento == Forma_de_Pagamento::Dinheiro)
        std::cout << "Forma de pagamento: Dinheiro";
    if (formapagamento == Forma_de_Pagamento::Cartao_credito)
        std::cout << "Forma de pagamento: Cartao_credito";
    if (formapagamento == Forma_de_Pagamento::Cartao_debito)
        std::cout << "Forma de pagamento: Cartao_debito";
    std:: cout << std::endl;
}


Pagamento::Pagamento (Venda v){
    this->v = v;
}

void Pagamento::pagar(){
    if (v.formapagamento == Forma_de_Pagamento::Dinheiro){
        Dinheiro d{};
        d.pagar(v.data_de_venda,v.valor);
    }
}

void Dinheiro::pagar(Data data_de_pfmt, float valor){
    std::cout << "Pagar em dinheiro no valor de " << valor << " no dia " << data_de_pfmt;
}