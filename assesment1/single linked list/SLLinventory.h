#ifndef SLLinventory_h
#define SLLinventory_h

#include <iostream>
using namespace std;

#define Nil NULL

typedef int string;

struct node {
    product;
    node* addrress;
};

struct linkedList {
    node* first;

};

// ===== Deklarasi Fungsi dan Prosedur =====
void createList(linkedList &L);
boolean isEmpty(linkedList &L);
void createList PrintList(linkedList &L);
void node* alokasi(int p &Product);
void dealokasi(node* address);
void insertFirst(linkedList &L, node* p);
void insertLast(linkedList &L, node* p);
void insertAfter(linkedList &L, int Q, node* p, node* prec);
void delFirst(linkedList &L, node* &p, node* prec);
void delLast(linkedList &L, node* &p, node* prec);
void delAfter(linkedList &L, int Q ->address);

updateAtPosition(linkedList &L, int string);
viewlist(linkedList &L)(name:string, SKU:string, Jumlah:int, HargaSatuan:float, (1-DiskonPersen 100%))
searchByFinalPriceRange(linkedList &L, minprice &float, maxPrice &float)

#endif