#include <iostream>
using namespace std;


void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void tukarPosisiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}


void tukarPointer(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

  
    tukarPosisiArray(A, B, 1, 1);

    cout << "\nArray A setelah elemen (1,1) ditukar:\n";
    tampilArray(A);
    cout << "\nArray B setelah elemen (1,1) ditukar:\n";
    tampilArray(B);


    int x = 10, y = 20;
    int* ptr1 = &x;
    int* ptr2 = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}