/**
 * @file: parte1Dominio.cpp
 *
 * @author1: Alice da Silva de Lima
 * @Matricula: 18/0112601
 * @author2: Giovana Pinho Garcia
 * @Matricula: 18/0101374
 *
 * @disciplina: Tecnicas de Programacao 1
 * @Professor: Washington Almeida
 *
 *Arquivo que lista todas as classes de teste unitário e as descreve */

#ifndef TESTES_H
#define TESTES_H
#include "dominios.h"

#include <iostream>


const static int SUCESSO =  0;
const static int FALHA   = -1;

/**
 * @class TesteCodigoJogo
 * @brief classe que da exemplos de string validas e invalidas para codigo do jogo e realiza o teste unitario
 **/
class TesteCodigoJogo{
private:
    const std::string VALIDO = "007";
    const std::string INVALIDO = "1B78";

    CodigoJogo *codigo;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();
};

/**
 * @class TesteCodigoIngresso
 * @brief classe que da exemplos de strings validas e invalidas para codigo do ingresso e realiza o teste unitario
 **/
class TesteCodigoIngresso{
private:
    const std::string VALIDO = "01234";
    const std::string INVALIDO = "A444T";

    CodigoIngresso *codigo;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();
};

/**
 * @class TesteCodigoSeguranca
 * @brief classe que da exemplos de strings validas e invalidas para codigo de seguranca e realiza o teste unitario
 **/
class TesteCodigoSeguranca{
private:
    const std::string VALIDO = "003";
    const std::string INVALIDO = "B22";

    CodigoSeguranca *codigo;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();

};

/**
 * @class TesteNomeJogo
 * @brief classe que da exemplos de strings validas e invalidas para nome do jogo e realiza o teste unitario
 **/
class TesteNomeJogo{
private:
    const std::string VALIDO = "Sao Paulo";
    const std::string INVALIDO = "Sao   Paulo";

    NomeJogo *nome;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();

};

/**
 * @class TesteData
 * @brief classe que da exemplos de strings validas e invalidas para data e realiza o teste unitario
 **/
class TesteData{
private:
    const std::string VALIDO = "31/08/17";
    const std::string INVALIDO = "29/02/15";

    Data *data;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();
};


/**
 * @class TesteHorario
 * @brief classe que da exemplos de strings validas e invalidas para horario e realiza o teste unitario
 **/
class TesteHorario{
private:
    const std::string VALIDO = "21:30";
    const std::string INVALIDO = "04:11";

    Horario *hora;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();

};

/**
 * @class TestePreco
 * @brief classe que da exemplos de strings validas e invalidas para o preco e realiza o teste unitario
 **/
class TestePreco{
private:
    const std::string VALIDO = "R$ 500,00";
    const std::string INVALIDO = "R$ 1.300,00";

    Preco *preco;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();

};

/**
 * @class TesteCidade
 * @brief classe que da exemplos de strings validas e invalidas para o nome de cidade e realiza o teste unitario
 **/
class TesteCidade{
private:
    const std::string VALIDO = "Sao Paulo";
    const std::string INVALIDO = "Sao    Paulo";

    Cidade *cidade;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();

};

/**
 * @class TesteEstado
 * @brief classe que da exemplos de strings validas e invalidas para as siglas de estado e realiza o teste unitario
 **/
class TesteEstado{
private:
    const std::string VALIDO = "DF";
    const std::string INVALIDO = "RF";

    Estado *est;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();

};

/**
 * @class TesteDisponibilidade
 * @brief classe que da exemplos de valores validos e invalidos para disponibilidade e realiza o teste unitario
 **/
class TesteDisponibilidade{
private:
    const static int VALIDO = 100;
    const static int INVALIDO = 260;

    Disponibilidade *disp;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();

};


/**
 * @class TesteCPF
 * @brief classe que da exemplos de strings validas e invalidas para CPF e realiza o teste unitario
 **/
class TesteCPF{
private:
    const std::string VALIDO = "057.004.141-47";
    const std::string INVALIDO = "111.111.111.32";

    CPF *cpf;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();
};

/**
 * @class TesteSENHA
 * @brief classe que da exemplos de strings validas e invalidas para senha e realiza o teste unitario
 **/
class TesteSENHA{
private:
    const std::string VALIDO = "Gjk0c8";
    const std::string INVALIDO = "dccp89";

    SENHA *senha;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();
};

/**
 * @class TesteNumCartao
 * @brief classe que da exemplos de strings validas e invalidas para numero do cartao e realiza o teste unitario
 **/
class TesteNumCartao{
private:
    const std::string VALIDO = "4919355856790266";
    const std::string INVALIDO = "4919355856790265";

    NumeroCartao *numcard;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();
};

/**
 * @class TesteDataValidade
 * @brief classe que da exemplo de string validas e invalidas para a data do jogo e realiza o teste unitario
 **/
class TesteDataValidade{
private:
    const std::string VALIDO = "10/20";
    const std::string INVALIDO = "23/34";

    DataValidade *data;

    int estado;

    void cria();
    void cenarioSucesso();
    void cenarioFalha();
    void destroi();

public:
    int testa();
};


#endif
