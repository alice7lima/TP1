#ifndef INTERFACES_H
#define INTERFACES_H
#include "dominios.h"
#include "entidade.h"
#include <stdexcept>


class ServiUsuario{
public:
    virtual bool cadastrar(CPF cpf, SENHA senha, NumeroCartao numero, CodigoSeguranca codigo, DataValidade data) throw(std::runtime_error) = 0;       
    virtual bool descadastrar(std::string cpf, std::string senha) = 0;      
};

class AprUsuario{
public:
    virtual void cadastrar() = 0;
    virtual void descadastrar() = 0;
    virtual void setSUsuario(ServiUsuario*) = 0;
};

class ServiJogos{
public:
    virtual bool cadastrar(NomeJogo nome, CodigoJogo codJ, Data data, Horario hora, Cidade cidade, Estado estado, Preco preco, CodigoIngresso codI, CPF cpf, Disponibilidade disp) = 0;                
    virtual bool descadastrar(std::string codJ) = 0;           
    virtual bool buscar(Data data, Cidade cidade, Estado est) = 0;                  
    virtual bool alterarjogo(CodigoJogo codJ, NomeJogo nome, CodigoIngresso codI, Data data, Horario hora, Preco preco, Cidade cidade, Estado estado, CPF cpf, Disponibilidade disp) = 0;              
    virtual bool obter_dados(std::string codJ) = 0;              
    virtual bool existejogo(std::string cpf, std::string codJ) = 0;

    
};

class AprJogos{
public:
    virtual void cadastrar() = 0;
    virtual void descadastrar() = 0;
    virtual void alterarjogo() = 0;
    virtual void buscar() = 0;
    virtual void obter_dados() = 0;

    virtual void setSJogos(ServiJogos*) = 0;
};

class ServiVendas{           
public:
    virtual bool comprar(const CodigoJogo codJ, int quantidade, std::string cpf) = 0;          
    
};

class AprVendas{            
public:
    virtual void comprar() = 0;
    virtual void setSVendas(ServiVendas*) = 0;
};

class ServiAutentica{
public:
    virtual bool autenticar(std::string cpf, std::string senha) = 0;
};



#endif