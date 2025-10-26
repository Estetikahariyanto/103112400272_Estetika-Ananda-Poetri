#include <iostream>
#include "listAngka.h"
using namespace std;

int main() {
    linkedList L;
    createList(L);

    // Alokasi node
    node *nodeA = alokasi(50);
    node *nodeB = alokasi(20);
    node *nodeC = alokasi(25);
    node *nodeD = alokasi(29);
    node *nodeE = alokasi(45);

    // Masukkan ke list
    insertLast(L, nodeA);
    insertLast(L, nodeB);
    insertLast(L, nodeC);
    insertLast(L, nodeD);
    insertLast(L, nodeE);

    printList(L);
    cout << endl;

    // Mencari data nilai 20
    SearchByData(L, 20);

    // Mencari data nilai 55
    SearchByData(L, 55);

    // Mencari data alamat nodeB
    SearchByAddress(L, nodeB);

    // Mencari data alamat nodeA
    SearchByAddress(L, nodeA);

    // Mencari data dengan nilai minimal 40
    SearchByRange(L, 40);

    return 0;
}
