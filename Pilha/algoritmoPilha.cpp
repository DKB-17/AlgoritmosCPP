#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct no {
    int valor;
    no* proximo;
};
struct pilha{
    no* inicio;
    int tamanho;
};

void criar_pilha(pilha *pilha);
void inserir_no_topo(pilha *pilha, int num);

int main(){

    pilha pilha;
    criar_pilha(&pilha);

    int valor, opcao;

    do {

        cout << "0 - Sair\n" << "1 - Inserir no Topo\n" << "2 - Remover no Topo\n" << "3 - Imprimir Pilha" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a ser inserido:";
            cin >> valor;
            inserir_no_topo(&pilha, valor);
            break;
        default:
            break;
        }
    }
    while (opcao != 0)

}

void criar_pilha(pilha *pilha){
    pilha->inicio;
    pilha->tamanho = 0;
}

void inserir_no_topo(pilha *pilha, int num) {
    no *novo = (no*) malloc(sizeof(no));

    if (pilha->inicio == NULL) {
        novo.valor = num;
        novo.proximo = pilha->inicio;
        pilha->inicio = novo;
    }
}