#include <stdexcept>

#include "stubs.h"
#include "dominios.h"
#include "entidade.h"

const std::string StubsAutentica::TRIGGER_FALHA_CPF = "111.111.111-11";
const std::string StubsAutentica::TRIGGER_ERRO_CPF = "123.123.123-12";
const std::string StubsAutentica::TRIGGER_FALHA_SENHA = "aaaaa";
const std::string StubsAutentica::TRIGGER_ERRO_SENHA = "11111";

bool StubsAutentica::autenticar(std::string cpf, std::string senha){
    if(cpf == TRIGGER_FALHA_CPF || senha == TRIGGER_FALHA_SENHA){
        return false;
    }
    else if(cpf == TRIGGER_ERRO_CPF || senha == TRIGGER_ERRO_SENHA){
        throw std::runtime_error("Erro de sistema");
    }

    else{
        if(servico_armazena->autentica_usuario(cpf, senha)){
            return true;
        }
        else{
            return false;
        }
    }
}

const std::string StubsUsuario:: TRIGGER_FALHA_CPF = "123.456.789-12";
const std::string StubsUsuario:: TRIGGER_ERRO_CPF_DESCADASTRAR = "000.000.000-00";
const std::string StubsUsuario:: TRIGGER_ERRO_CPF_CADASTRAR = "123.456.789-00";
const std::string StubsUsuario:: TRIGGER_FALHA_SENHA = "ABBBBA";
const std::string StubsUsuario:: TRIGGER_ERRO_SENHA_DESCADASTRAR = "123456";
const std::string StubsUsuario:: TRIGGER_ERRO_SENHA_CADASTRAR = "bcbcbcb";
const std::string StubsUsuario:: TRIGGER_FALHA_NUMERO_CARTAO = "123456789123456A";
const std::string StubsUsuario:: TRIGGER_ERRO_NUMERO_CARTAO = "0000000000000000";
const std::string StubsUsuario:: TRIGGER_FALHA_CODIGO_SEGURANCA = "abc";
const std::string StubsUsuario:: TRIGGER_ERRO_CODIGO_SEGURANCA = "1234";
const std::string StubsUsuario:: TRIGGER_FALHA_DATA = "13/22";
const std::string StubsUsuario:: TRIGGER_ERRO_DATA = "123/10";

bool StubsUsuario::cadastrar(CPF cpf, SENHA senha, NumeroCartao numero, CodigoSeguranca codigo, DataValidade data) throw(std::runtime_error){ 
    Usuario usuario;

    if(cpf.getCPF() == TRIGGER_FALHA_CPF || senha.getSenha() == TRIGGER_FALHA_SENHA || numero.getNumCartao() == TRIGGER_FALHA_NUMERO_CARTAO || codigo.getCodSeguranca() == TRIGGER_FALHA_CODIGO_SEGURANCA || data.getDataValidade() == TRIGGER_FALHA_DATA){ /*mudar condicional*/
        return false;
    }
    else if(cpf.getCPF() == TRIGGER_ERRO_CPF_CADASTRAR || senha.getSenha() == TRIGGER_ERRO_SENHA_CADASTRAR || numero.getNumCartao() == TRIGGER_ERRO_NUMERO_CARTAO || codigo.getCodSeguranca() == TRIGGER_ERRO_CODIGO_SEGURANCA || data.getDataValidade() == TRIGGER_ERRO_DATA){
        throw std::runtime_error("Erro de sistema");
    }

    else{
        usuario.setCPF(cpf);
        usuario.setSENHA(senha);
        usuario.setNumCartao(numero);
        usuario.setCodSeguranca(codigo);
        usuario.setDataValidade(data);

        /*confere se ha um usuario com tal cpf*/
        if(!servico_armazena->confere_cpf(cpf)){
            std::cout << "Esse cpf ja foi cadastrado" << std::endl;
            return false;
        }

        servico_armazena->armazena_usuario(usuario); /*invocar metodo que adc o usuario na lista de cadastros*/
        
        return true;
    }
}

bool StubsUsuario::descadastrar(std::string cpf, std::string senha){
    if(cpf == TRIGGER_FALHA_CPF || senha == TRIGGER_FALHA_SENHA){
        return false;
    }
    else if(cpf == TRIGGER_ERRO_CPF_DESCADASTRAR || senha == TRIGGER_ERRO_SENHA_DESCADASTRAR){
        throw std::runtime_error("Erro de sistema");
    }

    else{
        /*confere se usuario tem algum jogo cadastrado*/
        if(!servico_armazena->confere_cadastrado(cpf)){
            std::cout << "Esse usuario nao pode ser descadastrado, pois ele tem jogos cadastrados" << std::endl;
            return false;
        }
        else{
            if(!servico_armazena->remove_usuario(cpf, senha)){
                return false;
            }
        }
        return true;
    }
}

const std::string StubsJogos::TRIGGER_FALHA_NOME_JOGO = "Sao    Paulo";
const std::string StubsJogos::TRIGGER_ERRO_NOME_JOGO = "123 22";
const std::string StubsJogos::TRIGGER_FALHA_CODIGO_JOGO = "1378";
const std::string StubsJogos::TRIGGER_ERRO_CODIGO_JOGO = "1AB";
const std::string StubsJogos::TRIGGER_FALHA_DATA = "29/02/15";
const std::string StubsJogos::TRIGGER_ERRO_DATA = "37/08/19";
const std::string StubsJogos::TRIGGER_FALHA_HORARIO = "04:11";
const std::string StubsJogos::TRIGGER_ERRO_HORARIO = "02:199";
const std::string StubsJogos::TRIGGER_FALHA_CIDADE = "Sao    Paulo";
const std::string StubsJogos::TRIGGER_ERRO_CIDADE = ". Sao Paulo";
const std::string StubsJogos::TRIGGER_FALHA_ESTADO = "RF";
const std::string StubsJogos::TRIGGER_ERRO_ESTADO = "12";
const std::string StubsJogos::TRIGGER_FALHA_PRECO = "R$ 1.300,00";
const std::string StubsJogos::TRIGGER_ERRO_PRECO = "200,00";
const std::string StubsJogos::TRIGGER_FALHA_CODIGO_INGRESSO = "A444T";
const std::string StubsJogos::TRIGGER_ERRO_CODIGO_INGRESSO = "AAAA";

bool StubsJogos::cadastrar(NomeJogo nome, CodigoJogo codJ, Data data, Horario hora, Cidade cidade, Estado estado, Preco preco, CodigoIngresso codI, CPF cpf, Disponibilidade disp){
    Jogo jogo;
    if(nome.getNomeJogo() == TRIGGER_FALHA_NOME_JOGO || codJ.getCodJogo() == TRIGGER_FALHA_CODIGO_JOGO || data.getData() == TRIGGER_FALHA_DATA || hora.getHorario() == TRIGGER_FALHA_HORARIO || cidade.getCidade() == TRIGGER_FALHA_CIDADE || estado.getEstado() == TRIGGER_FALHA_ESTADO || preco.getPreco() == TRIGGER_FALHA_PRECO || codI.getCodIngresso() == TRIGGER_FALHA_CODIGO_INGRESSO){
        return false;
    }
    else if(nome.getNomeJogo() == TRIGGER_ERRO_NOME_JOGO || codJ.getCodJogo() == TRIGGER_ERRO_CODIGO_JOGO || data.getData() == TRIGGER_ERRO_DATA || hora.getHorario() == TRIGGER_ERRO_HORARIO || cidade.getCidade() == TRIGGER_ERRO_CIDADE || estado.getEstado() == TRIGGER_ERRO_ESTADO || preco.getPreco() == TRIGGER_ERRO_PRECO || codI.getCodIngresso() == TRIGGER_ERRO_CODIGO_INGRESSO){
        throw std::runtime_error("Erro de sistema");
    }
    else{
        jogo.setNomeJogo(nome);
        jogo.setCodJogo(codJ);
        jogo.setDisponibilidade(disp);
        jogo.setData(data);
        jogo.setHorario(hora);
        jogo.setCidade(cidade);
        jogo.setEstado(estado);
        jogo.setPreco(preco);
        jogo.setCodIngresso(codI);
        jogo.setCPF(cpf);
        
        servico_armazena->armazena_jogo(jogo);
        return true;
    }
}

bool StubsJogos::existejogo(std::string cpf, std::string codJ){
    if(codJ == TRIGGER_FALHA_CODIGO_JOGO){
        return false;
    }
    else if(codJ == TRIGGER_ERRO_CODIGO_JOGO){
        throw std::runtime_error("Erro de sistema");
    }
    else{
        if(!servico_armazena->existe(cpf, codJ)){
            return false;
        }
        return true;
    }
}

bool StubsJogos::alterarjogo(CodigoJogo codJ, NomeJogo nome, CodigoIngresso codI, Data data, Horario hora, Preco preco, Cidade cidade, Estado estado, CPF cpf, Disponibilidade disp){
    if(codJ.getCodJogo() == TRIGGER_FALHA_CODIGO_JOGO){
        return false;
    }
    else if(codJ.getCodJogo() == TRIGGER_ERRO_CODIGO_JOGO){
        throw std::runtime_error("Erro de sistema");
    }
    
    else{
        if(descadastrar(codJ.getCodJogo())){
            if(cadastrar(nome, codJ, data, hora, cidade, estado, preco, codI, cpf, disp)){
                return true;
            }                
            else{
                std::cout << "Ocorreu um erro." << std::endl;
            }
        }
    }
}

bool StubsJogos::descadastrar(std::string codJ) {
    if(codJ == TRIGGER_FALHA_CODIGO_JOGO){
        return false;
    }
    else if(codJ == TRIGGER_ERRO_CODIGO_JOGO){
        throw std::runtime_error("Erro de sistema");
    }
    else{
        /*procedimento que confere se ja foi vendido algum ingresso*/
        if(!servico_armazena->confere_vendido(codJ)){
            std::cout << "Esse jogo nao pode ser alterado, pois ja foram vendidos ingressos" << std::endl;
            return false;
        }

        /*procedimento que tira da lista*/
        servico_armazena->remove_jogo(codJ);
        return true;
    }
}

bool StubsJogos::buscar(Data data, Cidade cidade, Estado est){
    
    if(data.getData() == TRIGGER_FALHA_DATA || cidade.getCidade() == TRIGGER_FALHA_CIDADE || est.getEstado() == TRIGGER_FALHA_ESTADO){
        return false;
    }
    else if(data.getData() == TRIGGER_ERRO_DATA || cidade.getCidade() == TRIGGER_ERRO_CIDADE || est.getEstado() == TRIGGER_ERRO_ESTADO){
        throw std::runtime_error("Erro de sistema");
    }
    else{
        /*metodo que procura no arquivo e mostra as infos do jogo*/
        servico_armazena->busca_jogo(data, cidade, est);
        return true;
    }
}

bool StubsJogos::obter_dados(std::string codJ){
    if(codJ == TRIGGER_FALHA_CODIGO_JOGO){
        return false;
    }
    else if(codJ == TRIGGER_ERRO_CODIGO_JOGO){
        throw std::runtime_error("Erro de sistema");
    }
    else{
        servico_armazena->busca_infos(codJ);
        return true;
    }
}

const int StubsVendas:: LIMITE_INGRESSOS = 250;
const std::string StubsVendas:: TRIGGER_FALHA_CODIGO_INGRESSO = "A444T";
const std::string StubsVendas:: TRIGGER_ERRO_CODIGO_INGRESSO = "AAAA";

bool StubsVendas::comprar(CodigoJogo codJ, int quantidade, std::string cpf){
    if(codJ.getCodJogo() == TRIGGER_FALHA_CODIGO_INGRESSO || quantidade > LIMITE_INGRESSOS){
        return false;
    }
    else if(codJ.getCodJogo() == TRIGGER_ERRO_CODIGO_INGRESSO){
        throw std::runtime_error("Erro de sistema");
    }
    else{

        if(servico_armazena->compra_ingresso(codJ, quantidade)){
            servico_armazena->armazena_ingresso(codJ, quantidade, cpf);

            return true;
        }

        /*muda a disponibilidade*/
        /*adc na lista de ingressos*/
        return false;
    }
}

