/**
 * @file: dominios.h
 *
 * @author1: Alice da Silva de Lima
 * @Matricula: 18/0112601
 * @author2: Giovana Pinho Garcia
 * @Matricula: 18/0101374
 *
 * @disciplina: Técnicas de Programacao 1
 * @Professor: Washington Almeida
 *
 *Arquivo que lista todas as classes de dominio e as descreve */


#ifndef DOMINIOS_H
#define DOMINIOS_H
#include <string>

//Classe que transforma os tipos em inteiros ou strings para colocar no arquivo
class Transforma_String{
private:
    std::string str;

public:
    void setStr(std::string str);

    std::string getStr(){ return str; };

};

class Transforma_Inteiro{
private:
    int inteiro;
public:
    void setInt(int inteiro);

    int getInt(){ 
        return inteiro;
    }
};


/**
 * @class Validacao
 * @brief classe base para as classes de codigo, possuem metodo de validacao semelhante
 **/
class Validacao{
public:
    void validar_cod(std::string, int);
};

/*classes de dominio*/

/**
 * @class CodigoJogo
 * @brief classe que representa o codigo do jogo, contendo um atributo que representa o codigo e metodos auxiliares
 **/
class CodigoJogo : public Validacao, public Transforma_String {
private:
    std::string CodJ;
public:
    void setCodJogo(std::string codigo);
    /**
     * @brief adquire o codigo do jogo
     * @return retorna o codigo do jogo
     **/
    std::string getCodJogo() { return CodJ; }
};

/**
 * @class CodigoIngresso
 * @brief classe que representa o codigo do ingresso, contendo um atributo que representa o codigo e metodos auxilares
 **/
class CodigoIngresso : public Validacao, public Transforma_String{
private:
    std::string CodI;
public:
    void setCodIngresso(std::string codigo);
    /**
     * @brief adquire o codigo do ingresso
     * @return retorna o codigo do ingresso
     **/
    std::string getCodIngresso() { return CodI; }
};

/**
 * @class CodigoSeguranca
 * @brief classe que representa o codigo de seguranca do cartao, contendo um atributo que representa o codigo e metodos auxilares
 **/
class CodigoSeguranca : Validacao, public Transforma_String{
private:
    std::string CodS;
public:
    void setCodSeguranca(std::string CodS);
    /**
     * @brief adquire o codigo de seguranca
     * @return retorna o codigo de seguranca
     **/
    std::string getCodSeguranca() { return CodS; }
};

/**
 * @class NomeJogo
 * @brief classe que representa o nome do jogo, contendo um atributo que representa o nome e metodos auxiliares
 **/
class NomeJogo : public Transforma_String{
private:
    std::string NomJ;
    void validar(std::string nome);
public:
    void setNomeJogo(std::string nome);
    /**
     * @brief adquire o nome do jogo
     * @return retorna o nome do jogo
     **/
    std::string getNomeJogo() { return NomJ; }
};

/**
 * @class Data
 * @brief classe que representa a data do jogo, contendo um atributo que representa a data e metodos auxilares
 **/
class Data : public Transforma_String{
private:
    std::string Date;
    void validar(std::string data);
public:
    void setData(std::string data);
    /**
     * @brief adquire a data do jogo
     * @return retorna a data do jogo
     **/
    std::string getData() { return Date; }
};

/**
 * @class Horario
 * @brief classe que representa o horario do jogo, contendo um atributo que representa a hora e metodos auxilares
 **/
class Horario : public Transforma_String{
private:
    std::string Hora;
    void validar(std::string hora);
public:
    void setHorario(std::string hora);
    /**
     * @brief adquire o horario do jogo
     * @return retorna o horario do jogo
     **/
    std::string getHorario() { return Hora; }
};

/**
 * @class Preco
 * @brief classe que representa o preco do jogo, contendo um atributo que representa o preco e metodos auxiliares
 **/
class Preco : public Transforma_String{
private:
    std::string preco;
    void validar(std::string preco);
public:
    void setPreco(std::string preco);
    /**
     * @brief adquire o preco do ingresso
     * @return retorna o preco do ingresso
     **/
    std::string getPreco() { return preco; }
};

/**
 * @class Cidade
 * @brief classe que representa a cidade do jogo, contendo um atributo que representa a cidade e metodos auxilares
 **/
class Cidade : public Transforma_String{
private:
    std::string Cid;
    void validar(std::string Cid);
public:
    void setCidade(std::string cidade);
    /**
     * @brief adquire a cidade do jogo
     * @return retorna a cidade do jogo
     **/
    std::string getCidade() { return Cid; }
};

/**
 * @class Estado
 * @brief classe que representa o estado do jogo, contendo um atributo que representa a sigla do estado e metodos auxiliares
 **/
class Estado : public Transforma_String{
private:
    std::string Est;
    void validar(std::string Est);
public:
    void setEstado(std::string Est);
    /**
     * @brief adquire o estado do jogo
     * @return retorna o estado do jogo
     **/
    std::string getEstado() { return Est; }
};

/**
 * @class Disponibilidade
 * @brief classe que representa a disponibilidade de ingressos, contendo um atributo que representa a disponibilidade e metodos auxilares
 **/
class Disponibilidade : public Transforma_Inteiro{
private:
    int Disp;
    void validar(int disp);
public:
    void setDisponibilidade(int disp);
    /**
     * @brief adquire a disponibilidade de ingressos
     * @return retorna a disponibilidade de ingressos
     **/
    int getDisponibilidade() { return Disp; }
};

/**
 * @class CPF
 * @brief classe que representa o cpf, contendo um atributo que representa o cpf e metodos auxiliares
 **/
class CPF : public Transforma_String{
private:
    std::string cpf;
    void validar(std::string cpf);
public:
    void setCPF(std::string cpf);
    /**
     * @brief adquire o cpf do usuario
     * @return retorna o cpf do usuario
     **/
    std::string getCPF() { return cpf; }
};

/**
 * @class SENHA
 * @brief classe que representa a senha do usuario, contendo um atributo que representa a senha e metodos auxilares
 **/
class SENHA : public Transforma_String{
private:
    std::string Senha;
    void validar(std::string senha);
    int repeticao(int numero, int* vet, int n);
public:
    void setSenha(std::string senha);
    /**
     * @brief adquire a senha do usuario
     * @return retorna a senha do usuario
     **/
    std::string getSenha() { return Senha; }
};

/**
 * @class NumeroCartao
 * @brief classe que representa o numero do cartao do usuario, contendo um atributo que representa o numero e metodos auxiliares
 **/
class NumeroCartao : public Transforma_String{
private:
    std::string NumCard;
    void validar(std::string numero);
public:
    void setNumCartao(std::string numero);
    /**
     * @brief adquire o numero do cartao do usuario
     * @return retorna o numero do cartao do usuario
     **/
    std::string getNumCartao() { return NumCard; }
};

/**
 * @class DataValidade
 * @brief classe que representa a data de validade do cartao, contendo um atributo que representa o codigo e metodos auxilares
 **/
class DataValidade : public Transforma_String{
private:
    std::string DataVal;
    void validar(std::string data);
public:
    void setDataValidade(std::string data);
    /**
     * @brief adquire a validade do cartao do usuario
     * @return retorna a validade do cartao do usuario
     **/
    std::string getDataValidade() { return DataVal; }

};

#endif
