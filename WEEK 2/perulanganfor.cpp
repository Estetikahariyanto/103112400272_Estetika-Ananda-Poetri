#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka1: ";
    cin >> angka1;
    cout << "Masukkan angka2: ";
    cin >> angka2;

    // perulangan for pertama
    for (int i = 0; i < angka1; i++) {
        cout << i << " - ";
    }

    cout << endl;

    // perulangan for kedua
    for (int i = 0; i < angka2; i++) {
        cout << i << " - ";
    }

    cout << endl;

    return 0;
}