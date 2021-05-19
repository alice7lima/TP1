#ifndef ARMAZENA_H
#define ARMAZENA_H

#include <list>
#include <fstream>
#include "controladoras.h"

class Armazenamento{
public:
    int inteiro;
    std::list<Usuario> cadastros;
    std::list<Usuario>::iterator itU;

    std::list<Jogo> jogos;
    std::list<Jogo>::iterator itJ;

    std::list<Ingresso> ingressos;
    std::list<Ingresso>::iterator itI;

    bool armazena_usuario(Usuario usuario);
    bool confere_cpf(CPF cpf);
    bool armazena_jogo(const Jogo &jogo);
    bool armazena_ingresso(const CodigoJogo codJ, int quantidade, std::string cpf);
    bool confere_cadastrado(std::string cpf);
    bool remove_usuario(std::string cpf, std::string senha);
    bool existe(std::string cpf, std::string codj);
    bool confere_vendido(std::string codj);
    bool remove_jogo(std::string codj);
    void busca_jogo(Data data, Cidade cidade, Estado est);
    bool autentica_usuario(std::string cpf, std::string senha);
    bool busca_infos(std::string codJ);
    bool compra_ingresso(CodigoJogo codj, int quantidade);
    bool carrega_arquivo();
    bool grava_arquivo();

};


#endif