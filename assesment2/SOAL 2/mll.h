#ifndef mll_h
#define mll_h

#include <iostream>
#include <string>
using namespace std;

struct childNode {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    childNode *next;
    childNode *prev;
};

struct listChild {
    childNode *first;
    childNode *last;
};

struct parentNode {
    string idGenre;
    string namaGenre;
    parentNode *next;
    parentNode *prev;
    listChild child;
};

struct listParent {
    parentNode *first;
    parentNode *last;
};

void createListParent(listParent &LP);
void createListChild(listChild &LC);

parentNode* alokasiNodeParent(string id, string nama);
childNode* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void dealokasiNodeParent(parentNode *&P);
void dealokasiNodeChild(childNode *&C);

void insertFirstParent(listParent &LP, parentNode *P);
void insertLastChild(listChild &LC, childNode *C);

void hapusListChild(listChild &LC);
void deleteAfterParent(listParent &LP, parentNode *prec);

void printStrukturMLL(listParent LP);
void searchFilmByRatingRange(listParent LP, float min, float max);

#endif