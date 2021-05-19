#include <iostream>
#include <stdexcept>

#include "Testes.h"
#include "controladoras.h"
#include "stubs.h"
#include "armazena.h"


using namespace std;

int main(){
    int op = -1;
    string entrada;

    ControlaUsuario cntr_u;
    ControlaJogos cntr_j;
    ControlaVendas cntr_v;
    Armazenamento arm;

    StubsUsuario stb_u;
    StubsJogos stb_j;
    StubsVendas stb_v;
    StubsAutentica stb_a;


    cntr_u.setSUsuario(&stb_u);
    cntr_j.setSJogos(&stb_j);
    cntr_v.setSVendas(&stb_v);
    cntr_j.setAAutentica(&stb_a);
    cntr_v.setAAutentica(&stb_a);
    
    stb_v.setSArmazenamento(&arm);
    stb_u.setSArmazenamento(&arm);
    stb_j.setSArmazenamento(&arm);
    stb_a.setSArmazenamento(&arm);
    
    try{
        arm.carrega_arquivo();          /*le do arquivo todos os dados contidos e os coloca em listas*/
    }
    catch(const invalid_argument &exp){
        
    }

    while (op != 9){

        cout << endl << "\tMENU" << endl;
        cout << "1 - Cadastrar novo Usuario" << endl;
        cout << "2 - Descadastrar Usuario" << endl; //so pode se descadastrar se nao tiver nenhum jogo pendente
        cout << "3 - Buscar Jogo" << endl;
        cout << "4 - Comprar Ingresso" << endl; //a pessoa deve ser autenticada
        cout << "5 - Cadastrar Jogo" << endl; //a pessoa deve ser autenticada
        cout << "6 - Editar Jogo" << endl; //so o dono do jogo pode fazer e so pode ser feito se nenhum ingresso tiver sido vendido
        cout << "7 - Descadastrar Jogo" << endl; //so o dono do jogo pode fazer e so pode ser feito se nenhum ingresso tiver sido vendido
        cout << "8 - Solicitar informacoes de um Jogo" << endl; //so o dono do jogo pode fazer
        cout << "9 - Sair do sistema" << endl;

        cin >> op;
        getchar();

        system("cls");

        if(op == 1){
            cntr_u.cadastrar();
        }

        else if(op == 2){
            cntr_u.descadastrar();
        }

        else if(op == 3){
            cntr_j.buscar();
        }

        else if(op == 4){
            cntr_v.comprar();    
        }

        else if(op == 5){
            cntr_j.cadastrar();   
        }

        else if(op == 6){
            cntr_j.alterarjogo();    
        }

        else if(op == 7){
            cntr_j.descadastrar();
        }

        else if(op == 8){
            cntr_j.obter_dados();
        }
    
    }

    arm.grava_arquivo();

    return 0;
}
