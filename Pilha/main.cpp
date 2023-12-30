#include <iostream>
#include "pilha.h"
#include "pilha.c++"

using namespace std;

int main(){

    no *remover, *pilha = NULL;
    
    int opcao, valor;

    do {

        cout << "0 - Sair\n" << "1 - Empilhar\n" << "2 - Desempilhar\n" << "3 - Imprimir Pilha" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite um valor:";
            cin >> valor;
            pilha = empilhar(pilha, valor);
            break;
        case 2:
            remover = desempilhar(pilha);
            pilha = remover->proximo;
            cout << remover->valor << endl;
            free(remover);
            break;
        case 3:
            imprimir_pilha(pilha);
            break;
        default:
            if(opcao != 0){
            cout << "Opcao invalida" << endl;
            }
            break;
        }
    }
    while (opcao != 0);
}
