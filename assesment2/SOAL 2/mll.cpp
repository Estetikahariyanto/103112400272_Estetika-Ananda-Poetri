#include "mll.h"

void createListParent(listParent &LP) {
    LP.first = LP.last = NULL;
}

void createListChild(listChild &LC) {
    LC.first = LC.last = NULL;
}

parentNode* alokasiNodeParent(string id, string nama) {
    parentNode *P = new parentNode;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = P->prev = NULL;
    createListChild(P->child);
    return P;
}

childNode* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    childNode *C = new childNode;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = C->prev = NULL;
    return C;
}

void dealokasiNodeParent(parentNode *&P) {
    delete P;
    P = NULL;
}

void dealokasiNodeChild(childNode *&C) {
    delete C;
    C = NULL;
}

void insertFirstParent(listParent &LP, parentNode *P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(listChild &LC, childNode *C) {
    if (LC.first == NULL) {
        LC.first = LC.last = C;
    } else {
        LC.last->next = C;
        C->prev = LC.last;
        LC.last = C;
    }
}

void hapusListChild(listChild &LC) {
    childNode *C = LC.first;
    while (C != NULL) {
        childNode *temp = C;
        C = C->next;
        dealokasiNodeChild(temp);
    }
    LC.first = LC.last = NULL;
}

void deleteAfterParent(listParent &LP, parentNode *prec) {
    if (prec != NULL && prec->next != NULL) {
        parentNode *P = prec->next;
        hapusListChild(P->child);
        prec->next = P->next;
        if (P->next != NULL)
            P->next->prev = prec;
        else
            LP.last = prec;
        dealokasiNodeParent(P);
    }
}

void printStrukturMLL(listParent LP) {
    parentNode *P = LP.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== parent " << i++ << " ===" << endl;
        cout << "id genre : " << P->idGenre << endl;
        cout << "nama genre : " << P->namaGenre << endl;
        childNode *C = P->child.first;
        int j = 1;
        while (C != NULL) {
            cout << "- child " << j++ << " :" << endl;
            cout << "  id film : " << C->idFilm << endl;
            cout << "  judul film : " << C->judulFilm << endl;
            cout << "  durasi film : " << C->durasiFilm << " menit" << endl;
            cout << "  tahun tayang : " << C->tahunTayang << endl;
            cout << "  rating film : " << C->ratingFilm << endl;
            C = C->next;
        }
        cout << "------------------" << endl;
        P = P->next;
    }
}

void searchFilmByRatingRange(listParent LP, float min, float max) {
    parentNode *P = LP.first;
    int ip = 1;
    while (P != NULL) {
        childNode *C = P->child.first;
        int ic = 1;
        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "film ditemukan di genre " << P->namaGenre << endl;
                cout << "posisi parent ke-" << ip << endl;
                cout << "posisi child ke-" << ic << endl;
                cout << "judul : " << C->judulFilm << endl;
                cout << "rating : " << C->ratingFilm << endl;
                cout << "================" << endl;
            }
            C = C->next;
            ic++;
        }
        P = P->next;
        ip++;
    }
}