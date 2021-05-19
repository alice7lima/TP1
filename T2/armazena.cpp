#include "armazena.h"
#include<stdexcept>
#include <iostream>

bool Armazenamento::armazena_usuario(Usuario usuario){
    
    cadastros.push_back(usuario);
}

bool Armazenamento::confere_cpf(CPF cpf){
    for(itU = cadastros.begin(); itU != cadastros.end(); itU++){
        if(itU->getCPF().getCPF() == cpf.getCPF()){
            return 0;
        }
    }
    return 1;
}

bool Armazenamento::armazena_jogo(const Jogo &jogo){

    jogos.push_back(jogo);
    
}

bool Armazenamento::armazena_ingresso(const CodigoJogo codJ, int quantidade, std::string cpf){
    Ingresso ingresso;
    Disponibilidade disp;
    CPF cpf2;

    ingresso.setCodJogo(codJ);

    disp.setDisponibilidade(quantidade);
    ingresso.setDisponibilidade(disp);

    cpf2.setCPF(cpf);
    ingresso.setCPF(cpf2);

    ingressos.push_back(ingresso);

}

bool Armazenamento::confere_cadastrado(std::string cpf){
    for(itJ = jogos.begin(); itJ != jogos.end(); itJ++){
        if(itJ->getCPF().getCPF() == cpf){
            return 0;
        }
    }
    return 1;
}

bool Armazenamento::remove_usuario(std::string cpf, std::string senha){
    for(itU = cadastros.begin(); itU != cadastros.end(); itU++){
        if(itU->getCPF().getCPF() == cpf){
            if(itU->getSENHA().getSenha() == senha){
                itU = cadastros.erase(itU);
                return 1;
            }
        }
    }
    return 0;
}

bool Armazenamento::existe(std::string cpf, std::string codj){
    for(itJ = jogos.begin(); itJ != jogos.end(); itJ++){
        if(itJ->getCPF().getCPF() == cpf){
            if(itJ->getCodJogo().getCodJogo() == codj){
                return 1;
            }
        }
    }
    return 0;
}

bool Armazenamento::confere_vendido(std::string codj){
    for(itI = ingressos.begin(); itI != ingressos.end(); itI++){
        if(itJ->getCodJogo().getCodJogo() == codj){
            return 0;
        }
    }
    return 1;
}

bool Armazenamento::remove_jogo(std::string codj){
    for(itJ = jogos.begin(); itJ != jogos.end(); itJ++){
        if(itJ->getCodJogo().getCodJogo() == codj){
            itJ = jogos.erase(itJ);
            return 1;
        }
    }
    return 0;
}

void Armazenamento::busca_jogo(Data data, Cidade cidade, Estado est){
    int i=0;
    for(itJ = jogos.begin(); itJ != jogos.end(); itJ++){
        if(itJ->getData().getData() == data.getData()){
            if(itJ->getEstado().getEstado() == est.getEstado()){
                if(itJ->getCidade().getCidade() == cidade.getCidade()){
                    if(i==0){
                        std::cout << "Os jogos com essas informacoes sao: " << std::endl;
                        std::cout << std::endl;
                    }
                    std::cout << "Codigo do Jogo: " << itJ->getCodJogo().getCodJogo() << std::endl;
                    std::cout << "Nome do Jogo: " << itJ->getNomeJogo().getNomeJogo() << std::endl;
                    std::cout << "Data: " << itJ->getData().getData() << std::endl;
                    std::cout << "Horario: " << itJ->getHorario().getHorario() << std::endl;
                    std::cout << "Ingressos disponiveis: " << itJ->getDisponibilidade().getDisponibilidade() << std::endl;
                    std::cout << "Preco dos ingressos: " << itJ->getPreco().getPreco() << std::endl;
                    std::cout << "Cidade: " << itJ->getCidade().getCidade() << std::endl;
                    std::cout << "Estado: " <<itJ->getEstado().getEstado() << std::endl;
                    std::cout << std::endl;
                    i=1;
                }
            }
        }
    }
    if(i==0){
        std::cout << "Nao ha nenhum jogo com essas informacoes" << std::endl;
    }
}

bool Armazenamento::autentica_usuario(std::string cpf, std::string senha){
    int achou=0;

    for(itU = cadastros.begin(); itU != cadastros.end() && !achou; itU++){
        if(itU->getCPF().getCPF() == cpf){
            if(itU->getSENHA().getSenha() == senha){
                achou = 1;
            }
        } 
    }
    if(achou){
        return true;
    }
    else{
        throw std::invalid_argument("ERRO: dados nao autenticados");
    }
    return false;
}

bool Armazenamento::busca_infos(std::string codJ){
    int i=0, achou=0;

    for(itI = ingressos.begin(); itI != ingressos.end(); itI++){
       if(itI->getCodJogo().getCodJogo() == codJ){
           std::cout << "CPF do comprador " << i << ": " << itI->getCPF().getCPF() << std::endl;
           std::cout << "Comprou " << itI->getDisponibilidade().getDisponibilidade() << " ingressos" << std::endl;
           i++;
           achou = 1;
       }
    }

    for(itJ = jogos.begin(); itJ != jogos.end(); itJ++){
        if(itJ->getCodJogo().getCodJogo() == codJ){
            std::cout << "Total de ingressos disponiveis: " << itJ->getDisponibilidade().getDisponibilidade() << std::endl;
       }
    }

    if(achou){
        return 1;
    }
    
    return 0;
}

bool Armazenamento::compra_ingresso(CodigoJogo codj, int quantidade){
    Disponibilidade disp;
    int novaDisp=0;
    
    
    std::cout << "COMPRA INGRESSOS" << std::endl;

    for(itJ = jogos.begin(); itJ != jogos.end(); itJ++){
        if(itJ->getCodJogo().getCodJogo() == codj.getCodJogo()){
            if(quantidade > itJ->getDisponibilidade().getDisponibilidade()){
                return 0;
            }
            else{
                
                novaDisp = itJ->getDisponibilidade().getDisponibilidade();
                novaDisp = novaDisp - quantidade;

                //muda a disponibilidade
                disp.setDisponibilidade(novaDisp);
                itJ->setDisponibilidade(disp);

                std::cout << "Codigo do seu ingresso: " << itJ->getCodIngresso().getCodIngresso() << std::endl;
                std::cout << std::endl;

                return 1;
            }
        }
    }
    return 0;
}

bool Armazenamento::carrega_arquivo(){


    std::string linha;
    int i=0;

    Usuario usuario;
    CPF cpf;
    SENHA senha;
    CodigoSeguranca cods;
    NumeroCartao numc;
    DataValidade dval;
    
    
    Jogo jogo;
    CodigoJogo codj;
    NomeJogo nomej;
    CodigoIngresso codi;
    Data dt;
    Horario hr;
    Preco pr;
    Disponibilidade dsp;
    Cidade city;
    Estado est;
    int aux;

    Ingresso ingresso;

    std::ifstream file_pegar_Cadastros("TextC.txt");
    
    while(getline(file_pegar_Cadastros, linha)){
        if(i==0){
            cpf.setCPF(linha);
        }
        else if(i==1){
            senha.setSenha(linha);
        }
        else if(i==2){
            numc.setNumCartao(linha);
        }
        else if(i==3){
            cods.setCodSeguranca(linha);
        }
        else if(i==4){
            dval.setDataValidade(linha);

            usuario.setCPF(cpf);
            usuario.setSENHA(senha);
            usuario.setNumCartao(numc);
            usuario.setCodSeguranca(cods);
            usuario.setDataValidade(dval);
            
            cadastros.push_back(usuario);

            //zera o i porque comeca outro cadastro
            i=-1;
        }
        i++;
    }
    file_pegar_Cadastros.close();
    i=0;


    std::ifstream file_pegar_Jogos("TextJ.txt");


    while(getline(file_pegar_Jogos, linha)){
        if(i==0){
            cpf.setCPF(linha);
        }
        else if(i==1){
            codj.setCodJogo(linha);
        }
        else if(i==2){
            nomej.setNomeJogo(linha);
        }
        else if(i==3){
            codi.setCodIngresso(linha);
        }
        else if(i==4){
            dt.setData(linha);
        }
        else if(i==5){
            hr.setHorario(linha);
        }
        else if(i==6){
            pr.setPreco(linha);
        }
        else if(i==7){
            aux = std::stoi(linha);
            dsp.setDisponibilidade(aux);
        }
        else if(i==8){
            city.setCidade(linha);
        }
        else if(i==9){
            est.setEstado(linha);

            jogo.setCPF(cpf);
            jogo.setCodJogo(codj);
            jogo.setNomeJogo(nomej);
            jogo.setCodIngresso(codi);
            jogo.setData(dt);
            jogo.setHorario(hr);
            jogo.setPreco(pr);
            jogo.setDisponibilidade(dsp);
            jogo.setCidade(city);
            jogo.setEstado(est);

            jogos.push_back(jogo);
            
            //zera o i porque comeca outro jogo
            i=-1;
        }
        i++;
    }
    file_pegar_Jogos.close();
    i=0;

    std::ifstream file_pegar_Ingressos("TextI.txt");


    while(getline(file_pegar_Ingressos, linha)){
        if(i==0){
            codj.setCodJogo(linha);
        }
        else if(i==1){
            cpf.setCPF(linha);
        }
        else if(i==2){
            aux = std::stoi(linha);
            dsp.setDisponibilidade(aux);

            ingresso.setCodJogo(codj);
            ingresso.setCPF(cpf);
            ingresso.setDisponibilidade(dsp);

            ingressos.push_back(ingresso);

            i=-1;
        }
        i++;
    }
    file_pegar_Ingressos.close();
}

bool Armazenamento::grava_arquivo(){
    
    std::ofstream fileCadastros; 

    fileCadastros.open("TextC.txt"); //abre arquivo de cadastros

    for(itU = cadastros.begin(); itU != cadastros.end(); itU++){   //percorre a lista para gravar cada nodo no arquivo texto
        fileCadastros << itU->getCPF().getCPF() << std::endl;
        fileCadastros << itU->getSENHA().getSenha() << std::endl;
        fileCadastros << itU->getNumCartao().getNumCartao() << std::endl;
        fileCadastros << itU->getCodSeguranca().getCodSeguranca() << std::endl;
        fileCadastros << itU->getDataValidade().getDataValidade() << std::endl;
    }
    fileCadastros.close(); //fecha arquivo

    std::ofstream fileJogos;
    fileJogos.open("TextJ.txt"); //abre arquivo de jogos

    for(itJ = jogos.begin(); itJ != jogos.end(); itJ++){
        fileJogos << itJ->getCPF().getCPF() << std::endl;
        fileJogos << itJ->getCodJogo().getCodJogo() << std::endl;
        fileJogos << itJ->getNomeJogo().getNomeJogo() << std::endl;
        fileJogos << itJ->getCodIngresso().getCodIngresso() << std::endl;
        fileJogos << itJ->getData().getData() << std::endl;
        fileJogos << itJ->getHorario().getHorario() << std::endl;
        fileJogos << itJ->getPreco().getPreco() << std::endl;
        fileJogos << itJ->getDisponibilidade().getDisponibilidade() << std::endl;
        fileJogos << itJ->getCidade().getCidade() << std::endl;
        fileJogos << itJ->getEstado().getEstado() << std::endl;
    }
    fileJogos.close(); //fecha arquivo

    std::ofstream fileIngressos;
    fileIngressos.open("TextI.txt");

    for(itI = ingressos.begin(); itI != ingressos.end(); itI++){
        fileIngressos << itI->getCodJogo().getCodJogo() << std::endl;
        fileIngressos << itI->getCPF().getCPF() << std::endl;
        fileIngressos << itI->getDisponibilidade().getDisponibilidade() << std::endl;
    }
    fileIngressos.close();
    

    //limpa as listas
    cadastros.clear();
    jogos.clear();
    ingressos.clear();

}