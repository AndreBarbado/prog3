#ifndef VENDAS_H
#define VENDAS_H

#include <iostream>
#include <array>

#include "data.h"

class Empresa{
    std::array<float,12> receita_mensal;

public:
    friend class Venda;
    friend class Dinheiro;
    friend class Cartao_Debito;
    friend class Cartao_Credito;

    Empresa();

    void print(){
        for (const auto& it : receita_mensal){
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
};


enum class Forma_de_Pagamento {CARTAO_CREDITO, CARTAO_DEBITO, DINHEIRO};

class Venda{
    friend std::ostream &operator<< (std::ostream &, const Venda & );

    Empresa empresa_creditada;
    Forma_de_Pagamento formapagamento;
    Data data_de_venda;
    float valor;
    unsigned int parcelas = 1;

    //Tratamento de estoque

public:
    Venda(Empresa empresa_creditada, Forma_de_Pagamento formapagamento, Data data_de_venda, float valor, unsigned int parcelas = 1);

    Venda() {};

    virtual ~Venda() {};

    virtual void pagar();
        
};


class Dinheiro: public Venda{
public:
    void pagar(Empresa& empresa_creditada, Data data_de_pfmt, float valor);

};


enum class Cartao {VISAMASTER, ELO, HIPERCARD};

// fazer vetor com os valores das taxas, os vetores leem as planilhas

class Taxas_bandeiras{
protected:
    std::array<float,12> c_visaemaster;
    std::array<float,12> c_elo;
    std::array<float,12> c_hiper;
    float d_visaemaster;
    float d_elo;
    float d_hiper;

private:
    void ler_taxas();

public:
    Taxas_bandeiras();
};

class Cartao_Debito: public Venda, public Taxas_bandeiras{
    Cartao bandeira_do_cartao;
public:
    Cartao_Debito();
    
    void pagar(Empresa empresa_creditada, Data data_de_pfmt, float valor);

};

class Cartao_Credito: public Venda, public Taxas_bandeiras{
    Cartao bandeira_do_cartao;
public:
    Cartao_Credito();

    void pagar(Empresa empresa_creditada, Data data_de_pfmt, float valor, unsigned int parcelas);
};


#endif
