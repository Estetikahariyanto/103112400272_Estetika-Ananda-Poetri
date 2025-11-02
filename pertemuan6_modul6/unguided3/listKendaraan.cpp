#include "listKendaraan.h"

bool isEmpty(linkedlist L) {
    return (L.first == Nil);
}

void createList(linkedlist &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(string nopol, string warna, int tahun) {
    address P = new node;
    P->info.nopol = nopol;
    P->info.warna = warna;
    P->info.tahun = tahun;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(linkedlist &L, address P) {
    if (isEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(linkedlist &L, address P) {
    if (isEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printList(linkedlist L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.tahun << endl;
            cout << endl;
            P = P->next;
        }
    }
}

void deleteFirst(linkedlist &L, address &P) {
    if (isEmpty(L)) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = L.last = Nil;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(linkedlist &L, address &P) {
    if (isEmpty(L)) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.last;
        L.first = L.last = Nil;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(linkedlist &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteByNomor(linkedlist &L, string nopol) {
    address P = L.first;
    address Prec = Nil;

    while (P != Nil && P->info.nopol != nopol) {
        Prec = P;
        P = P->next;
    }

    if (P == Nil) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan." << endl;
    } else {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(L, Prec, P);
        }
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
        dealokasi(P);
    }
}