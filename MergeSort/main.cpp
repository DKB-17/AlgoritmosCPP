#include <iostream>

using namespace std;

void merge_sort(int vetor[], int ini, int fim);
void imprimir_vetor(int vetor[], int tamanho);
void merge(int vetor[], int ini, int meio, int fim);

int main(){

    int tamanho = 10;
    int vetorA[tamanho] = {9,1,3,7,2,6,4,8,5,0};

    imprimir_vetor(vetorA, tamanho);

    cout << "--Ordenando--" << endl;
    merge_sort(vetorA, 0, tamanho);

    imprimir_vetor(vetorA, tamanho);


    return 0;
}

void merge_sort(int vetor[], int ini, int fim) {
    if(ini < (fim - 1)) {
        int meio = (ini+fim) / 2;
        merge_sort(vetor, ini, meio);
        merge_sort(vetor, meio, fim);
        merge(vetor, ini, meio, fim);
    }

}

void merge(int vetor[], int ini, int meio, int fim){
    int i,j,k,*w;

    w = (int*) malloc((fim-ini) * sizeof(int));
    i = ini;
    j = meio;
    k = 0;
    
    while (i < meio && j < fim) {
        if (vetor[i] <= vetor[j]) {
            w[k++] = vetor[i++];
        }else{
            w[k++] = vetor[j++];
        }
    }
    while (i < meio) {
        w[k++] = vetor[i++];
    }
    while (j < fim) {
        w[k++] = vetor[j++];
    }
    for (i = ini; i < fim; i++) {
        vetor[i] = w[i - ini];
    }
    free(w);
}

void imprimir_vetor(int vetor[], int tamanho) {

    cout << "Vetor : [ " ;
    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i];
        if (i < (tamanho - 1)) {
            cout << " ,";
        }
    }
    cout << " ]" << endl ;

}