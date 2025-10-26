#include <iostream>
#include "listAngka.h"  
int main() {
    linkedList L;
    createList(L);

    //membuat node
    node *nodeA, *nodeB, *nodeC, *nodeD, *nodeE, *nodeF;
    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    // === Proses Insert ===
    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    // === Hapus node setelah nodeC ===
    node* delNode;
    delAfter(L, delNode, nodeC);
    dealokasi(delNode);

    cout << "Isi list sebelum update: ";
    printList(L); // ini menampilkan list awal

    // === Update data (Nomor 1) ===
    nodeF->angka = 50;   // 40 → 50
    nodeA->angka = 29;   // 8 → 29
    nodeE->angka = 45;   // 33 → 45
    nodeC->angka = 20;   // 18 → 20

    cout << "Isi list setelah update: ";
    printList(L); //ini menampilkan hasil setelah update

    return 0;
}
