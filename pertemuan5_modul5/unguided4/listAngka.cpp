#include "listAngka.h"


void createList(linkedList &L) {
    L.first = Nil;
}


node* alokasi(int x) {
    node* P = new node;
    P->info = x;
    P->next = Nil;
    return P;
}


void insertLast(linkedList &L, node* P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        node* Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}


void showAll(linkedList L) {
    node* P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}


void operasiAritmatika(linkedList L) {
    if (L.first == Nil) {
        cout << "List kosong!" << endl;
        return;
    }

    node *P = L.first;
    int totalTambah = 0;
    int totalKurang = P->info;   
    long long totalKali = 1;    


    while (P != Nil) {
        totalTambah += P->info;
        totalKali *= P->info;
        P = P->next;
    }


    P = L.first->next;
    while (P != Nil) {
        totalKurang -= P->info;
        P = P->next;
    }

    cout << "Total penjumlahan : " << totalTambah << endl;
    cout << "Total pengurangan : " << totalKurang << endl;
    cout << "Total perkalian   : " << totalKali << endl;
}