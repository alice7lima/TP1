/**
 * @file: dominios.cpp
 *
 * @author1: Alice da Silva de Lima
 * @Matricula: 18/0112601
 * @author2: Giovana Pinho Garcia
 * @Matricula: 18/0101374
 *
 * @disciplina: Tecnicas de Programacao 1
 * @Professor: Washington Almeida
 *
 *Arquivo que descreve todos os métodos presentes nas classes de dominio */

#include "dominios.h"
#include <stdexcept>


void Transforma_String::setStr(std::string str){
    this->str = str;
}

void Transforma_Inteiro::setInt(int inteiro){
    this->inteiro = inteiro;
}

/**
 * @brief faz a validacao de todas as entradas que sao codigo
 * @param codigo String que representa o codigo a ser validado
 * @param n Tamanho do codigo
 **/
void Validacao::validar_cod(std::string codigo, int n){
    int i;
    if(codigo.length() != n){                   /*verificacao do tamanho do codigo*/
        throw std::invalid_argument("Argumento invalido");
    }

    for(i=0; i<codigo.length(); i++){                   /*verifica se todos os digitos sao numeros*/
        if(codigo.at(i) < '0' || codigo.at(i) > '9'){
            throw std::invalid_argument("Argumento invalido.");
        }
    }
}

/**
 * @brief atribui a numeracao do codigo a seu respectivo atributo apos valida-lo
 * @param codigo String que representa o codigo do jogo
 **/
void CodigoJogo::setCodJogo(std::string codigo){
    validar_cod(codigo, 3);
    CodJ = codigo;
}

/**
 * @brief atribui a numeracao do codigo a seu respectivo atributo apos valida-lo
 * @param codigo String que representa o codigo do ingresso
 **/

void CodigoIngresso::setCodIngresso (std::string codigo){
    validar_cod(codigo, 5);
    CodI = codigo;
}

/**
 * @brief faz a validacao do nome do jogo, conferindo o formato exigido
 * @param nome String que foi enviada pela funcao set
 * */

void NomeJogo::validar(std::string nome){
    int i, letra=0, espaco=0;
    if(nome.length()>20){                                    /*verificacao do tamanho*/
        throw std::invalid_argument("Argumento invalido");
    }

    for(i=0; i<nome.length(); i++){
        if(nome.at(i) == ' '){              /*verifica se ha dois espacos seguidos*/
            espaco += 1;
        }
        else{
            espaco = 0;
        }
        if((nome.at(i) >= 65 && nome.at(i) < 91) || (nome.at(i)>= 97 && nome.at(i) < 123)){ /*verifica se ha letras*/
            letra += 1;
        }
        if(espaco > 1){
            throw std::invalid_argument("Argumento inválido");
        }
    }

    if(letra = 0){
        throw std::invalid_argument("Argumento inválido");
    }

}

/**
 * @brief atribui o nome do jogo a seu respectivo atributo apos valida-lo
 * @param nome do tipo String que representa o nome do jogo
 **/

void NomeJogo::setNomeJogo (std::string nome){
    validar(nome);
    NomJ = nome;
}

/**
 * @brief faz a validação da data do jogo
 * @param data String que foi enviada pela funcao set
 **/

void Data::validar(std::string data){
    int valido=0, ano=0, aux1, aux2, i, mes, dia;
    char pdig, sdig;

    if(data.length() != 8){                        /*verifica o tamanho*/
        throw std::invalid_argument("Argumento inválido");
    }

    if(data.at(2) != '/' || data.at(5) != '/'){                 /*verifica se esta no formato XX/XX/XX*/
        throw std::invalid_argument("Argumento inválido");
    }

    for(i=0; i<data.length(); i++){
        if(i != 2 && i != 5){
            if(data.at(i) < '0' || data.at(i) > '9' ){          /*verifica se X e digito*/
                throw std::invalid_argument("Argumento invalido.");
            }
        }
    }

    pdig = data.at(6);          /*calculo do ano*/
    sdig = data.at(7);

    aux1 = int(pdig) - 48;
    aux2 = int(sdig) - 48;

    ano = (aux1*10) + aux2;


    pdig = data.at(3);              /*calculo do mes*/
    sdig = data.at(4);

    aux1 = int(pdig) - 48;
    aux2 = int(sdig) - 48;

    mes = (aux1*10) + aux2;

    pdig = data.at(0);              /*calculo do dia*/
    sdig = data.at(1);

    aux1 = int(pdig) - 48;
    aux2 = int(sdig) - 48;

    dia = (aux1*10) + aux2;

    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if(dia < 1 || dia > 31){
            throw std::invalid_argument("Argumento inválido");
        }
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if(dia < 1 || dia > 30){
            throw std::invalid_argument("Argumento inválido");
        }
    }
    else{
        if(ano%4 == 0){
            if(dia < 1 || dia > 29){
                throw std::invalid_argument("Argumento inválido");
            }
        }
        else{
            if(dia < 1 || dia > 28){
                throw std::invalid_argument("Argumento inválido");
            }
        }
    }
}

/**
 * @brief atribui a data do jogo a seu respectivo atributo apos valida-lo
 * @param data String que representa a data do jogo
 **/

void Data::setData (std::string data){
    validar(data);
    this->Date = data;
}

/**
 * @brief faz a validação do horario do jogo
 * @param hora String que foi enviada pela funcao set
 **/
void Horario::validar(std::string hora){
    int valido=0;

    if(hora.length() != 5){                     /*verifica o tamanho*/
        throw std::invalid_argument("Argumento inválido");
    }

    if(hora.at(0) >= '0' && hora.at(0) <= '2'){             /*testa as condicoes do formato da hora*/
        if((hora.at(0) == '0' && (hora.at(1) >= '7' && hora.at(1) <= '9')) || (hora.at(0) == '1' && (hora.at(1) >= '0' && hora.at(1) <= '9')) || (hora.at(0) == '2' && (hora.at(1)>='0' && hora.at(1)<='2'))){
            if(hora.at(2) == ':'){
                if(hora.at(3) >= '0' && hora.at(3) <= '4' && hora.at(3) != '2'){
                    if(((hora.at(3) == '0' || hora.at(3) == '3') && hora.at(4) == '0') || (hora.at(3) == '1' || hora.at(3) == '4') && hora.at(4) == '5'){
                        valido = 1;             /*flag auxiliar*/
                    }
                }
            }
        }
    }
    if(!valido){
        throw std::invalid_argument("Argumento inválido");
    }
}

/**
 * @brief atribui o horario do jogo a seu respectivo atributo apos valida-lo
 * @param hora String que representa a hora do jogo
 **/

void Horario::setHorario(std::string hora){
    validar(hora);
    this->Hora = hora;
}


/**
 * @brief faz a validação do preco do jogo
 * @param preco String que foi enviada pela funcao set
 **/
void Preco::validar(std::string preco){
    int i, tam;

    if(preco.length() < 7 || preco.length() > 11 || preco.length() == 10){
        throw std::invalid_argument("Argumento inválido");
    }

    tam = preco.length();

     /*verfica o formato R$ seguido de espaço e a virgula separando os reais dos centavos*/
    if(preco.at(0) != 'R' || preco.at(1) != '$' || preco.at(2) != ' ' || preco.at(tam-3) != ','){
        throw std::invalid_argument("Argumento inválido");
    }

    if (tam == 11 && preco != "R$ 1.000,00"){
        throw std::invalid_argument("Argumento inválido");
    }

    if(tam != 11){
        /*verifica se as demais posicoes sao numeros*/
        for(i=3; i<tam; i++){
            if(i != tam-3){
                if(preco.at(i) < '0' || preco.at(i) > '9'){
                    throw std::invalid_argument("Argumento inválido");
                }
            }
        }
    }
}

/**
 * @brief atribui o preco do ingresso a seu respectivo atributo apos valida-lo
 * @param preco String que representa o valor do ingresso
 **/

void Preco::setPreco(std::string preco){
    validar(preco);
    this->preco = preco;
}


/**
 * @brief faz a validacao da cidade do jogo
 * @param cidade String que foi enviada pela funcao set
 **/
void Cidade::validar(std::string cidade){
    int i, espaco=0;
    if(cidade.length()>15){                /*verificando o tamanho*/
        throw std::invalid_argument("Argumento inválido");
    }

    for(i=0; i<cidade.length(); i++){
        if(cidade.at(i) == ' '){       /*verificando espacos seguidos*/
            espaco += 1;
        }
        else{
            espaco = 0;
        }

        if(cidade.at(i) == '.'){           /*verificando se o . e precedido por letra.*/
            if (i == 0){
                throw std::invalid_argument("Argumento inválido");
            }

            if((cidade.at(i-1) < 65 || cidade.at(i-1) >= 91) && (cidade.at(i-1) < 97 || cidade.at(i-1) >= 123)){
                throw std::invalid_argument("Argumento inválido");
            }
        }

        if(espaco > 1){
            throw std::invalid_argument("Argumento inválido");
        }
    }

}

/**
 * @brief atribui a cidade onde ocorrera o jogo a seu respectivo atributo apos valida-lo
 * @param cidade String que representa a cidade onde ocorrera um jogo
 **/

void Cidade::setCidade(std::string cidade){
    validar(cidade);
    Cid = cidade;
}


/**
 * @brief faz a validacao do estado onde ocorre o jogo
 * @param Est String que foi enviada pela funcao set
 **/
void Estado::validar(std::string Est){
    int valido=0;


    if(Est.at(0) == 'A'){
        if(Est.at(1) == 'C' || Est.at(1) == 'L' || Est.at(1) == 'P' || Est.at(1) == 'M'){
            valido = 1;
        }
    }
    else if(Est == "BA" || Est == "CE" || Est == "DF" || Est == "ES" || Est == "GO" || Est == "TO"){
        valido = 1;
    }
    else if(Est.at(0) == 'M'){
        if(Est.at(1) == 'A' || Est.at(1) == 'T' || Est.at(1) == 'S' || Est.at(1) == 'G'){
            valido = 1;
        }
    }
    else if(Est.at(0) == 'P'){
        if(Est.at(1) == 'A' || Est.at(1) == 'B' || Est.at(1) == 'R' || Est.at(1) == 'E' || Est.at(1) == 'I'){
            valido = 1;
        }
    }
    else if(Est.at(0) == 'R'){
        if(Est.at(1) == 'J' || Est.at(1) == 'N' || Est.at(1) == 'S' || Est.at(1) == 'O' || Est.at(1) == 'R'){
            valido = 1;
        }
    }
    else if(Est.at(0) == 'S'){
        if(Est.at(1) == 'C' || Est.at(1) == 'P' || Est.at(1) == 'E'){
            valido = 1;
        }
    }

    if(!valido){
        throw std::invalid_argument("Argumento inválido");
    }
}

/**
 * @brief atribui o estado onde ocorrera o jogo a seu respectivo atributo apos valida-lo
 * @param Est String que representa o estado onde ocorrera um jogo
 **/

void Estado::setEstado(std::string Est){
    validar(Est);
    this->Est = Est;
}

/**
 * @brief faz a validacao da disponibilidade de ingressos do jogo
 * @param disp String que foi enviada pela funcao set
 **/
void Disponibilidade::validar(int disp){
    if(disp < 0 || disp > 250){
        throw std::invalid_argument("Argumento inválido");
    }
}

/**
 * @brief atribui a disponibilidade de ingressos a seu respectivo atributo apos valida-lo
 * @param disp String que representa a disponibilidade de ingressos de um jogo
 **/

void Disponibilidade::setDisponibilidade(int disp){
    validar(disp);
    this->Disp = disp;
}

/**
 * @brief faz a validação do CPF do usuário
 * @param cpf String que foi enviada pela funcao set
 **/
void CPF::validar(std::string cpf){
    int i, auxvalida=0, j=10, k=0;
    int vet[11];

    if(cpf.length() != 14){
        throw std::invalid_argument("Argumento inválido");
    }

    if(cpf.at(3) != '.' || cpf.at(7) != '.' || cpf.at(11) != '-'){      /*verifica se ha pontos e traco nos lugares corretos*/
        throw std::invalid_argument("Argumento inválido");
    }

    for(i = 0; i< cpf.length(); i++){
        if(i != 3 && i != 7 && i != 11){
            if(cpf.at(i) < 48 || cpf.at(i) > 57){       /*verifica se os digitos do cpf nao sao . ou - ou numero*/
                throw std::invalid_argument("Argumento inválido");
            }
        }
    }

    for(i=0; i<14; i++){                /*passa os numeros do cpf para um vetor de strings*/
        if(cpf.at(i) != '.' && cpf.at(i) != '-'){
            vet[k] = int(cpf.at(i)) - 48;
            k++;
        }
    }

    for(i=0; i<9; i++){
        auxvalida += vet[i]*j;
        j--;
    }

    auxvalida = (auxvalida*10)%11;

    if(auxvalida == 10){
        auxvalida = 0;
    }

    if(auxvalida != vet[9]){            /*se o resto da divisao for diferente do primeiro digito verificador*/
        throw std::invalid_argument("Argumento inválido.");
    }

    auxvalida = 0;
    j = 11;

    for(i=0; i<10; i++){
        auxvalida += vet[i]*j;
        j--;
    }

    auxvalida = (auxvalida*10)%11;

    if(auxvalida == 10){
        auxvalida = 0;
    }

    if(auxvalida != vet[10]){            /*se o resto da divisao for diferente do primeiro digito verificador*/
        throw std::invalid_argument("Argumento inválido.");
    }

}

/**
 * @brief atribui o CPF do usuario a seu respectivo atributo apos valida-lo
 * @param CPF String que representa o CPF do usuario do sistema
 **/

void CPF::setCPF(std::string cpf){
    validar(cpf);
    this->cpf = cpf;
}

/**
 * @brief checa se tem numeros repetidos na senha do usuario
 * @param numero Valor que sera comparado e adicionado ao vetor
 * @param vet Vetor que tem todos os valores digitados pelo usuario para fazer a comparacao
 * @param n Quantidade de digitos que foram digitados ate o momento
 * @return Retorna 1 caso haja numeros repetidos, caso contrario, retorna 0
 **/
int SENHA::repeticao(int numero, int* vet, int n){
    int i;
    for(i=0; i<n; i++){
        if(vet[i] == numero){               /*verifica se o novo caractere ja esta incluido na senha*/
            return 1;
        }
    }

    return 0;
}


/**
 * @brief faz a validacao da senha do usuario
 * @param senha String que foi enviada pela funcao set
 **/
void SENHA::validar(std::string senha){
    int vet[6];
    int i, j=0, num;
    int flag=0, letraMa = 0, letraMi = 0, dig = 0; /*flags auxiliares*/

    if(senha.length() != 6){
        throw std::invalid_argument("Argumento inválido");
    }

    for(i=0; i<6; i++){
        num = int(senha.at(i));
        flag = repeticao(num, vet, i);

        if(flag){
            throw std::invalid_argument("Argumento invalido.");
        }

        vet[j] = int(senha.at(i));
        j++;

    }

    for(i=0; i<6; i++){
        if(senha.at(i) >= 'a' && senha.at(i) <= 'z'){
            letraMi = 1;
        }
        else if(senha.at(i) >= 'A' && senha.at(i) <= 'Z'){
            letraMa = 1;

        }
        else if(senha.at(i) >= '0' && senha.at(i) <= '9'){
            dig = 1;
        }
    }

    if(letraMi != 1 || letraMa != 1 || dig != 1){
        throw std::invalid_argument("Argumento inválido");
    }
}

/**
 * @brief atribui a senha do usuario a seu respectivo atributo apos valida-lo
 * @param senha String que representa a senha do usuario
 **/

void SENHA::setSenha(std::string senha){
    validar(senha);
    this->Senha = senha;
}


/**
 * @brief faz a validacao do numero do cartao do usuario
 * @param numero String que foi enviada pela funcao set
 **/
void NumeroCartao::validar(std::string numero){
    int i, soma=0;
    int vet[16];

    if(numero.length() != 16){
        throw std::invalid_argument("Argumento inválido");
    }

    for(i=0; i<numero.length(); i++){
        if(numero.at(i) < '0' || numero.at(i) > '9'){
            throw std::invalid_argument("Argumento inválido");
        }
    }

    for(int i = 0; i<16; i++){
        vet[15 - i] = int(numero.at(i)) - 48;
    }

    for(int i = 0; i<16; i++){
        if(i%2 == 1){
            vet[i] *= 2;
        }
        if(vet[i] > 9){
            vet[i] -= 9;
        }
        soma += vet[i];
    }

    if(soma%10 != 0){
        throw std::invalid_argument("Argumento inválido");
    }
}

/**
 * @brief atribui o numero do cartao do usuario a seu respectivo atributo apos valida-lo
 * @param numero String que representa o numero do cartao do usuario
 **/

void NumeroCartao::setNumCartao(std::string numero){
    validar(numero);
    this->NumCard = numero;
}

/**
 * @brief atribui o codigo de seguranca do cartao a seu respectivo atributo apos valida-lo
 * @param CodS String que representa o codigo de seguranca do cartao de credito
 **/

void CodigoSeguranca::setCodSeguranca(std::string CodS){
    validar_cod(CodS, 3);
    this->CodS = CodS;
}


/**
 * @brief faz a validacao da data de validade do cartao do usuario
 * @param data String que foi enviada pela funcao set
 **/
void DataValidade::validar(std::string data){
    char pdig, sdig;
    int aux1, aux2, mes, ano, i;

    if(data.length() != 5){
        throw std::invalid_argument("Argumento inválido");
    }

    if(data.at(2) != '/'){
        throw std::invalid_argument("Argumento inválido");
    }

    for(i=0; i<data.length(); i++){
        if(i != 2){
            if(data.at(i) < '0' || data.at(i) > '9' ){
                throw std::invalid_argument("Argumento invalido.");
            }
        }
    }
    pdig = data.at(0);          /*calculando o mes*/
    sdig = data.at(1);

    aux1 = int(pdig) - 48;
    aux2 = int(sdig) - 48;

    mes = (aux1*10) + aux2;

    if(mes < 1 || mes > 12){
        throw std::invalid_argument("Argumento invalido.");
    }
}

/**
 * @brief atribui a data de validade do cartao a seu respectivo atributo apos valida-lo
 * @param data String que representa a data de validade do cartao
 **/

void DataValidade::setDataValidade(std::string data){
    validar(data);
    this->DataVal = data;
}



