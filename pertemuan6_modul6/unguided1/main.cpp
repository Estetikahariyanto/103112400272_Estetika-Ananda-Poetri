#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    char lanjut = 'y';

    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\nmasukkan nomor polisi: ";
        cin >> x.nopol;

        if (isDuplicate(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n";
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnBuat;

            address P = alokasi(x);
            insertLast(L, P);
        }

        cout << "\nTambah data lagi? (y/n): ";
        cin >> lanjut;
    }

    printInfo(L);

    return 0;
}