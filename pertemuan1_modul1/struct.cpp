#include <iostream>
#include <string>
using namespace std;

int main() {
    const int jumlah = 3; // contoh, biar ga kepanjangan

    struct rapot {
        string nama;
        int nilai;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama siswa: ";
        getline(cin, siswa[i].nama);

        cout << "Masukkan jumlah nilai: ";
        cin >> siswa[i].nilai;
        cin.ignore(); // buang newline setelah input angka
    }

    cout << "\n=== Data Siswa ===\n";
    int i = 0;
    while (i < jumlah) {
        cout << "Nama: " << siswa[i].nama 
             << " | Nilai: " << siswa[i].nilai << endl;
        i++;
    }

    return 0;
}