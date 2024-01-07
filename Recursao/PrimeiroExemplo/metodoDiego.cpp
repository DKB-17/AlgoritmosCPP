#include <iostream>

using namespace std;

int menor(int vet[], int tam);

int main(){
    
    int tamanho = 10;

    int vetA[tamanho] = {0, 57, 13, 42, 135, 21, 3, 82, 59, 1};

    cout << menor(vetA, tamanho);


    return 0;
}

int menor(int vetA[], int tam) {
    if(tam < 1) {
        return vetA[tam];
    }else {
        int aux = menor(vetA,(tam - 1));
        if(vetA[tam] < aux) {
            return vetA[tam];
        }
        return aux;
    }  


}