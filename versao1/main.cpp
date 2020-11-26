#include "data.h"
#include "vendas.h"

int main(){

    Data data_teste{15,8};

    Venda teste{Forma_de_Pagamento::Dinheiro, data_teste , 771.99};

    std::cout << teste;

    Pagamento testanto{teste};


    testanto.pagar();
   
    return 0;
}