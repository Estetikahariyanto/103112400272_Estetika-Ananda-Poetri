#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

// =====================
// TIPE DATA
// =====================
#define Nil NULL

struct dataMahasiswa {
    string nama;
    string nim;
    int umur;
};

struct elmlist {
    dataMahasiswa info;
    elmlist* next;
};

typedef elmlist* address;

struct linkedlist {
    address first;
};

// =====================
// DEKLARASI FUNGSI
// =====================
void createList(linkedlist &L);
bool isEmpty(linkedlist L);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &P);

void insertFirst(linkedlist &L, address P);
void insertLast(linkedlist &L, address P);
void insertAfter(linkedlist &L, address P, address Prec);

void delFirst(linkedlist &L);
void delLast(linkedlist &L);
void delAfter(linkedlist &L, address Prec, address P);

void printList(linkedlist L);
int nbList(linkedlist L);
void deleteList(linkedlist &L);

#endif
