#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int dataAngka;

struct node {
    dataAngka angka;
    node* next;
};

struct linkedList {
    node* first;
};

// ===== Deklarasi Fungsi dan Prosedur =====
void createList(linkedList &L);
node* alokasi(int x);
void dealokasi(node* p);
void printList(linkedList L);
void insertFirst(linkedList &L, node* p);
void insertLast(linkedList &L, node* p);
void insertAfter(linkedList &L, node* p, node* prec);
void delAfter(linkedList &L, node* &p, node* prec);

#endif