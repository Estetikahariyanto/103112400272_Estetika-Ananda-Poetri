#ifndef LISTKENDARAAN_H
#define LISTKENDARAAN_H
#define Nil NULL
#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int tahun;
};

typedef kendaraan infotype;
typedef struct node *address;

struct node {
    infotype info;
    address next;
    address prev;
};

struct linkedlist {
    address first;
    address last;
};

// ===== Deklarasi fungsi =====
bool isEmpty(linkedlist L);
void createList(linkedlist &L);
address alokasi(string nopol, string warna, int tahun);
void dealokasi(address &P);

void insertFirst(linkedlist &L, address P);
void insertLast(linkedlist &L, address P);
void printList(linkedlist L);

void deleteFirst(linkedlist &L, address &P);
void deleteLast(linkedlist &L, address &P);
void deleteAfter(linkedlist &L, address Prec, address &P);
void deleteByNomor(linkedlist &L, string nopol);

#endif