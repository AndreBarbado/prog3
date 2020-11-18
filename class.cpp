#include"class_lib.hpp"

class data{


};

class lote{
    public:
    std::string nome_lote;
    int qnt;
    float preco_unidade;
    bool consiguinado;
    data vencimento;
    data data_retirada;
    data data_pagamento;

    lote *prox;
    lote *ant;

    private:
    protected:
};

class produtos{
    public:
        std::string nome_do_produto;
        lote lote_inicial;
        produtos *produtos_ant;
        produtos *produtos_prox;
    private:
    protected:
};

class parque{
    public:
        std::string nome;
        produtos l_produtos;        
    private:
    protected:
};




class bandeira{
    public:
    std::string nome_bandeira;
    float taxa[12];

    bandeira *prox;
    bandeira *ant;
    
    private:
    protected:
};

class maquina_de_cartao{
    public:
    std:: string nome_maquina;
    bool recebe_a_vista;
    bandeira *bandeira_inicio;

    data data_cadastro;
    bool esta_ativo;
    
    maquina_de_cartao *prox;
    maquina_de_cartao *ant;

    private:
    protected:
};

class forma_pagamento{
    public:
    std::string nome_forma_de_pag;
    int n_de_parcelas[12];
    std::string bandeira;
    maquina_de_cartao *maquina_inicio;
    
    private:
    protected:
};


class cliente{
    public:
        std::string nome_cliente;
        data data_cadastro;
        std::string regiao;
        std::string categoria;
        
    
    private:
    protected:
};

class consiguinado{
    public:
        data data_entrega;
        int qnt_deixado;
        int qnt_vendida;
    
    private:
    protected:
};


class vendas{
    public:
        cliente *cel_cliente;
        lote *cel_lote;
        forma_pagamento pag;
        int  qnt;
        int  bonificacao;
        bool eh_consiguinado;
        float valor_total;
        data data_venda;

        bool finalizado;
         
    private:
    protected:
};