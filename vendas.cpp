#include "vendas.h"

#include <iostream>
#include <iomanip>



// std::ostream &operator<< (std::ostream &output){
//     output << "Receita anual " << company.nome << ":" << std::endl;
//     for (const auto& it : company.receita_mensal){
//             output << it << " ";
//     }
//     output << std::endl;

//     return output;
// }

// Empresa::Empresa(){
//     receita_mensal = {0,0,0,0,0,0,0,0,0,0,0,0};
//     nome = " ";
// }

// Empresa::Empresa(std::string nome){
//     receita_mensal = {0,0,0,0,0,0,0,0,0,0,0,0};
//     this->nome = nome;
// }



std::ostream &operator<< (std::ostream &output , const Venda &sell ){
    if (sell.formapagamento == Forma_de_Pagamento::DINHEIRO)
        std::cout << "Forma de pagamento: Dinheiro";
    if (sell.formapagamento == Forma_de_Pagamento::CARTAO_CREDITO)
        std::cout << "Forma de pagamento: Cartao_credito";
    if (sell.formapagamento == Forma_de_Pagamento::CARTAO_DEBITO)
        std::cout << "Forma de pagamento: Cartao_debito";
    std:: cout << std::endl;

    std::cout << "Data da venda: " << sell.data_de_venda
        << "Valor: " << sell.valor << std::endl
        << "Parcelas: " << sell.parcelas << std::endl;

    return output;
}



Venda::Venda (Forma_de_Pagamento formapagamento, Data data_de_venda,int qnt ,float valor, unsigned int parcelas){
//    this->empresa_creditada = empresa_creditada;
    this->formapagamento = formapagamento;
    this->data_de_venda = data_de_venda;
    this->valor = valor;
    this->parcelas = parcelas;
    this->qnt = qnt;

}

void Venda::set_data_de_pag(Data pag){
    data_de_venda=pag;

}

void Venda::set_lucro(float valor,float taxa=0){
    lucro = valor* (1-(taxa/100)) - valor_unidade_lote * qnt ;    
}



void Venda::pagar(){
    if (formapagamento == Forma_de_Pagamento::DINHEIRO){
        Dinheiro d{};
        d.pagar(data_de_venda, valor);
    }
    if (formapagamento == Forma_de_Pagamento::CARTAO_DEBITO){
        Cartao_Debito cd{};
        cd.pagar(data_de_venda, valor);
    }
    if (formapagamento == Forma_de_Pagamento::CARTAO_CREDITO){
        Cartao_Credito cc{};
        cc.pagar(data_de_venda, valor ,parcelas);
    }
}



 void Dinheiro::pagar(Data data_de_pfmt, float valor){
     set_data_de_pag(data_de_pfmt);
     set_lucro(valor); 
      //empresa_creditada->receita_mensal[data_de_pfmt.get_mes()-1] += valor;
 }



Taxas_bandeiras::Taxas_bandeiras(){
    ler_taxas();
}



void Taxas_bandeiras::ler_taxas(){
    d_visa = 1.49;
    d_master = 1.49;
    d_elo = 2.49;
    d_hiper = 0;

    c_visa= {2.97, 3.60, 3.94, 4.27, 4.60, 4.93, 5.84, 6.17, 6.49, 6.82, 7.14, 7.45};
    c_master= {2.97, 3.60, 3.94, 4.27, 4.60, 4.93, 5.84, 6.17, 6.49, 6.82, 7.14, 7.45};
    c_elo = {4.16, 4.79, 5.12, 5.45, 5.78, 6.10, 6.91, 7.24, 7.56, 7.87, 8.19, 8.51};
    c_hiper = {3.37, 4.49, 4.83, 5.16, 5.48, 5.81, 6.62, 6.95, 7.27, 7.59, 7.90, 8.22};
}



Cartao_Debito::Cartao_Debito(){
    std::cout << "Qual o cartão utilizado? \nVisa => digite 1 \nMaster => digite 1  \nElo => digite 3 \nHipercard => digite 4" << std::endl;
    unsigned int bandeira; 
    std::cin >> bandeira;

    switch (bandeira)
    {
    case 1:
        bandeira_do_cartao = Cartao::VISA;
        break;
    case 2:
        bandeira_do_cartao = Cartao::MASTER;
        break;
    case 3:
        bandeira_do_cartao = Cartao::ELO;
        break;
    case 4:
        bandeira_do_cartao = Cartao::HIPERCARD;
        break;
    default:
        std::cout << "Valor invávilo" << std::endl;
        break;
    }
}


 
void Cartao_Debito::pagar(Data data_de_pfmt, float valor){
    float taxabandeira{};

    switch (bandeira_do_cartao)
    {
    case Cartao::VISA:
        taxabandeira = d_visa;
        break;
    case Cartao::MASTER:
        taxabandeira = d_master;
        break;
    case Cartao::ELO:
        taxabandeira = d_elo;
        break;
    case Cartao::HIPERCARD:
        taxabandeira = d_hiper;
        break;
    default:
        std::cout << "Valor invávilo";
        taxabandeira = 0;
        break;
    }

    set_data_de_pag(data_de_pfmt);
    set_lucro(valor,taxabandeira); 

//    empresa_creditada->receita_mensal[data_de_pfmt.get_mes()-1] += valor;
}



Cartao_Credito::Cartao_Credito(){
    std::cout << "Qual o cartão utilizado? \nVisa => digite 1 \nMaster => digite 2 \nElo => digite 3 \nHipercard => digite 4" << std::endl;
    unsigned int bandeira;
    std::cin >> bandeira;

    switch (bandeira)
    {
    case 1:
        bandeira_do_cartao = Cartao::VISA;
        break;
    case 2:
        bandeira_do_cartao = Cartao::MASTER;
        break;

    case 3:
        bandeira_do_cartao = Cartao::ELO;
        break;
    case 4:
        bandeira_do_cartao = Cartao::HIPERCARD;
        break;
    default:
        std::cout << "Valor invávilo" << std::endl;
        break;
    }
}



void Cartao_Credito::pagar(Data data_de_pfmt ,float valor, unsigned int parcelas){
    float taxabandeira{};

    switch (bandeira_do_cartao)
    {
    case Cartao::VISA:
        taxabandeira = c_visa[parcelas-1];
        break;
    case Cartao::MASTER:
    taxabandeira = c_master[parcelas-1];
    break;
    case Cartao::ELO:
        taxabandeira = c_elo[parcelas-1];
        break;
    case Cartao::HIPERCARD:
        taxabandeira = c_hiper[parcelas-1];
        break;
    default:
        std::cout << "Valor invávilo";
        taxabandeira = 0;
        break;
    }

    set_data_de_pag(data_de_pfmt);
    set_lucro(valor,taxabandeira); 
    

    //for (unsigned int i = 0; i< parcelas; i++){
    //    empresa_creditada->receita_mensal[data_de_pfmt.get_mes()-1 +i] += (valor/parcelas);
    //}
}
