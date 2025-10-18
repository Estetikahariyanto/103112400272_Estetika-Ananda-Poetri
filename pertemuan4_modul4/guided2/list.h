//Header guard di gunakan untuk mencegah file header yang sama
//di-include lebih dari sekalai dalam satu program
#ifndef LIST_H
#define LIST_H
#define LIST nullptr

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa 
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Menebrikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke strct node

struct node{ //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & pprosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
// void insertFirst(linkedlist &List, address nodeBaru);
// void insertAfter(linkedlist &List, address nodeBaru, address Prev);
// void insertLast(linkedlist &List, address nodeBaru);

#endif