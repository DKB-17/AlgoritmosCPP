#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct no{
    int valor;
    no *proximo;
};

void inserir_no_inicio(no **lista, int num);
void inserir_no_fim(no **lista, int num);
void inserir_no_meio(no **lista, int num, int ant);
void imprimir_lista(no *no);

int main(){

    no *lista = NULL;
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


void inserir_no_inicio(no **lista, int num){

    no *novo = (no*) malloc(sizeof(no));

    if (novo) {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        cout << "Erro ao alocar memoria!" << endl;
    }
}


void inserir_no_fim(no **lista, int num){
    no *aux, *novo = (no*) malloc(sizeof(no));

    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        // caso o ultimo inserido for o primeiro elemento da lista
        if (*lista == NULL) {
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else{
        cout << "Erro ao alocar memoria!" << endl;
    }
}

void inserir_no_meio(no **lista, int num, int ant) {
    no *aux, *novo = (no*) malloc(sizeof(no));

    if (novo){
        novo->valor = num;
        if (*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }
            if(aux->valor == ant){
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }else{
                cout << ant << " não pertence a lista" << endl;
            }
        }
    }
    else{
        cout << "Erro ao alocar memoria!" << endl;
    }
}

void imprimir_lista(no *no){
    if(no){
        cout << "Valor:" << endl;
        while (no->proximo != NULL){
            cout << no->valor << endl;
            no = no->proximo;
        }
        cout << endl;
    }else{
        cout << "Lista vazia" << endl;
    }
}
