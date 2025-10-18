#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5, Pdel;

    CreateList(L);

    // Membuat linked list sesuai soal
    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    cout << "List awal: ";
    printInfo(L);

    // Hapus 9 (deleteFirst)
    deleteFirst(L, Pdel);
    dealokasi(Pdel);

    // Hapus 2 (deleteLast)
    deleteLast(L, Pdel);
    dealokasi(Pdel);

    // Hapus 8 (deleteAfter)
    deleteAfter(L, L.first, Pdel);
    dealokasi(Pdel);

    cout << "Setelah penghapusan: ";
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // Hapus seluruh list
    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}