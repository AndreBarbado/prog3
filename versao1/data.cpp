#include "data.h"
#include <iostream>
#include <iomanip>

std::ostream &operator<<( std::ostream &output, const Data &date ){
    output << std::setw(2) << std::setfill('0') << date.get_dia() << "/" 
        << std::setw(2) << std::setfill('0') << date.get_mes() << "/"
        << date.get_ano() << std:: endl;
    return output;
}

Data::Data (unsigned int dia, unsigned int mes, unsigned int ano){
    set_ano(ano);
    set_mes(mes);
    set_dia(dia);
}

Data::Data (){}

void Data::set_dia(unsigned int dia){
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

void Data::set_mes(unsigned int mes){
    if (mes<=12){
        this->mes = mes; 
    }else { data_invalida(); }
}

void Data::set_ano(unsigned int ano){
    this->ano = ano;
}

unsigned int Data::get_dia() const{
    return this->dia;
}

unsigned int Data::get_mes() const{
    return this->mes;
}

unsigned int Data::get_ano() const{
    return this->ano;
}

void Data::data_invalida() {
    printf("Data Inválida\n");
}

bool Data::bissexto(){
    if (ano%4==0 && ano%100!=0)
        return true;
    if (ano%400==0)
        return true;
    return false;
}





