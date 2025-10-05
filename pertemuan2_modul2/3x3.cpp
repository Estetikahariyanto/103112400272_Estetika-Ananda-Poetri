#include <iostream>
using namespace std;
int main() {
    int A[3][3], B[3][3], C[3][3];
    int pilihan;
    // Input matriks A
    cout << "Masukkan elemen matriks A (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    // Input matriks B
    cout << "\nMasukkan elemen matriks B (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }
    // Pilihan operasi
    cout << "\nPilih operasi:\n";
    cout << "1. Penjumlahan\n";
    cout << "2. Pengurangan\n";
    cout << "3. Perkalian\n";
    cout << "Masukkan pilihan (1-3): ";
    cin >> pilihan;
    cout << "\nHasil operasi:\n";
    if (pilihan == 1) {
        // Penjumlahan
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = A[i][j] + B[i][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    } else if (pilihan == 2) {
        // Pengurangan
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = A[i][j] - B[i][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    } else if (pilihan == 3) {
        // Perkalian
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }
    return 0;
}
