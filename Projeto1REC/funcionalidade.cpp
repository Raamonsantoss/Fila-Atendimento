#include "funcionalidade.h"
#include "menu_usuario.h"

void separa(const string & algo, char sep, queue<string> & q) {

    string aux;
    int i = 0;

    if (! algo.empty()) {
        while (i != string::npos) {
            int pos1 = algo.find_first_not_of(sep,i);
            int pos2 = algo.find(sep,pos1);
            if (pos2 == string::npos) algo.substr(pos1);
            aux = algo.substr(pos1,pos2-pos1);
            q.push(aux);
            i = pos2;
        }

    }
}

//Função responsável por organizar a lista de classe por prioridade
bool ordena_por_prioridade(const classe & c1, const classe & c2){
    return c1.prioridade < c2.prioridade;
}

//Função responsável por ordenar a lista de classe pelo seu respectivo codigo
bool ordena_em_codigo(const classe & c1, const classe & c2) {
    return c1.cod < c2.cod;
}

//Função que cria as classes que estão presentes no arquivo CSV
void cria_classes_em_ordem(const string & csv_file, list<classe> & filas) {
    string linha_arq;
    char sep = ',';
    queue<string> parametros_separados;
    classe classe;

//Abrir o arquivo que é passado como parametro
    ifstream arq(csv_file);
    if(!arq.is_open()) {
        cout << "Arquivo invalido" << endl;
        return;
    }
    //Nesta parte é feito a leitura do arquivo e separado cada informação para que o programa funcione como solicitado.
    while(getline(arq,linha_arq)){
        separa(linha_arq,sep,parametros_separados);
        while(!parametros_separados.empty()){
            classe.cod = parametros_separados.front();
            parametros_separados.pop();
            classe.prioridade = stoi(parametros_separados.front());
            parametros_separados.pop();
            classe.t_lim = stoi(parametros_separados.front());
            parametros_separados.pop();
            classe.desc = parametros_separados.front();
            parametros_separados.pop();
            filas.push_back(classe);
        }
    }
    filas.sort(ordena_por_prioridade); //Organiza a lista baseado na prioridade
}
//Função que adiciona o cliente na fila
void adiciona_cliente (string & cod, list<classe> & filas_de_atendimento) {
    cliente novo_cliente;

    for(auto & x: filas_de_atendimento){
        if(cod == x.cod){
            if(x.fila.size()<9){
                novo_cliente.senha = x.cod + "00" + to_string(x.fila.size()+1);
            }else if (x.fila.size() >= 9 && x.fila.size() < 99){
                novo_cliente.senha = x.cod + "0" + to_string(x.fila.size()+1);
            }else if (x.fila.size()>=99){
                novo_cliente.senha = to_string(x.fila.size()+1);
            }
            // Insere o cliente na fila referente a opção escolhida e mostra sua senha
            x.fila.push(novo_cliente);
            cout << novo_cliente.senha << endl;
            return menu_inicial(filas_de_atendimento);
        }
    }
}
void retira_cliente(list<classe> & filas_de_clientes) {

    filas_de_clientes.sort(
            ordena_por_prioridade); //Ordena novamente a lista de classes  em prioridade, visto que precisou ser ordenada em código no menu do cliente

    auto atual = filas_de_clientes.begin();
    auto fim = filas_de_clientes.end();
    fim--;

//   Nessa parte do código é feita a verificação das filas quando o atendente seleciona "atender novo cliente"
    while (atual != filas_de_clientes.end()) {
        if (atual == fim && fim->fila.empty()) {
            cout << "As filas estão vazias, retornando ao menu principal..." << endl << endl;
            menu_inicial(filas_de_clientes);
            return;

        } else {
            if (!atual->fila.empty()) {
                cout << "Atendendo: " << atual->fila.front().senha << endl << endl;
                atual->fila.pop();
                menu_atendente(filas_de_clientes);
                return;
            } else {
                atual++;
            }
        }
    }
}
