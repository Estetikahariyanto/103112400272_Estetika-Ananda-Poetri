//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
#include <string>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif