#include "pilha.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

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
    } else {
        cout << "Pilha Vazia" << endl;
    }

    return remover;

}


void imprimir_pilha(no *pilha) {

    cout << "PILHA" << endl;
    while(pilha) {
        cout << pilha->valor << endl;
        pilha = pilha->proximo;
    }
    
}