#include <iostream>
#include <stdio.h>

using namespace std;

void move_disco(int d, char ori, char dest, char aux);

int main(){

    int discos = 3;
    move_disco(discos, 'A', 'B', 'C');

    return 0;
}

void move_disco(int d, char ori, char dest, char aux){
    if (d == 1) {
        cout << "Move disco: " << d << " de " << ori << " para " << dest << endl;
    }else {
        move_disco(d-1, ori, aux, dest);
        cout << "Move disco: " << d << " de " << ori << " para " << dest << endl;
        move_disco(d-1, aux, dest, ori);
    }
}