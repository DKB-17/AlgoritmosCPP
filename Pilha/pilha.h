#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

struct no {
    int valor;
    no* proximo;
};

no* empilhar(no *pilha, int num);
no* desempilhar (no *pilha);
void imprimir_pilha(no *pilha);

#endif