#ifndef VENDAS_H
#define VENDAS_H

#include <iostream>
#include <string>
#include <array>

#include "data.h"



// class Empresa{
//     std::string nome;
//     std::array<float,12> receita_mensal;
//     friend std::ostream &operator<< (std::ostream &, const Empresa & );

// public:
//     friend class Venda;
//     friend class Dinheiro;
//     friend class Cartao_Debito;
//     friend class Cartao_Credito;

//     Empresa();
//     Empresa(std::string nome);
// };



enum class Forma_de_Pagamento {CARTAO_CREDITO, CARTAO_DEBITO, DINHEIRO};



class Venda{
    friend std::ostream &operator<< (std::ostream &, const Venda & );

   //Empresa* empresa_creditada;
    Forma_de_Pagamento formapagamento;
    Data data_de_venda;
    float valor;
    float valor_unidade_lote;
    unsigned int parcelas = 1;
    int qnt;
    float lucro;

    //Tratamento de estoque

public:
    Venda(Forma_de_Pagamento formapagamento, Data data_de_venda,int qnt,float valor, unsigned int parcelas = 1);

    Venda() {};

    virtual ~Venda() {};

    virtual void pagar();

    void set_data_de_pag(Data);

    void set_lucro(float,float);
        
};



class Dinheiro: public Venda{
public:
    void pagar(Data data_de_pfmt, float valor);

};



enum class Cartao {VISA, MASTER, ELO, HIPERCARD};



class Taxas_bandeiras{
protected:
    std::array<float,12> c_visa;
    std::array<float,12> c_master;
    std::array<float,12> c_elo;
    std::array<float,12> c_hiper;
    float d_visa;
    float d_master;
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
    
    void pagar(Data data_de_pfmt ,float valor);

};



class Cartao_Credito: public Venda, public Taxas_bandeiras{
    Cartao bandeira_do_cartao;
public:
    Cartao_Credito();

    void pagar(Data data_de_pfmt, float valor, unsigned int parcelas);
};



#endif
