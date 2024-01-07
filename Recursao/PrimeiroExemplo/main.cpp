#include <iostream>

using namespace std;

int menor(int v[], int tam, int indice);


int main(){

    int vet[] = {0, 57, 13, 42, 135, 21, 3, 82, 59, 1};

    cout << menor(vet, 9, 0);



    return 0;
}

int menor(int v[], int tam, int indice){   
    
    if(tam == 0){
        return v[indice];
    }else{
        if(v[tam] < v[indice]) {
            return menor(v, tam - 1, tam);
        }else{
            return menor(v, tam - 1, indice);
        }
    }

}