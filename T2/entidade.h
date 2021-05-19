/**
 * @file: entidades.h
 *
 * @author1: Alice da Silva de Lima
 * @Matricula: 18/0112601
 * @author2: Giovana Pinho Garcia
 * @Matricula: 18/0101374
 *
 * @disciplina: Tecnicas de Programacao 1
 * @Professor: Washington Almeida
 *
 *Arquivo que lista todas as classes de entidade e as descreve */


#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "dominios.h"
#include <string>


/**
 * @class Usuario
 * @brief classe de entidade que representa o usuario, contendo as classes de dominio que a representa e seus respectivos metodos auxiliares
 **/
class Usuario{
private:
    CPF cpf;
    SENHA senha;
    NumeroCartao numero;
    CodigoSeguranca codigo;
    DataValidade data;

public:

    /**
    * @brief atribui a string do cpf a seu respectivo atributo
    * @param cpf CPF que representa o CPF do usuario
    **/
    void setCPF(const CPF &cpf){
        this->cpf = cpf;
    }

    /**
     * @brief adquire o cpf do usuario
     * @return retorna o cpf do usuario
     **/
    CPF getCPF() const{
        return cpf;
    }

    /**
    * @brief atribui a string da senha a seu respectivo atributo
    * @param senha SENHA que representa a senha do usuario
    **/
    void setSENHA(const SENHA &senha){
        this->senha = senha;
    }

    /**
     * @brief adquire a senha do usuario
     * @return retorna a senha do usuario
     **/
    SENHA getSENHA() const{
        return senha;
    }

    /**
    * @brief atribui a numeracao do cartao a seu respectivo atributo
    * @param numero NumeroCartao que representa o numero do cartao do usuario
    **/
    void setNumCartao(const NumeroCartao &numero){
        this->numero = numero;
    }

    /**
     * @brief adquire o numero do cartao do usuario
     * @return retorna o numero do cartao do usuario
     **/
    NumeroCartao getNumCartao() const{
        return numero;
    }

    /**
    * @brief atribui a numeracao do codigo a seu respectivo atributo
    * @param codigo CodigoSeguranca que representa o codigo de seguranca do cartao
    **/
    void setCodSeguranca(const CodigoSeguranca &codigo){
        this->codigo = codigo;
    }

    /**
     * @brief adquire o codigo de seguranca do cartao do usuario
     * @return retorna o codigo de seguranca do cartao do usuario
     **/
    CodigoSeguranca getCodSeguranca() const{
        return codigo;
    }

    /**
    * @brief atribui a string da data de validade a seu respectivo atributo
    * @param data DataValidade que representa a data de vaidade do cartao do usuario
    **/
    void setDataValidade(const DataValidade &data){
        this->data = data;
    }

    /**
     * @brief adquire a data de validade do cartao do usuario
     * @return retorna a data de validade do cartao do usuario
     **/
    DataValidade getDataValidade() const{
        return data;
    }

};

/**
 * @class Jogo
 * @brief classe de entidade que representa o jogo, contendo as classes de dominio que a representa e seus respectivos metodos auxiliares
 **/
class Jogo{
private:
    CPF cpf;
    CodigoJogo codigo;
    NomeJogo nome;
    Cidade cidade;
    Estado estado;
    Data data;
    Horario horario;
    Preco preco;
    Disponibilidade disp;
    CodigoIngresso codi;

public:

    /**
    * @brief atribui a string do cpf a seu respectivo atributo
    * @param cpf CPF que representa o CPF do usuario
    **/
    void setCPF(const CPF &cpf){
        this->cpf = cpf;
    }

    /**
     * @brief adquire o cpf do usuario
     * @return retorna o cpf do usuario
     **/
    CPF getCPF() const{
        return cpf;
    }

    /**
    * @brief atribui a numeracao do codigo a seu respectivo atributo
    * @param codigo CodigoJogo que representa o codigo do jogo
    **/
    void setCodJogo(const CodigoJogo &codigo){
        this->codigo = codigo;
    }

    /**
     * @brief adquire o codigo do jogo
     * @return retorna o codigo do jogo
     **/
    CodigoJogo getCodJogo() const{
        return codigo;
    }

    /**
    * @brief atribui o nome do jogo a seu respectivo atributo
    * @param nome NomeJogo que representa o nome do jogo
    **/
    void setNomeJogo(const NomeJogo &nome){
        this->nome = nome;
    }

    /**
     * @brief adquire o nome do jogo
     * @return retorna o nome do jogo
     **/
    NomeJogo getNomeJogo() const{
        return nome;
    }

    /**
    * @brief atribui a string cidade a seu respectivo atributo
    * @param cidade Cidade que representa a cidade do jogo
    **/
    void setCidade(const Cidade &cidade){
        this->cidade = cidade;
    }

    /**
     * @brief adquire a cidade do jogo
     * @return retorna a cidade do jogo
     **/
    Cidade getCidade() const{
        return cidade;
    }

    /**
    * @brief atribui a sigla do estado a seu respectivo atributo
    * @param estado Estado que representa o estado do jogo
    **/
    void setEstado(const Estado &estado){
        this->estado = estado;
    }

    /**
     * @brief adquire o estado do jogo
     * @return retorna o estado do jogo
     **/
    Estado getEstado() const{
        return estado;
    }

    /**
    * @brief atribui a string da data a seu respectivo atributo
    * @param data Data que representa a data da partida
    **/
    void setData(const Data &data){
        this->data = data;
    }

    /**
     * @brief adquire a data da partida
     * @return retorna a data da partida
     **/
    Data getData() const{
        return data;
    }

    /**
    * @brief atribui a string do horario a seu respectivo atributo
    * @param horario Horario que representa o horario da partida
    **/
    void setHorario(const Horario &horario){
        this->horario = horario;
    }

    /**
     * @brief adquire o horario da partida
     * @return retorna o horario da partida
     **/
    Horario getHorario() const{
        return horario;
    }

    /**
    * @brief atribui a valor do preco a seu respectivo atributo
    * @param preco Preco que representa o preco do ingresso da partida
    **/
    void setPreco(const Preco &preco){
        this->preco = preco;
    }

    /**
     * @brief adquire o preco do ingresso da partida
     * @return retorna o preco do ingresso da partida
     **/
    Preco getPreco() const{
        return preco;
    }

    /**
    * @brief atribui o valor de disponibilidade a seu respectivo atributo
    * @param disp Disponibilidade que representa a disponibillidade de ingressos da partida
    **/
    void setDisponibilidade(const Disponibilidade &disp){
        this->disp = disp;
    }

    /**
     * @brief adquire a disponibilidade de ingressos da partida
     * @return retorna a disponibilidade de ingressos da partida
     **/
    Disponibilidade getDisponibilidade() const{
        return disp;
    }

    /**
    * @brief atribui a numeracao do codigo a seu respectivo atributo
    * @param codigo CodigoIngresso que representa o codigo do ingresso
    **/
    void setCodIngresso(const CodigoIngresso &codigo){
        this->codi = codigo;
    }

    /**
     * @brief adquire o codigo do ingresso
     * @return retorna o codigo do ingresso
     **/
    CodigoIngresso getCodIngresso() const{
        return codi;
    }
};

class Ingresso{
private:
    CodigoJogo codigo;
    CPF cpf;
    Disponibilidade disp;

public:
    /**
    * @brief atribui a string do cpf a seu respectivo atributo
    * @param cpf CPF que representa o CPF do usuario
    **/
    void setCPF(const CPF &cpf){
        this->cpf = cpf;
    }

    /**
     * @brief adquire o cpf do usuario
     * @return retorna o cpf do usuario
     **/
    CPF getCPF() const{
        return cpf;
    }

    /**
    * @brief atribui a numeracao do codigo a seu respectivo atributo
    * @param codigo CodigoJogo que representa o codigo do jogo
    **/
    void setCodJogo(const CodigoJogo &codigo){
        this->codigo = codigo;
    }

    /**
     * @brief adquire o codigo do jogo
     * @return retorna o codigo do jogo
     **/
    CodigoJogo getCodJogo() const{
        return codigo;
    }

     /**
    * @brief atribui o valor de disponibilidade a seu respectivo atributo
    * @param disp Disponibilidade que representa a disponibillidade de ingressos da partida
    **/
    void setDisponibilidade(const Disponibilidade &disp){
        this->disp = disp;
    }

    /**
     * @brief adquire a disponibilidade de ingressos da partida
     * @return retorna a disponibilidade de ingressos da partida
     **/
    Disponibilidade getDisponibilidade() const{
        return disp;
    }
};

#endif





