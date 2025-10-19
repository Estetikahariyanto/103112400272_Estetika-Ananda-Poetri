#include "list.h"

// =====================
// FUNGSI DASAR
// =====================
void createList(linkedlist &L) {
    L.first = Nil;
}

bool isEmpty(linkedlist L) {
    return (L.first == Nil);
}

address alokasi(string nama, string nim, int umur) {
    address P = new elmlist;
    P->info.nama = nama;
    P->info.nim = nim;
    P->info.umur = umur;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// =====================
// INSERT
// =====================
void insertFirst(linkedlist &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(linkedlist &L, address P) {
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedlist &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

// =====================
// DELETE
// =====================
void delFirst(linkedlist &L) {
    if (!isEmpty(L)) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void delLast(linkedlist &L) {
    if (!isEmpty(L)) {
        if (L.first->next == Nil) {
            delFirst(L);
        } else {
            address Q = L.first;
            while (Q->next->next != Nil) {
                Q = Q->next;
            }
            address P = Q->next;
            Q->next = Nil;
            dealokasi(P);
        }
    }
}

void delAfter(linkedlist &L, address Prec, address P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

// =====================
// UTILITAS
// =====================
void printList(linkedlist L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "Nama: " << P->info.nama
                 << " | NIM: " << P->info.nim
                 << " | Umur: " << P->info.umur << endl;
            P = P->next;
        }
    }
}

int nbList(linkedlist L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(linkedlist &L) {
    while (!isEmpty(L)) {
        delFirst(L);
    }
}
