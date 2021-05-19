#ifndef CONTROLADORAS_H
#define CONTROLADORAS_H

#include <iostream>
#include "interfaces.h"
#include "dominios.h"

class ControlaUsuario: public AprUsuario{
private:
    ServiUsuario *controlaserv;

public:
    void cadastrar();

    void descadastrar();

    void setSUsuario(ServiUsuario *controlaserv){
        this->controlaserv = controlaserv;
    }

};

class ControlaJogos: public AprJogos{
private:
    ServiJogos *controlaserv;
    ServiAutentica *controla_aut;

public:
    void cadastrar();
    void descadastrar();
    void alterarjogo();
    void buscar();
    void obter_dados();

    void setSJogos(ServiJogos *controlaserv){
        this->controlaserv = controlaserv;
    }

    void setAAutentica(ServiAutentica *controla_aut){
        this->controla_aut = controla_aut;
    }
};

class ControlaVendas: public AprVendas{
private:
    ServiVendas *controleserv;
    ServiAutentica *controla_aut;
public:

    void comprar();

    void setSVendas(ServiVendas *controleserv){
        this->controleserv = controleserv;
    }

    void setAAutentica(ServiAutentica *controla_aut){
        this->controla_aut = controla_aut;
    }
};

/*class ControlaAutentica: public AprAutentica{
private:
    ServiAutentica *controlaserv;

public:
    void autenticar();

    void setSAutentica(ServiAutentica *controlaserv){
        this->controlaserv = controlaserv;
    }
};*/

#endif