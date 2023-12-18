#include <iostream>

using namespace std;

struct no{
    int valor;
    no *proximo;
};

void inserir_no_inicio(no **lista, int num);
void inserir_no_fim(no **lista, int num);
void inserir_no_meio(no **lista, int num, int ant);
void imprimir_lista(no **lista);

int main(){



    return 0;
}


void inserir_no_inicio(no **lista, int num){
    no *novo = malloc(sizeof(no));

    if (novo) {
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        cout << "Erro ao alocar memoria!" << endl;
    }
}


void inserir_no_fim(no **lista, int num){
    no *aux, *novo = malloc(sizeof(no));

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
    no *aux, *novo = malloc(sizeof(no));

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
        while (no->proximo){
            cout << no->valor << endl;
            no = no->proximo;
        }
        cout << endl;
    }else{
        cout << "Lista vazia" << endl;
    }
}
