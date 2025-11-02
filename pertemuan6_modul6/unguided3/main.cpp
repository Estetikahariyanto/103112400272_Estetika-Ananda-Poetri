#include "listKendaraan.h"

int main() {
    linkedlist L;
    createList(L);

    // Tambah data kendaraan sesuai contoh
    insertFirst(L, alokasi("D001", "hitam", 90));
    insertFirst(L, alokasi("D003", "biru", 95));
    insertFirst(L, alokasi("D004", "kuning", 90));

    string hapusNopol;

    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    deleteByNomor(L, hapusNopol);
    cout << endl;

    cout << "DATA LIST 1" << endl;
    printList(L);

    return 0;
}