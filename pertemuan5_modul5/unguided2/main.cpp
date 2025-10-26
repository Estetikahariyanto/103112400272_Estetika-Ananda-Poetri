#include <iostream>
#include "listAngka.h"
using namespace std;

int main() {
    linkedList L;
    createList(L);

    //membuat node
    node *nodeA, *nodeB, *nodeC, *nodeD, *nodeE, *nodeF;
    nodeA = alokasi(8);
    nodeB = alokasi(25);
    nodeC = alokasi(18);
    nodeD = alokasi(33);
    nodeE = alokasi(40);
    nodeF = alokasi(29); // akan dipakai untuk insert tambahan (opsional)

    // === SUSUN LIST SESUAI CONTOH ===
    insertFirst(L, nodeD);  // 33
    insertFirst(L, nodeA);  // 8 - 33
    insertFirst(L, nodeB);  // 25 - 8 - 33
    insertFirst(L, nodeC);  // 18 - 25 - 8 - 33
    insertFirst(L, nodeE);  // 40 - 18 - 25 - 8 - 33

    cout << "Isi list awal :" << endl;
    printList(L);
    cout << endl;

    // === PROSES UPDATE SESUAI OUTPUT CONTOH ===
    updateFirst(L);          // ubah data pertama (40 -> 50)
    updateAfter(L, nodeB);   // ubah data setelah node 25 (8 -> 29)
    updateLast(L);           // ubah data terakhir (33 -> 45)
    updateAfter(L, nodeE);   // ubah data setelah node 50 (18 -> 20)

    // === CETAK HASIL AKHIR ===
    printList(L);

    return 0;
}