#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

#define Nil NULL

struct node {
    int info;
    node *next;
};

struct linkedList {
    node *first;
};

void createList(linkedList &L);
node* alokasi(int x);
void insertLast(linkedList &L, node* P);
void showAll(linkedList L);
void operasiAritmatika(linkedList L);

#endif