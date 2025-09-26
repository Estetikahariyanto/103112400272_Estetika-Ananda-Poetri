#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka1: ";
    cin >> angka1;
    cout << "Masukkan angka2: ";
    cin >> angka2;

    // penjumlahan
    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    // pengurangan
    cout << "Hasil pengurangan: " << angka1 - angka2 << endl;
    // perkalian
    cout << "Hasil perkalian: " << angka1 * angka2 << endl;

    // pembagian dan modulus (dicek dulu angka2 != 0)
    if (angka2 != 0) {
        cout << "Hasil pembagian: " << angka1 / angka2 << endl;
        cout << "Hasil modulus: " << angka1 % angka2 << endl;
    } else {
        cout << "Pembagian dan modulus tidak bisa dilakukan (angka2 = 0)" << endl;
    }

    return 0;
}