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

int main(){

}

void criar_pilha(pilha *pilha){
    pilha->inicio;
    pilha->tamanho = 0;
}