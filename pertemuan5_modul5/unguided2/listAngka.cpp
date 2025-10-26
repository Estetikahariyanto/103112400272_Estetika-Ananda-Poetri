#include "listAngka.h"
#include <iostream>
using namespace std;

// ===== Fungsi dasar =====
void createList(linkedList &L) {
    L.first = Nil;
}

node* alokasi(int x) {
    node* p = new node;
    p->angka = x;
    p->next = Nil;
    return p;
}

void dealokasi(node* p) {
    delete p;
}

void printList(linkedList L) {
    node* p = L.first;
    while (p != Nil) {
        cout << p->angka;
        if (p->next != Nil) cout << " - ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, node* p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, node* p) {
    if (L.first == Nil) {
        L.first = p;
    } else {
        node* q = L.first;
        while (q->next != Nil) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(linkedList &L, node* p, node* prec) {
    if (prec != Nil) {
        p->next = prec->next;
        prec->next = p;
    }
}

void delAfter(linkedList &L, node* &p, node* prec) {
    if (prec != Nil && prec->next != Nil) {
        p = prec->next;
        prec->next = p->next;
        p->next = Nil;
    }
}

// ====== FUNGSI UPDATE (Nomor 1) ======
void updateFirst(linkedList &L) {
    if (L.first != Nil) {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    } else {
        cout << "List kosong, tidak bisa update." << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first == Nil) {
        cout << "List kosong, tidak bisa update." << endl;
        return;
    }

    node* p = L.first;
    while (p->next != Nil) {
        p = p->next;
    }

    cout << "masukkan update data node terakhir : " << endl;
    cout << "Masukkan angka : ";
    cin >> p->angka;
    cout << "Data Berhasil Diupdate!" << endl << endl;
}

void updateAfter(linkedList &L, node* prec) {
    if (prec != Nil && prec->next != Nil) {
        cout << "masukkan update data node setelah node " << prec->angka << " : " << endl;
        cout << "Masukkan angka : ";
        cin >> prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    } else {
        cout << "Node sebelumnya tidak valid / tidak punya penerus." << endl;
    }
}