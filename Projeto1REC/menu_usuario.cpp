#include "menu_usuario.h"
#include "funcionalidade.h"

//Função responsável pela criação menu do cliente

void menu_cliente(list<classe> & filas_clientes) {
    string cod;

    cout << "Digite a opcao desejada: " << endl;
    cout << endl;

    filas_clientes.sort(ordena_em_codigo); //Ordena as opções apresentadas ao cliente

    for(auto &x : filas_clientes) {
        cout << x.cod << ": " << x.desc << endl; // Apresenta na tela as opções com suas respectivas descrições
    }
    cout << endl;
    cout << "Digite SAIR caso queira sair do menu do cliente" << endl;

//No seguinte loop é feito a leitura do que o cliente digitar
    while(true){
        cin >> cod;
        if(cod == "SAIR"){
            menu_inicial(filas_clientes);
            break;
        }
        adiciona_cliente(cod, filas_clientes);
        cout << endl;
    }
}

// Função responsável por criar a interface do atendente
void menu_atendente(list<classe> & filas_clientes) {
    string op;

    cout << "Escolha a opcao desejada: " << endl;
    cout << "1: Atender cliente" << endl;
    cout << "2: Sair do menu do atendente" << endl;

    cin >> op;
    cout << endl;
//Loop responsável por executar o que o cliente digitar

    if(op == "1") {
        retira_cliente(filas_clientes);
        return;
    } else if (op == "2") {
        menu_inicial(filas_clientes);
        return;
    } else {
        cout << "Opcao digitada não corresponde a nenhuma das opcoes acima" << endl;
        cout << endl;
        menu_atendente(filas_clientes);
        return;
    }
}

// Função responsável por criar o menu inicial
void menu_inicial(list<classe> & filas_clientes){
    string opcoes;

    cout << "Atendente ou cliente?" << endl << endl;
    cout << "1: Atendente" << endl;
    cout << "2: Cliente" << endl;
    cout << "3: Sair" << endl;

    cin >> opcoes;

//Loop responsável por executar a opção escolhida pelo Atendente/cliente
    if(opcoes == "1") {
        menu_atendente(filas_clientes);
        return;
    } else if (opcoes == "2") {
        menu_cliente(filas_clientes);
        return;
    } else if(opcoes == "3") {
        cout << "Sistema encerrado" << endl;
        return;
    } else {
        cout << "Opcao digitada nao corresponde as opcoes acima" << endl;
        menu_inicial(filas_clientes);
    }
}