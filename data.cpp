#include "class_lib.hpp"

data::data (unsigned int dia, unsigned int mes, unsigned int ano = 2020){
    set_ano(ano);
    set_mes(mes);
    set_dia(dia);
}

void data::set_dia(unsigned int dia){
    if ( mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        if(dia<=31){
            this->dia = dia;
        }else{ data_invalida(); }
    }
    if ( mes==4 || mes==6 || mes==9 || mes==11){
        if(dia<=30){
            this->dia = dia;
        }else{ data_invalida(); }
    }
    if ( mes==2 ){
        if(bissexto()){
            if(dia<=29){
                this->dia = dia;
            }else{ data_invalida(); }
        }else{
            if(dia<=28){
                this->dia = dia;
            }else{ data_invalida(); }
        }
    }
}

void data::set_mes(unsigned int mes){
    if (mes<=12){
        this->mes = mes; 
    }else { data_invalida(); }
}

void data::set_ano(unsigned int ano){
    this->ano = ano;
}

unsigned int data::get_dia() const{
    return this->dia;
}

unsigned int data::get_mes() const{
    return this->mes;
}

unsigned int data::get_ano() const{
    return this->ano;
}

void data::data_invalida() {
    printf("Data Inválida\n");
}

bool data::bissexto(){
    if (ano%4==0 && ano%100!=0)
        return true;
    if (ano%400==0)
        return true;
    return false;
}

void data::print() const{
    std::cout << get_dia() << "/"
        << get_mes() << "/"
        << get_ano() << std::endl;
}
