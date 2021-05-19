#include "controladoras.h"

void ControlaUsuario::cadastrar(){
//deve informar cpf, senha, num do cartao, codigo de seguranca e data de validade
    std::string entrada;
    CPF cpf;
    SENHA senha;
    NumeroCartao NumCard;
    CodigoSeguranca CodSeg;
    DataValidade DataVal;
    system("cls");
    try{

        std::cout << "\tCADASTRO" << std::endl;

        std::cout << "CPF: " << std::endl;
        std::cin >> entrada;
        cpf.setCPF(entrada);

        std::cout << "Senha: " << std::endl;
        std::cin >> entrada;
        senha.setSenha(entrada);

        std::cout << "\n\tInformacoes do Cartao\n" << std::endl;
        std::cout << "Numero do Cartao: " << std::endl;
        std::cin >> entrada;
        NumCard.setNumCartao(entrada);

        std::cout << "Codigo de Seguranca" << std::endl;
        std::cin >> entrada;
        CodSeg.setCodSeguranca(entrada);

        std::cout << "Data de Validade" << std::endl;
        std::cin >> entrada;
        DataVal.setDataValidade(entrada);


        if (controlaserv->cadastrar(cpf, senha, NumCard, CodSeg, DataVal)){
            std::cout << "Cadastro realizado com sucesso" << std::endl;
        }
    }
    catch(const std::invalid_argument &exp){
        std::cout << exp.what() <<  " ,tente novamente mais tarde" <<std::endl<< std::endl;
        return;
    }
    //manda pra camada de serviço 
    
    //deve informar se foi usuario foi cadastrado com sucesso apos autentificacao dos dados
}

void ControlaUsuario::descadastrar(){
    std::string entrada1, entrada2;

    std::cout << "Por favor digite seu CPF: " << std::endl;
    std::cin >> entrada1;
    std::cout << "Por favor digite sua senha: " << std::endl;
    std::cin >> entrada2;

    if(controlaserv->descadastrar(entrada1, entrada2)){
        std::cout << "Descadastro realizado com sucesso" << std::endl;
    }
    else{
        std::cout << "Usuario nao foi descadastrado" << std::endl;
    }
}

void ControlaJogos::cadastrar(){
    std::string entrada1, entrada2, entrada;
    int aux;
    system("cls");
    CPF cpf;
    CodigoJogo codJ;
    NomeJogo nome;
    CodigoIngresso codI;
    Data data;
    Horario hora;
    Preco preco;
    Disponibilidade disp;
    Cidade cidade;
    Estado estado;
    
    try{

        std::cout << "CADA USUARIO PODE CADASTRAR NO MAXIMO 5 JOGOS" << std::endl << std::endl;

        std::cout << "\t" << "AUTENTICACAO" << std::endl;
        std::cout << "Por favor digite seu CPF: " << std::endl;
        std::cin >> entrada1;
        std::cout << "Por favor digite sua senha: " << std::endl;
        std::cin >> entrada2;

        if(controla_aut->autenticar(entrada1, entrada2)){
            
            cpf.setCPF(entrada1);
            //conferir se esse usuario possui menos de 5 jogos
            //se ja possuir 5 jogos printar que nao pode mais adicionar
            //apos verificacao deve informar codigo do jogo, nome do jogo, codigo do ingresso, data, horario, preco, nome do estadio, cidade, estado
            std::cout << std::endl << "\t" << "Informações do Jogo" << std::endl;
            std::cout << "Codigo do Jogo: " << std::endl;
            //conferir se ja existe um codigo de jogo igual
            getchar();
            getline(std::cin, entrada);
            
            codJ.setCodJogo(entrada);

            std::cout << "Nome do Jogo: " << std::endl;
            getline(std::cin, entrada);
            nome.setNomeJogo(entrada);

            entrada.clear();

            std::cout << "Codigo do Ingresso: " << std::endl;
            getline(std::cin, entrada);
            codI.setCodIngresso(entrada);
            entrada.clear();

            std::cout << "Data: " << std::endl;
            getline(std::cin, entrada);
            data.setData(entrada);
            
            entrada.clear();

            std::cout << "Horario: " << std::endl;
            getline(std::cin, entrada);
            hora.setHorario(entrada); 

            std::cout << "Preco do Ingresso: " << std::endl;
            getline(std::cin, entrada);
            preco.setPreco(entrada);

            std::cout << "Disponibilidade: " << std::endl;
            getline(std::cin, entrada);

            aux = std::stoi(entrada);
            disp.setDisponibilidade(aux);
            
            std::cout << "Cidade: " << std::endl;
            getline(std::cin, entrada);
            cidade.setCidade(entrada);

            std::cout << "Sigla do Estado: " << std::endl;
            getline(std::cin, entrada);
            estado.setEstado(entrada);

            if(controlaserv->cadastrar(nome, codJ, data, hora, cidade, estado, preco, codI, cpf, disp)){
                std::cout << "Jogo cadastrado com sucesso." << std::endl;
            }
        }
    }
    catch(const std::invalid_argument &exp){
        std::cout << exp.what() << std::endl;
        return;
    }
    //manda pra camada de servico
    //apos autenticacao de todas as informacoes informar se o jogo foi cadastrado com sucesso
}

void ControlaJogos::descadastrar(){
    std::string entrada, entrada1, entrada2;
    system("cls");
    CodigoJogo codJ;

    //deve informar CPF e senha para conferir que esse usuario esta cadastrado
    
    try{     

        std::cout << "\t" << "AUTENTICACAO" << std::endl;
        std::cout << "Por favor digite seu CPF: " << std::endl;
        std::cin >> entrada1;
        std::cout << "Por favor digite sua senha: " << std::endl;
        std::cin >> entrada2;

        if(controla_aut->autenticar(entrada1, entrada2)){
            
            //deve informar codigo do jogo que quer descadastrar
            std::cout << std::endl << "Codigo do Jogo: " << std::endl;
            std::cin >> entrada;
            codJ.setCodJogo(entrada);
        }

        if(controlaserv->existejogo(entrada1, entrada)){
            /*conferir se nenhum ingresso foi vendido*/
            if(controlaserv->descadastrar(entrada)){
                std::cout << "Descadastro realizado com sucesso" << std::endl;
            }
        }
    }
    catch(const std::invalid_argument &exp){
        std::cout << exp.what() << std::endl;
        return;
    }
    //manda pra camada de servico
    //deve conferir se esse usuario e realmente dono desse jogo e se algum ingresso ja foi vedido, se estiver tudo certo
    //excluir esse jogo
}

void ControlaJogos::alterarjogo(){
    std::string entrada, entrada1, entrada2;
    int aux;
    system("cls");
    CPF cpf;
    CodigoJogo codJ;
    NomeJogo nome;
    CodigoIngresso codI;
    Data data;
    Horario hora;
    Preco preco;
    Disponibilidade disp;
    Cidade cidade;
    Estado estado;


    try{
        
        std::cout << "\t" << "AUTENTICACAO" << std::endl;
        std::cout << "Por favor digite seu CPF: " << std::endl;
        std::cin >> entrada1;
        cpf.setCPF(entrada1);
        std::cout << "Por favor digite sua senha: " << std::endl;
        std::cin >> entrada2;
        
        if(controla_aut->autenticar(entrada1, entrada2)){

            std::cout << "\t" << "ALTERACAO DE JOGO" << std::endl << std::endl;
            //deve informar codigo do jogo que quer editar
            std::cout << std::endl << "Codigo do Jogo: " << std::endl;
            std::cin >> entrada;
            codJ.setCodJogo(entrada);

            /*inserir metodo que confere se esse jogo realmente pertence a esse usuario*/
            //chamar existe jogo


            if(controlaserv->existejogo(entrada1, entrada)){
                //conferir se nenhum ingresso foi vendido
                std::cout << std::endl << "\t" << "Informações do Jogo" << std::endl;
                std::cout << "Codigo do Jogo: " << std::endl;
                //conferir se ja existe um codigo de jogo igual
                getchar();
                getline(std::cin, entrada);
                codJ.setCodJogo(entrada);

                std::cout << "Nome do Jogo: " << std::endl;
                getline(std::cin, entrada);
                nome.setNomeJogo(entrada);

                entrada.clear();

                std::cout << "Codigo do Ingresso: " << std::endl;
                getline(std::cin, entrada);
                codI.setCodIngresso(entrada);
                entrada.clear();

                std::cout << "Data: " << std::endl;
                getline(std::cin, entrada);
                data.setData(entrada);
                
                entrada.clear();

                std::cout << "Horario: " << std::endl;   
                //std::cin >> entrada;
                getline(std::cin, entrada);
                hora.setHorario(entrada); 

                std::cout << "Preco do Ingresso: " << std::endl;
                getline(std::cin, entrada);
                preco.setPreco(entrada);

                std::cout << "Disponibilidade: " << std::endl;
                getline(std::cin, entrada);

                aux = std::stoi(entrada);
                disp.setDisponibilidade(aux);
                
                std::cout << "Cidade: " << std::endl;
                getline(std::cin, entrada);
                cidade.setCidade(entrada);

                std::cout << "Sigla do Estado: " << std::endl;
                getline(std::cin, entrada);
                estado.setEstado(entrada);

                if(controlaserv->alterarjogo(codJ, nome, codI, data, hora, preco, cidade, estado, cpf, disp)){
                    std::cout << "Alteracoes realizadas com sucesso" << std::endl;
                }
            }

            else{
                std::cout << "ERRO: você não possue permissao para alterar esse jogo" << std::endl;
            }
        }
    }
    catch(const std::invalid_argument &exp){
        std::cout << exp.what() << std::endl;
        return;
    }
  
}

void ControlaJogos::buscar(){
    std::string entrada;
    system("cls");
    Data data;
    Cidade city;
    Estado est;

    try{    
        std::cout << "\t" << "BUSCA DE JOGOS" << std::endl << std::endl;

        //deve informar data, cidade, estado
        std::cout << std::endl << "Data: " << std::endl;
        std::cin >> entrada;
        data.setData(entrada);

        std::cout << "Cidade: " << std::endl;
        std::cin >> entrada;
        city.setCidade(entrada);

        std::cout << "Estado: " << std::endl;
        std::cin >> entrada;
        est.setEstado(entrada);

        if(controlaserv->buscar(data, city, est) == false){
            std::cout << "Ocorreu um erro" << std::endl;
        }
    }
    
    catch(const std::invalid_argument &exp){
        std::cout << exp.what() << std::endl;
        return;
    }
    //procura... (manda pra camada de servico)

    //apos verificar as informacoes lista todos os jogos que satisfazem esses dados 
    //listar nome do jogo, codigo do jogo, horario, preco, nome do estadio, quantidade de ingressos disponiveis
}

void ControlaJogos::obter_dados(){
    std::string entrada1, entrada2;
    CodigoJogo codJ;
    system("cls");
    try{
        std::cout << "\t" << "AUTENTICACAO" << std::endl;
        std::cout << "Por favor digite seu CPF: " << std::endl;
        std::cin >> entrada1;
        std::cout << "Por favor digite sua senha: " << std::endl;
        std::cin >> entrada2;

        if(controla_aut->autenticar(entrada1, entrada2)){
            std::cout << "Por favor digite o codigo do jogo" << std::endl;
            std::cin >> entrada2;
            codJ.setCodJogo(entrada2);
        }

        if(controlaserv->existejogo(entrada1, entrada2)){
            controlaserv->obter_dados(entrada2);
        }
        else{
            std::cout << "ERRO: codigo de jogo invalido" << std::endl;
        }
    }
    
    catch(const std::invalid_argument &exp){
        std::cout << exp.what() << std::endl;
        return;
    }
}

void ControlaVendas::comprar(){
    std::string entrada, entrada1, entrada2;
    int entr;
    system("cls");
    CPF cpf;
    SENHA senha;
    CodigoJogo codJ;
    Disponibilidade disp;
    int flag; /*auxiliar da autenticacao*/

    try{
        
        std::cout << "\t" << "AUTENTICACAO" << std::endl;
        std::cout << "Por favor digite seu CPF: " << std::endl;
        std::cin >> entrada1;
        getchar();
        cpf.setCPF(entrada1);

        std::cout << "Por favor digite sua senha: " << std::endl;
        std::cin >> entrada2;
        senha.setSenha(entrada2);

        std::cout << "\t" << "COMPRA DE INGRESSOS" << std::endl;

        //deve informar CPF e senha para conferir que esse usuario esta cadastrado
        controla_aut->autenticar(entrada1, entrada2);

        /*aqui é um bloco try*/
        //apos verificacao deve informar codigo do jogo e quantidade de ingressos
        std::cout << std::endl << "Codigo do Jogo: " << std::endl;
        std::cin >> entrada;
        codJ.setCodJogo(entrada);
        std::cout << "Quantidade de Ingressos: " << std::endl;
        std::cin >> entr;
        //disp.setDisponibilidade(entr);
        
        if(!controleserv->comprar(codJ, entr, entrada1)){
            std::cout << "Essa compra nao foi efetuada" << std::endl;
        }
    }

    catch(const std::invalid_argument &exp){
        std::cout << exp.what() << std::endl;
        return;
    }    

    
    //manda pra camada de servico
    //confere se a QtdIngressos e menor ou igual a quantidade de ingressos disponiveis e se for
    //lista o codigo dos ingressos e atualiza a quantidade de ingressos
} 