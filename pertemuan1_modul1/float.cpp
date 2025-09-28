#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;
    cout << "masukkan bilangan pertama : ";
    cin >> angka1;
    cout << "masukkan bilangan kedua   : ";
    cin >> angka2;

    cout << "\nHasil Penjumlahan : " << angka1 + angka2 << endl;
    cout << "hasil Pengurangan : " << angka1 - angka2 << endl;
    cout << "hasil Perkalian   : " << angka1 * angka2 << endl;

    if (angka2 != 0) {
        cout << "hasil Pembagian   : " << angka1 / angka2 << endl;
    } else {
        cout << "hasil Pembagian   : Error (pembagian dengan nol tidak terdefinisi)" << endl;
    }
    return 0;
}