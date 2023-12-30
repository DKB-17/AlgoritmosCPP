#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct no {
    int valor;
    no* proximo;
};

no* empilhar(no *pilha, int num);
no* desempilhar (no *pilha);
void imprimir_pilha(no *pilha);

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
            cout << remover->valor;
            free(remover);
            break;
        case 3:
            imprimir_pilha(pilha);
            break;
        default:
            break;
        }
    }
    while (opcao != 0);
}


no* empilhar(no *pilha, int num) {
    no *novo = (no*) malloc(sizeof(no));

    if (novo) {
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    } else{
        cout << "Erro ao alocar memoria!" << endl;
    }
    return NULL;
}

no* desempilhar(no *pilha) {
    no *remover = NULL;

    if (pilha) {
        remover = pilha;
        pilha = remover->proximo;
    } else {
        cout << "Pilha Vazia" << endl;
    }

    return remover;

}


void imprimir_pilha(no *pilha) {
    no *aux = (no*) malloc(sizeof(no));

    aux = pilha;
    while(aux->proximo) {
        cout << aux->valor << endl;
    }
    
}