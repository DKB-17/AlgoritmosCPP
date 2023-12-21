#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct no{
    int valor;
    no *proximo;
};

struct lista {
    no *inicio;
    int tam;
};

void criar_lista(lista *lista);
void inserir_no_inicio(lista *lista, int num);
void inserir_no_fim(lista *lista, int num);
void inserir_no_meio(lista *lista, int num, int ant);
void imprimir_lista(lista lista);

int main(){

    lista lista;
    criar_lista(&lista);

    int opcao, valor, anterior;

    do {

        cout << setw(2) << "0 - Sair\n" << setw(2) << "1 - Inserir no Inicio\n" << setw(2) << "2 - Inserir no Fim\n" << setw(2) << "3 - Inserir no Meio\n" << setw(2) << "4 - Imprimir Lista" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite um valor:";
            cin >> valor;
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            cout << "Digite um valor:";
            cin >> valor;
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            cout << "Digite um valor:";
            cin >> valor;
            cout << "Digite o valor de referencia:";
            cin >> anterior;
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            imprimir_lista(lista);
            break;
        default:
            if (opcao != 0) {
                cout << "Opcao Invalida" << endl;
            }
            break;
        }

    }while (opcao != 0);

    return 0;
}


void inserir_no_inicio(lista *lista, int num){

    no *novo = (no*) malloc(sizeof(no));

    if (novo) {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam ++;
    }else{
        cout << "Erro ao alocar memoria!" << endl;
    }
}


void inserir_no_fim(lista *lista, int num){
    no *aux, *novo = (no*) malloc(sizeof(no));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        // caso o ultimo inserido for o primeiro elemento da lista
        if (lista->inicio == NULL) {
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while(aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        lista->tam ++;
    }
    else{
        cout << "Erro ao alocar memoria!" << endl;
    }
}

void inserir_no_meio(lista *lista, int num, int ant) {
    no *aux, *novo = (no*) malloc(sizeof(no));

    if (novo){
        novo->valor = num;

        if (lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo != NULL){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam ++;
    }
    else{
        cout << "Erro ao alocar memoria!" << endl;
    }
}

void imprimir_lista(lista lista){
    no *aux = lista.inicio;
    if(aux->proximo != NULL){
        cout << "Valor:" << setw(7) << "Tamanho: " << lista.tam << endl;
        while (aux->proximo != NULL){
            cout << aux->valor << endl;
            aux = aux->proximo;
        }
        cout << endl;
    }else{
        cout << "Lista vazia" << endl;
    }
}

void criar_lista(lista* lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}
