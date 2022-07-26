#include "menu_usuario.h"
#include "funcionalidade.h"

// Função responsável por chamar as demais funções.
int main (int argc, char * argv[]) {
    list<classe> lista_com_classes;
    cria_classes_em_ordem(argv[1], lista_com_classes);
    cout << endl;

    if(!lista_com_classes.empty()){
        menu_inicial(lista_com_classes);
    }
}
