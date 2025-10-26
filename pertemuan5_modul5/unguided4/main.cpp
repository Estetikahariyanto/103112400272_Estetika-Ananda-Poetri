#include <iostream>
#include "listAngka.h"
using namespace std;

int main() {
    linkedList L;
    createList(L);

    //membuat node dan mengisi data
    node *A, *B, *C, *D, *E, *F;
    A = alokasi(8);
    B = alokasi(13);
    C = alokasi(25);
    D = alokasi(20);
    E = alokasi(33);
    F = alokasi(70);

    //memasukkan ke dalam list
    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);
    insertLast(L, D);
    insertLast(L, E);
    insertLast(L, F);

    //menampilkan isi list
    cout << "Isi list: ";
    showAll(L);

    //melakukan operasi aritmetika
    operasiAritmatika(L);

    return 0;
}