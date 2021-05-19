#ifndef STUBS_H
#define STUBS_H

#include <iostream>
#include <string>

#include "armazena.h"
#include "controladoras.h"
#include "entidade.h"

class StubsUsuario: public ServiUsuario{
private:
    const static std::string TRIGGER_FALHA_CPF;
    const static std::string TRIGGER_ERRO_CPF_DESCADASTRAR;
    const static std::string TRIGGER_ERRO_CPF_CADASTRAR;
    const static std::string TRIGGER_FALHA_SENHA;
    const static std::string TRIGGER_ERRO_SENHA_DESCADASTRAR;
    const static std::string TRIGGER_ERRO_SENHA_CADASTRAR;
    const static std::string TRIGGER_FALHA_NUMERO_CARTAO;
    const static std::string TRIGGER_ERRO_NUMERO_CARTAO;
    const static std::string TRIGGER_FALHA_CODIGO_SEGURANCA;
    const static std::string TRIGGER_ERRO_CODIGO_SEGURANCA;
    const static std::string TRIGGER_FALHA_DATA;
    const static std::string TRIGGER_ERRO_DATA;

    Armazenamento *servico_armazena;

public:
    bool cadastrar(CPF cpf, SENHA senha, NumeroCartao numero, CodigoSeguranca codigo, DataValidade data) throw(std::runtime_error);
    bool descadastrar(std::string cpf, std::string senha);

    void setSArmazenamento(Armazenamento *servico_armazena){
        this->servico_armazena = servico_armazena;
    }
};

class StubsJogos: public ServiJogos{
private:
    const static std::string TRIGGER_FALHA_NOME_JOGO;
    const static std::string TRIGGER_ERRO_NOME_JOGO;
    const static std::string TRIGGER_FALHA_CODIGO_JOGO;
    const static std::string TRIGGER_ERRO_CODIGO_JOGO;
    const static std::string TRIGGER_FALHA_DATA;
    const static std::string TRIGGER_ERRO_DATA;
    const static std::string TRIGGER_FALHA_HORARIO;
    const static std::string TRIGGER_ERRO_HORARIO;
    const static std::string TRIGGER_FALHA_CIDADE;
    const static std::string TRIGGER_ERRO_CIDADE;
    const static std::string TRIGGER_FALHA_ESTADO;
    const static std::string TRIGGER_ERRO_ESTADO;
    const static std::string TRIGGER_FALHA_PRECO;
    const static std::string TRIGGER_ERRO_PRECO;
    const static std::string TRIGGER_FALHA_CODIGO_INGRESSO;
    const static std::string TRIGGER_ERRO_CODIGO_INGRESSO;

    Armazenamento *servico_armazena;

public:
    bool cadastrar(NomeJogo nome, CodigoJogo codJ, Data data, Horario hora, Cidade cidade, Estado estado, Preco preco, CodigoIngresso codI, CPF cpf, Disponibilidade disp);
    bool descadastrar(std::string codJ);
    bool buscar(Data data, Cidade cidade, Estado est);
    bool alterarjogo(CodigoJogo codJ, NomeJogo nome, CodigoIngresso codI, Data data, Horario hora, Preco preco, Cidade cidade, Estado estado, CPF cpf, Disponibilidade disp);
    //bool alterarjogo(CodigoJogo codJ, NomeJogo nome, CodigoIngresso codI, Data data, Horario hora, Preco preco, Cidade cidade, Estado estado);
    bool obter_dados(std::string codJ);
    bool existejogo(std::string cpf, std::string codJ);

    void setSArmazenamento(Armazenamento *servico_armazena){
        this->servico_armazena = servico_armazena;
    }

};

class StubsVendas: public ServiVendas{
private:
    const static int LIMITE_INGRESSOS;
    const static std::string TRIGGER_FALHA_CODIGO_INGRESSO;
    const static std::string TRIGGER_ERRO_CODIGO_INGRESSO;
    Armazenamento *servico_armazena;
public:
    bool comprar(CodigoJogo codJ, int quantidade, std::string cpf);

    void setSArmazenamento(Armazenamento *servico_armazena){
        this->servico_armazena = servico_armazena;
    }
};

class StubsAutentica: public ServiAutentica{
private:
    const static std::string TRIGGER_FALHA_CPF;
    const static std::string TRIGGER_ERRO_CPF;
    const static std::string TRIGGER_FALHA_SENHA;
    const static std::string TRIGGER_ERRO_SENHA;
    Armazenamento *servico_armazena;
public:
    bool autenticar(std::string cpf, std::string senha);

    void setSArmazenamento(Armazenamento *servico_armazena){
        this->servico_armazena = servico_armazena;
    }
};


#endif