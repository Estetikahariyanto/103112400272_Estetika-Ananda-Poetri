#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

#define Nil nullptr

// ====== Struktur Data ======
struct infotype {
    string nama;
    string nim;
    int umur;
};

struct node {
    infotype isiData;
    node* next;
};

typedef node* address;

struct linkedList {
    address first;
};

// ====== Deklarasi Fungsi & Prosedur ======
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void printList(linkedList List);

#endif