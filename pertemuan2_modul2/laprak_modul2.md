# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Estetika Ananda Poetri Hariyanto - 103112400272</p>

## Dasar Teori
Array merupakan sebuah variabel yang menyimpan lebih dari 1 buah data yang memiliki tipe data yang sama. Jadi dapat dikatakan bahwa array merupakan kumpulan dari data-data tunggal yang dijadikan dalam 1 variabel array yang alamat memorinya berbeda yang selanjutnya disebut elemen-elemen array yang bisa kita akses berdasarkan indeks.Array atau larik sendiri di definisikan sebagai pemesanan alokasi memory berurutan. Array (larik) merupakan tipe data tersetruktur dimana didalamnya terdiri dari komponen –komponen yang mempunyai tipe data yang sama. Didalam suatu array jumlah komponen banyaknya adalah tetap. [1].

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Array 1 Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "masukkan value indeks ke-" << i << ": ";
        cin >> arr[i];
    }

    int j = 0;
    while(j < 5) {
        cout << "isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }

    return 0;
}

```
Program ini digunakan untuk memasukkan 5 nilai ke dalam array dan kemudian menampilkan kembali nilai-nilai tersebut sesuai dengan indeksnya.

### 2. Array 2 Dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4},
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5},
    };
    int arrD[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program ini membuat dua matriks 2x2, yaitu A = {{1,2},{3,4}} dan B = {{2,3},{4,5}}, lalu mengalikan keduanya menggunakan rumus perkalian matriks. Hasil perkalian disimpan pada matriks D, kemudian ditampilkan dengan fungsi tampilkanHasil. Output akhir yang muncul di layar adalah matriks hasil perkalian:
10 13  
22 29

### 3. Function

```C++
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
```
Program di atas berfungsi untuk mencari nilai maksimum dari sebuah array serta menghitung jumlah dan perkalian semua elemen array.
per bagian:
Fungsi cariMAX
Menerima array dan ukurannya.
Membandingkan setiap elemen untuk mencari nilai terbesar.
Mengembalikan nilai maksimum.
Fungsi operasiAritmetika
Menjumlahkan seluruh elemen array lalu menampilkan hasilnya.
Mengalikan semua elemen array lalu menampilkan hasilnya.
Fungsi main
Membuat array dengan ukuran 5.
Meminta input nilai array dari pengguna sebanyak 5 kali.
Menampilkan nilai maksimum dengan memanggil fungsi cariMAX.
Menampilkan hasil penjumlahan dan perkalian dengan memanggil fungsi operasiAritmetika.
Pemanggilan fungsi harus sesuai dengan tipe data dan jumlah parameter.
Saat memanggil array ke dalam fungsi, tidak perlu menuliskan ukuran array lagi (cukup nama array saja).

### 4. Pointer

```C++
#include<iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Address of a : " << &a << endl;
    cout << "Value stored of ptr (adress of a): " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    tukar (&a, &b);
    cout << "After swaping value of a : " << a <<  " and b= " << b << endl;

    return 0;
}
```
Fungsi tukar(int *x, int *y)
Berfungsi untuk menukar nilai dua variabel.
Parameter berupa pointer (int *x, int *y) sehingga fungsi bisa langsung mengubah nilai asli variabel yang dikirim.
Prosesnya:
Simpan nilai *x ke temp.
Isi *x dengan nilai *y.
Isi *y dengan nilai temp.
Fungsi main
Membuat dua variabel a = 20 dan b = 30.
Membuat pointer ptr dan mengarahkannya ke alamat variabel a.
Menampilkan:
Nilai dari a.
Alamat memori a.
Nilai yang disimpan di ptr (yaitu alamat dari a).
Nilai yang ditunjuk oleh ptr (isi dari a, yaitu 20).
Memanggil fungsi tukar(&a, &b) → menukar nilai a dan b.
Menampilkan hasil setelah ditukar.
program ini untuk menunjukkan cara kerja pointer (mengakses alamat dan nilai variabel) serta menggunakan pointer untuk menukar nilai dua variabel.

### 5. Reference

```C++
#include<iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a  << endl;
    cout << "alamat a (&a) : " << &a  << endl;
    cout << "Nilai ref (alias a) : " << ref  << endl;
    cout << "Almat ref (&ref) : " << &ref << endl;

    //menukar nilai a lewat reference
    ref = 50;
    cout << "\nsetelah ref = 50;" << a  << endl;
    cout << "Nilai a : " << a  << endl;
    cout << "Nilai ref : " << ref  << endl;
    

    tukar(a, b);
    cout << "After swapping, value of a=" << a << "and b=" << b << endl;

    return 0;
}
```
Fungsi tukar(int &x, int &y)
Fungsi ini menggunakan reference parameter (&) untuk menukar nilai dari dua variabel.
perubahan pada x dan y akan langsung mengubah nilai variabel asli yang dikirim dari main.
Deklarasi Variabel di main:
int a = 20, b = 30;
int& ref = a;
a bernilai 20, b bernilai 30.
ref adalah reference (alias) dari a. Jadi, ref bukan variabel baru, tetapi nama lain untuk a.

Menampilkan Nilai dan Alamat:
a dan ref memiliki nilai sama.

Alamat &a dan &ref juga sama, karena ref hanyalah alias dari a.
Mengubah Nilai melalui Reference:
ref = 50;
Karena ref alias dari a, maka a otomatis berubah jadi 50.

Menukar Nilai dengan Fungsi:
tukar(a, b);
Nilai a dan b akan tertukar.
Awalnya a = 50, b = 30 → setelah swap: a = 30, b = 50.

## Unguided 

### 1. ..

```C++
..
```
### Output Unguided 1 :

##### Output 1
![alt text](output/output-unguided1-modul1.png)

jelasakn

### 2. ..

```C++
..
```
### Output Unguided 2 :

##### Output 1
![alt text](output/output-unguided2-modul1.png)

jlskn

### 3. ..

```C++
..
```
### Output Unguided 3 :

##### Output 1
![alt text](output/output-unguided3-modul1.png)

jlskn

## Kesimpulan
...

## Referensi
[1] [https://osf.io/preprints/osf/mx6cp]

