#ifndef DATA_H
#define DATA_H

#include <iostream>

class Data{
    friend std::ostream &operator<< ( std::ostream & , const Data & );

public:
    Data (unsigned int dia, unsigned int mes, unsigned int ano = 2020); 
    Data ();

    void set_dia(unsigned int dia);
    void set_mes(unsigned int mes);
    void set_ano(unsigned int ano);

    unsigned int get_dia() const;
    unsigned int get_mes() const;
    unsigned int get_ano() const;

private:
    unsigned int dia = 0;
    unsigned int mes = 0;
    unsigned int ano = 0;

    void data_invalida();
    bool bissexto();
};

#endif