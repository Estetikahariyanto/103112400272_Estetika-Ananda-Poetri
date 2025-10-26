#include "listAngka.h"

//program membuat list kosong
void createList(linkedList &L) {
    L.first = Nil;
}

//mengalokasi node baru
node* alokasi(int x) {
    node *p = new node;
    p->data = x;
    p->next = Nil;
    return p;
}

//menyisipkan node di akhir list
void insertLast(linkedList &L, node *p) {
    if (L.first == Nil) {
        L.first = p;
    } else {
        node *q = L.first;
        while (q->next != Nil) {
            q = q->next;
        }
        q->next = p;
    }
}

//menampilkan isi list
void printList(linkedList L) {
    node *p = L.first;
    while (p != Nil) {
        cout << p->data << " - ";
        p = p->next;
    }
    cout << endl;
}

// ===================================================
// ============== SEARCH FUNCTIONS ===================
// ===================================================

//search oleh data
void SearchByData(linkedList L, int data) {
    node *p = L.first;
    int pos = 1;
    bool found = false;

    while (p != Nil) {
        if (p->data == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << pos << "!" << endl;
            found = true;
            break;
        }
        p = p->next;
        pos++;
    }

    if (!found) {
        cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
    }
    cout << endl;
}

//search oleh address
void SearchByAddress(linkedList L, node *address) {
    node *p = L.first;
    int pos = 1;
    bool found = false;

    while (p != Nil) {
        if (p == address) {
            cout << "Node ditemukan pada posisi ke-" << pos << "!" << endl;
            cout << "Alamat node : " << p << endl;
            found = true;
            break;
        }
        p = p->next;
        pos++;
    }

    if (!found) {
        cout << "Node dengan alamat " << address << " tidak ditemukan dalam list!" << endl;
    }
    cout << endl;
}

//search oleh range
void SearchByRange(linkedList L, int nilaiMin) {
    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    node *p = L.first;
    int pos = 1;
    bool found = false;

    while (p != Nil) {
        if (p->data >= nilaiMin) {
            cout << "Data ditemukan pada posisi ke-" << pos << ", nilai : " << p->data << endl;
            found = true;
        }
        p = p->next;
        pos++;
    }

    if (!found) {
        cout << "Tidak ada data dengan nilai >= " << nilaiMin << endl;
    }
    cout << "-----------------------------------" << endl;
}
