#include "list.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    createList(List);

    address m1 = alokasi("Andi", "12345", 20);
    address m2 = alokasi("Budi", "67890", 21);
    address m3 = alokasi("Citra", "11223", 19);

    insertFirst(List, m1);      // Andi di awal
    insertLast(List, m2);       // Budi di akhir
    insertAfter(List, m3, m1);  // Citra setelah Andi

    cout << "Isi Linked List Mahasiswa:\n";
    printList(List);

    return 0;
}
