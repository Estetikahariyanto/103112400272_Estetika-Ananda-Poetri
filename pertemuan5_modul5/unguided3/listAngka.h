#ifndef LISTANGKA_H_INCLUDED
#define LISTANGKA_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

struct node {
    int data;
    node *next;
};

struct linkedList {
    node *first;
};

void createList(linkedList &L);
node* alokasi(int x);
void insertLast(linkedList &L, node *p);
void printList(linkedList L);

// prosedur pencarian
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, node *address);
void SearchByRange(linkedList L, int nilaiMin);

#endif