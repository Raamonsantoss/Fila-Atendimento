//
// Created by pacov on 13/06/2022.
//

#ifndef TESTE_FUNCIONALIDADE_H
#define TESTE_FUNCIONALIDADE_H

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <fstream>
#include <time.h>
#include <ctype.h>
#include <cstring>

using namespace std;

struct cliente{
    int horario;
    string senha;
};

struct classe {
    string cod;
    int prioridade;
    int t_lim;
    string desc;
    queue<cliente> fila;
};
void separa(const string & algo, char sep, queue<string> & q);

bool ordena_por_prioridade (const classe & c1, const classe & c2);

void cria_classes_em_ordem (const string & csv_file, list<classe> & filas);

bool ordena_em_codigo(const classe & c1, const classe & c2);

void adiciona_cliente(string & cod, list<classe> & filas_de_atendimento);

void retira_cliente(list<classe> & filas_de_clientes);


#endif //TESTE_FUNCIONALIDADE_H
