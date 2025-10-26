#include "listAngka.h"
#include <iostream>
using namespace std;

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
        cout << p->angka << " ";
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