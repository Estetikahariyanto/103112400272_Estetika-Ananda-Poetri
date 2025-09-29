#include<iostream>
using namespace std;

int cariMAX(int arr[], int size) {
    int MAX = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmetika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran ; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : "  << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++) {
        cout << "masukan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << "nilai MAX adalah : " << cariMAX(arr, ukuran) << endl;

    operasiAritmetika(arr, ukuran);
    return 0;
}

// pemanggilan function harus sesuai tipe data dan jumlah parameter
// pemanggilan array tidak perlu menyertakan ukuran array
//