/**
 * @file: Testes.cpp
 *
 * @author1: Alice da Silva de Lima
 * @Matricula: 18/0112601
 * @author2: Giovana Pinho Garcia
 * @Matricula: 18/0101374
 *
 * @disciplina: Tecnicas de Programacao 1
 * @Professor: Washington Almeida
 *
 *Arquivo que descreve todos os metodos presentes nas classes responsaveis pelos testes unitarios */

#include "Testes.h"

/**
 * @brief cria um objeto do tipo CodigoJogo e atribui ao estado o valor SUCESSO
 **/
void TesteCodigoJogo::cria(){
   codigo = new CodigoJogo();
   estado = SUCESSO;
}

/**
 * @brief deleta o codigo criado na funcao cria
 **/
void TesteCodigoJogo::destroi(){
    delete codigo;
}

/**
 * @brief testa um codigo do jogo valido, verificando se o valor que chega ate a funcao set e realmente o enviado
**/
void TesteCodigoJogo::cenarioSucesso(){
    try{
        codigo->setCodJogo(VALIDO);
        if (codigo->getCodJogo() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }

}

/**
 * @brief testa um codigo invalido e mostra que a funcao set nao deixara este valor ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteCodigoJogo::cenarioFalha(){
    try{
        codigo->setCodJogo(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}


/**
 * @brief testa o codigo do jogo para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteCodigoJogo::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo CodigoIngresso e atribui ao estado o valor SUCESSO
 **/
void TesteCodigoIngresso::cria(){
    codigo = new CodigoIngresso();
    estado = SUCESSO;
}

/**
 * @brief deleta o codigo criado na funcao cria
 **/
void TesteCodigoIngresso::destroi(){
    delete codigo;
}

/**
 * @brief testa um codigo de ingresso valido, verificando tambem se o valor que chega a funcao set e realmente o enviado
 **/

void TesteCodigoIngresso::cenarioSucesso(){
    try{
        codigo->setCodIngresso(VALIDO);
        if (codigo->getCodIngresso() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um codigo invalido e mostra que a funcao set nao deixara este valor ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/

void TesteCodigoIngresso::cenarioFalha(){
    try{
        codigo->setCodIngresso(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o codigo do ingresso para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteCodigoIngresso::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo CodigoSeguranca e atribui ao estado o valor SUCESSO
 **/
void TesteCodigoSeguranca::cria(){
    codigo = new CodigoSeguranca();
    estado = SUCESSO;
}

/**
 * @brief deleta o codigo criado na funcao cria
 **/
void TesteCodigoSeguranca::destroi(){
    delete codigo;
}

/**
 * @brief testa um codigo de seguranca valido, verificando tambem se o valor que chega a funcao set e realmente o enviado
 **/

void TesteCodigoSeguranca::cenarioSucesso(){
    try{
        codigo->setCodSeguranca(VALIDO);
        if (codigo->getCodSeguranca() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }

}

/**
 * @brief testa um codigo invalido e mostra que a funcao set nao deixara este valor ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteCodigoSeguranca::cenarioFalha(){
    try{
        codigo->setCodSeguranca(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o codigo de seguranca para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteCodigoSeguranca::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}


/**
 * @brief cria um objeto do tipo NomeJogo e atribui ao estado o valor SUCESSO
 **/
void TesteNomeJogo::cria(){
    nome = new NomeJogo();
    estado = SUCESSO;
}

/**
 * @brief deleta o nome criado na funcao cria
 **/
void TesteNomeJogo::destroi(){
    delete nome;
}

/**
 * @brief testa um nome de jogo valido, verificando tambem se o nome que chega a funcao set e realmente o enviado
 **/

void TesteNomeJogo::cenarioSucesso(){
    try{
        nome->setNomeJogo(VALIDO);
        if (nome->getNomeJogo() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }

}

/**
 * @brief testa um nome invalido e mostra que a funcao set nao deixara este nome ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/

void TesteNomeJogo::cenarioFalha(){
    try{
        nome->setNomeJogo(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o nome do jogo para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteNomeJogo::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo Horario e atribui ao estado o valor SUCESSO
 **/
void TesteHorario::cria(){
    hora = new Horario();
    estado = SUCESSO;
}

/**
 * @brief deleta a hora criada na funcao cria
 **/
void TesteHorario::destroi(){
    delete hora;
}

/**
 * @brief testa um horario em formato valido, verificando tambem se o horario que chega a funcao set e realmente o enviado
 **/

void TesteHorario::cenarioSucesso(){
    try{
        hora->setHorario(VALIDO);
        if (hora->getHorario() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um horario em formato invalido e mostra que a funcao set nao deixara este horario ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/

void TesteHorario::cenarioFalha(){
    try{
        hora->setHorario(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o horario do jogo para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteHorario::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo Data e atribui ao estado o valor SUCESSO
 **/
void TesteData::cria(){
    data = new Data();
    estado = SUCESSO;
}

/**
 * @brief deleta a data criada na funcao cria
 **/
void TesteData::destroi(){
    delete data;
}

/**
 * @brief testa uma data em formato valido, verificando tambem se a data que chega a funcao set e realmente o enviado
 **/

void TesteData::cenarioSucesso(){
    try{
        data->setData(VALIDO);
        if (data->getData() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa uma data em formato invalido e mostra que a funcao set nao deixara esta data ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/

void TesteData::cenarioFalha(){
    try{
        data->setData(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa a data do jogo para saber se e valida
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteData::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo Preco e atribui ao estado o valor SUCESSO
 **/
void TestePreco::cria(){
    preco = new Preco();
    estado = SUCESSO;
}

/**
 * @brief deleta o preco criado na funcao cria
 **/
void TestePreco::destroi(){
    delete preco;
}

/**
 * @brief testa um preco em formato valido, verificando tambem se o preco que chega a funcao set e realmente o enviado
 **/

void TestePreco::cenarioSucesso(){
    try{
        preco->setPreco(VALIDO);
        if (preco->getPreco() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um preco em formato invalido e mostra que a funcao set nao deixara este preco ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/

void TestePreco::cenarioFalha(){
    try{
        preco->setPreco(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o preco do jogo para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TestePreco::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo Cidade e atribui ao estado o valor SUCESSO
 **/
void TesteCidade::cria(){
    cidade = new Cidade();
    estado = SUCESSO;
}

/**
 * @brief deleta a cidade criada na funcao cria
 **/
void TesteCidade::destroi(){
    delete cidade;
}

/**
 * @brief testa um nome de cidade valido, verificando tambem se o nome que chega a funcao set e realmente o enviado
 **/

void TesteCidade::cenarioSucesso(){
    try{
        cidade->setCidade(VALIDO);
        if (cidade->getCidade() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um nome de cidade invalido e mostra que a funcao set nao deixara este nome ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteCidade::cenarioFalha(){
    try{
        cidade->setCidade(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa a cidade do jogo para saber se e valida
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteCidade::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo Estado e atribui ao estado o valor SUCESSO
 **/
void TesteEstado::cria(){
    est = new Estado();
    estado = SUCESSO;
}

/**
 * @brief deleta o estado criado na funcao cria
 **/
void TesteEstado::destroi(){
    delete est;
}

/**
 * @brief testa uma sigla de estado valida, verificando tambem se a sigla que chega a funcao set e realmente o enviado
 **/

void TesteEstado::cenarioSucesso(){
    try{
        est->setEstado(VALIDO);
        if (est->getEstado() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa uma sigla de estado invalida e mostra que a funcao set nao deixara esta sigla ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/

void TesteEstado::cenarioFalha(){
    try{
        est->setEstado(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o Estado do jogo para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteEstado::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo Disponibilidade e atribui ao estado o valor SUCESSO
 **/
void TesteDisponibilidade::cria(){
    disp = new Disponibilidade();
    estado = SUCESSO;
}

/**
 * @brief deleta a disponibilidade criada na funcao cria
 **/
void TesteDisponibilidade::destroi(){
    delete disp;
}

/**
 * @brief testa um valor de disponibilidade valido, verificando tambem se o valor que chega a funcao set e realmente o enviado
 **/
void TesteDisponibilidade::cenarioSucesso(){
    try{
        disp->setDisponibilidade(VALIDO);
        if (disp->getDisponibilidade() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um numero de disponibilidade invalida e mostra que a funcao set nao deixara este numero ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteDisponibilidade::cenarioFalha(){
    try{
        disp->setDisponibilidade(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa a disponibilidade de ingressos para saber se e valida
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteDisponibilidade::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}


/**
 * @brief cria um objeto do tipo CPF e atribui ao estado o valor SUCESSO
 **/
void TesteCPF::cria(){
    cpf = new CPF();
    estado = SUCESSO;
}

/**
 * @brief deleta o cpf criado na funcao cria
 **/
void TesteCPF::destroi(){
    delete cpf;
}

/**
 * @brief testa um numero de CPF valido, verificando tambem se o CPF que chega a funcao set e realmente o enviado
 **/
void TesteCPF::cenarioSucesso(){
    try{
        cpf->setCPF(VALIDO);
        if (cpf->getCPF() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um numero de CPF invalido e mostra que a funcao set nao deixara este CPF ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteCPF::cenarioFalha(){
    try{
        cpf->setCPF(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o CPF do usuario para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteCPF::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo SENHA e atribui ao estado o valor SUCESSO
 **/
void TesteSENHA::cria(){
    senha = new SENHA();
    estado = SUCESSO;
}

/**
 * @brief deleta a senha criada na funcao cria
 **/
void TesteSENHA::destroi(){
    delete senha;
}

/**
 * @brief testa uma senha valida, verificando tambem se a senha que chega a funcao set e realmente a enviada
 **/
void TesteSENHA::cenarioSucesso(){
    try{
        senha->setSenha(VALIDO);
        if (senha->getSenha() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa uma senha invalida e mostra que a funcao set nao deixara esta senha ser atribuida ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteSENHA::cenarioFalha(){
    try{
        senha->setSenha(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa a senha do usuario para saber se e valida
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteSENHA::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo NumeroCartao e atribui ao estado o valor SUCESSO
 **/
void TesteNumCartao::cria(){
    numcard = new NumeroCartao();
    estado = SUCESSO;
}

/**
 * @brief deleta o numero do cartao criado na funcao cria
 **/
void TesteNumCartao::destroi(){
    delete numcard;
}

/**
 * @brief testa um numero de cartao valido, verificando tambem se o numero que chega a funcao set e realmente o enviado
 **/
void TesteNumCartao::cenarioSucesso(){
    try{
        numcard->setNumCartao(VALIDO);
        if (numcard->getNumCartao() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um numero de cartao invalido e mostra que a funcao set nao deixara este numero ser atribuido ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteNumCartao::cenarioFalha(){
    try{
        numcard->setNumCartao(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa o numero do cartao do usuario para saber se e valido
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteNumCartao::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}

/**
 * @brief cria um objeto do tipo DataValidade e atribui ao estado o valor SUCESSO
 **/
void TesteDataValidade::cria(){
    data = new DataValidade();
    estado = SUCESSO;
}

/**
 * @brief deleta a data de validade criada na funcao cria
 **/
void TesteDataValidade::destroi(){
    delete data;
}

/**
 * @brief testa uma data de validade valida, verificando tambem se a data que chega a funcao set e realmente a enviada
 **/
void TesteDataValidade::cenarioSucesso(){
    try{
        data->setDataValidade(VALIDO);
        if (data->getDataValidade() != VALIDO){
            estado = FALHA;
        }
    }
    catch(std::invalid_argument excecao){
        estado = FALHA;
    }
}

/**
 * @brief testa um data de validade invalida e mostra que a funcao set nao deixara esta data ser atribuida ao respectivo atributo,
 * assim evitando o estado FALHA
**/
void TesteDataValidade::cenarioFalha(){
    try{
        data->setDataValidade(INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument excecao){
        return;
    }
}

/**
 * @brief testa a data de validade do cartao do usuario para saber se e valida
 * @return Retorna o estado (SUCESSO ou FALHA)
 **/
int TesteDataValidade::testa(){
    cria();
    cenarioSucesso();
    cenarioFalha();
    destroi();
    return estado;
}
