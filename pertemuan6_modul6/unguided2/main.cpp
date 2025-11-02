#include <iostream>
#include <string>
using namespace std;

#define Nil NULL
struct infotype {
    string nopol;
    string warna;
    int tahun;
};

typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

bool isEmpty(List L) {
    return (L.first == Nil);
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;  
        }
        P = P->next;
    }
    return Nil; 
}

void tampilkanData(address P) {
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahun << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

int main() {
    List L;
    createList(L);
    infotype x;
    x = {"D001", "hitam", 90};
    insertLast(L, alokasi(x));

    x = {"B202", "merah", 95};
    insertLast(L, alokasi(x));

    x = {"F303", "biru", 88};
    insertLast(L, alokasi(x));

    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;

    address hasil = findElm(L, cari);

    cout << endl;
    tampilkanData(hasil);

    return 0;
}