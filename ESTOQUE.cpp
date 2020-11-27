#include"ESTOQUE.h"
#include"vendas.h"

#include<list>
//consulta funcoes de lista 

//it=minha_lista.beguin()
//advance(it,5); //avanca 5
// class data{

// };

// class cliente{
//     public:
//         std::string nome_cliente;
//         //data data_cadastro;
//         std::string regiao;
//         std::string categoria;
        
//         void print_cliente(){
//             std::cout<<nome_cliente<<std::endl;
//             std::cout<<regiao<<std::endl;
//             std::cout<<categoria<<std::endl;
//         }
    
//     private:
//     protected:
// };

// class lista_cliente{
//         std::list<cliente> m_lista_cliente;
//         std::list<cliente>::iterator it;

//         void novo_cliente(){
//             cliente a;
//             m_lista_cliente.push_front(a); //adc novo lote no inicio
//         }
// };

// class vendas{
//     public:
//         cliente *cel_cliente;
//         //lote *cel_lote;
//         forma_pagamento pag;
//         int  qnt;
//         int  bonificacao;
//         bool eh_consignado;
//         float valor_total;
//         //data data_venda;

//         bool finalizado;

//         //---------------------funcoes
//         void print_vendas(){
//             cel_cliente->print_cliente();
//             std::cout<<qnt<<std::endl;
//             std::cout<<bonificacao<<std::endl;
//             std::cout<<eh_consignado<<std::endl;
//             std::cout<<valor_total<<std::endl;
//         }

//         //----------------------construtores
//         //vendas(){}
//         vendas(cliente *m_cliente, int m_qnt,int m_bonificacao,float m_valor_total)
//         : cel_cliente(m_cliente) , qnt(m_qnt),bonificacao(m_bonificacao),eh_consignado(false), valor_total(m_valor_total){}

//     private:
//     protected:
// };

class lote{

    private:
    friend class produto;

    //-----------------------//
    std::string nome_lote;   //
    int qnt;                 //
    float preco_unidade;     //
    bool consignado;         //
    // data vencimento;      //
    // data data_retirada;   //
    // data data_pagamento;  //
    //---------------------- //

    public:
    //-------------construtores
    //lote(){}

    lote(std::string m_lote,int m_qnt,float m_preco_unidade,bool m_consiguinado)
         : nome_lote(m_lote),qnt(m_qnt),preco_unidade(m_preco_unidade),consignado(m_consiguinado){}

    void set_qnt(int a){
        if (a>=0)
            qnt=a;
    }

    void set_preco_unidade(float b){
            preco_unidade=b;
    }

    void set_consignado(bool a){
            consignado=a;
    }

    int get_qnt(void){
        return qnt;
    }

    float get_preco_unidade(void){
        return preco_unidade;
    }

    bool get_consignado(void){
        return consignado;
    }


    void print_lote(){
          std::cout << std::endl;
          std::cout << qnt << std::endl;
          std::cout << preco_unidade << std:: endl;
          std::cout << consignado << std:: endl;
    }

    // //--------------------------------lista vendas

    std::list<Venda> lista_vendas;
    std::list<Venda>::iterator it;

    void nova_venda(Forma_de_Pagamento formapagamento, Data data_de_venda, float valor, unsigned int parcelas){
        Venda a(formapagamento, data_de_venda ,valor , parcelas);
        lista_vendas.push_front(a); //adc novo lote no inicio
    }
         
    protected:
};

class produto{
    public:
        //-------------lista de lotes--
        std::list<lote> lista_lote;
        std::list<lote>::iterator it;

        //-------------construtor------

        produto(std::string m_nome):nome_do_produto(m_nome){}

        void novo_lote(std::string m_lote,int m_qnt,float m_preco_unidade,bool m_consiguinado){
            lote a(m_lote,m_qnt,m_preco_unidade,m_consiguinado);
            lista_lote.push_front(a); //adc novo lote no inicio
        }

        std::string nome_do_produto; 
        private:
        friend class lote;
    protected:

};

class parque{
    public:
        std::string nome;  

        //-------------construtor--------------------------
        parque(std::string m_nome):nome(m_nome){}  

        //-------------criando lista de produtos-----------
        std::list<produto> lista_produto;
        std::list<produto>::iterator it;

        void novo_produto(std::string nome){
            produto a(nome);
            lista_produto.push_front(a); //adc novo lote no inicio
        }

        void print_lista_produto(){

        for ( it = lista_produto.begin(); it != lista_produto.end(); it++ ){
                std::cout << "Imprimindo a lista...: " << it->nome_do_produto << std::endl;
        }
    }   



    private:
    protected:
};

class lista_parques{

        std::list<parque> mlista_parques;
        std::list<parque>::iterator it;

    public:
        void novo_parque(std::string nome){
            parque a(nome);
            mlista_parques.push_front(a); //adc novo lote no inicio

        }
        void print_lista_parque(){
            std::list<parque>::iterator it;

            for ( it = mlista_parques.begin(); it != mlista_parques.end(); it++ ){
                 std::cout << "Imprimindo a lista...: " << it->nome << std::endl;
            }
        }  

        void print_lista_parque_produtos(){
            std::list<parque>::iterator it;

            for ( it = mlista_parques.begin(); it != mlista_parques.end(); it++ ){
                 std::cout << "Imprimindo a lista...: " << it->nome << std::endl;
                 it->print_lista_produto();
            }
        } 

        std::list<parque>::iterator busca_parque(std::string nome){

            for ( it = mlista_parques.begin(); it != mlista_parques.end(); it++ ){
                 //std::cout << "Imprimindo a lista...: " << it->nome << std::endl;
                 if (it->nome==nome){
                     return it;
                 }
            }
            return it;
        }
         
};

