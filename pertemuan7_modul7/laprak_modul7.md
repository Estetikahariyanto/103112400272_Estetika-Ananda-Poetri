# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Estetika Ananda Poetri Hariyanto - 103112400272</p>

## Dasar Teori
Stack merupakan sebuah struktur data yang digunakan untuk menyimpan sejumlah objek atau variabel.
Sesuai dengan namanya, stack sering kali terlihat seperti tumpukan dalam bentuk fisik.
Karakteristik khas dari stack adalah penggunaan aturan LIFO (Last In, First Out).
Artinya, data yang terakhir dimasukkan ke dalam stack akan menjadi data pertama yang diambil atau dikeluarkan. 
Konsep ini mirip dengan tumpukan buku, di mana buku yang terakhir diletakkan di atas tumpukan harus diambil
terlebih dahulu sebelum bisa mengakses buku yang berada di bagian bawah tumpukan.
Operasi utama pada stack meliputi:
- Push, yaitu menambahkan elemen baru ke dalam stack pada posisi teratas.
- Pop, yaitu menghapus elemen teratas dari stack dan mengembalikan nilainya.
- Peek atau Top, yaitu mengecek elemen teratas dari stack tanpa menghapusnya.
- IsEmpty, yaitu memeriksa apakah stack kosong atau tidak.
- Size, yaitu mengembalikan jumlah elemen dalam stack.
Stack sering digunakan dalam berbagai konteks pemrograman, seperti manajemen memori,
pemanggilan fungsi, evaluasi ekspresi matematika, dan manajemen tumpukan
panggilan saat melakukan rekursi. [1].

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

### 1. Guided 1

stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

stack.h

``` C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
program ini untuk membuat dan memahami implementasi struktur data Stack 
berbasis Linked List yang mendukung operasi penambahan, penghapusan, pencarian, 
dan pembaruan data secara dinamis.

- push(stack &listStack, address nodeBaru)
void push(stack &listStack, address nodeBaru) {
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
}

ini utk menambahkan (menumpuk) node baru ke atas stack.

- pop(stack &listStack)
void pop(stack &listStack) {
    if(isEmpty(listStack)) {
        cout << "Stack kosong!";
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        dealokasi(nodeHapus);
    }
}

Menghapus data paling atas dari stack (LIFO).
Kalau kosong → tampilkan pesan "Stack kosong!"
Ilustrasi:
Sebelum pop: top -> 5 -> 4 -> 3
Setelah pop: top -> 4 -> 3

### 2. Guided 2

stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } 
    else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } 
    else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
} // <--- ini yang tadinya hilang!

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data <" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```

stack.h

```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
isEmpty() → memeriksa apakah stack kosong
isFull() → memeriksa apakah stack penuh
createStack() → inisialisasi stack
push() → menambahkan data
pop() → menghapus data paling atas
update() → memperbarui data pada posisi tertentu
view() → menampilkan isi stack
searchData() → mencari data tertentu dalam stack

push()
void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan!" << endl;
    }
}

Menambah data baru ke atas stack.
Jika penuh → tampilkan pesan “Stack penuh!”
Jika belum → top naik 1 dan data dimasukkan ke posisi itu.

pop()
void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus!" << endl;
    }
}

Menghapus elemen paling atas (data[top])
top dikurangi 1 setelah dihapus.

update()
void update(stackTable &s, int posisi){
    // posisi dihitung dari atas (1-based)
    int idx = s.top - (posisi - 1);
    ...
    cin >> s.data[idx];
}

Memperbarui data pada posisi ke-n dari atas.
Jika posisi tidak valid (misal melebihi isi stack) → tampilkan pesan kesalahan.
Pengguna diminta memasukkan angka baru untuk mengganti data lama.

Jadi, tujuan utama dari output program ini adalah untuk memperlihatkan secara jelas 
mekanisme kerja struktur data stack (tumpukan) melalui serangkaian operasi dasar.

## Unguided 

### 1. ![alt text](outputdansoal/soal1-unguided.png)

stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}
```

stack.h
```C++
#ifndef STACK_H
#define STACK_H

const int MAX = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 2);
    push(S, 9);

    pop(S);
    push(S, 8);
    pop(S);
    push(S, 2);
    pop(S);
    push(S, 9);
    push(S, 4);
    push(S, 3);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![alt text](outputdansoal/output-unguided1.png)

Stack adalah struktur data bertipe LIFO (Last In, First Out) — artinya:
Elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan.
Piring terakhir yang ditaruh di atas, akan jadi yang pertama diambil.

Fungsi-Fungsi Utama di stack.cpp
a. createStack(Stack &S)
void createStack(Stack &S) {
    S.top = -1;
}
Menyiapkan stack kosong sebelum digunakan.

b. push(Stack &S, infotype x)
void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}


Menambahkan data ke atas stack.
Contoh:
Jika top = -1, setelah push(S, 3) → top = 0, isi [3].

c. pop(Stack &S)
infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}


Menghapus elemen paling atas dan mengembalikan nilainya.
Misal stack [3, 4, 2], setelah pop → hasil 2, stack jadi [3, 4].

d. printInfo(Stack S)
void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}


Menampilkan isi stack dari atas ke bawah.

Contoh:
Jika S.info = [3, 4, 2, 9] dan top = 3,
outputnya:

[TOP] 9 2 4 3

e. balikStack(Stack &S)
void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

Langkah-langkah :
stack awal:
S: [TOP] 9 2 4 3
Buat stack baru temp (kosong).
Selama S belum kosong:
Ambil elemen dari S dengan pop()
Masukkan ke temp dengan push()
Setelah semua dipindah, isi temp jadi:
temp: [TOP] 3 4 2 9
Lalu S diset ulang dengan S = temp.
Hasil akhirnya:
[TOP] 3 4 2 9

4. Proses saat di main.cpp
Urutan kode di main:
createStack(S);
push(S,3);
push(S,4);
push(S,2);
push(S,9);
...
printInfo(S);
balikStack(S);
printInfo(S);
Setelah semua operasi push dan pop, isi akhir stack adalah:
[TOP] 9 2 4 3
Kemudian dipanggil balikStack(S) → urutan jadi terbalik:
[TOP] 3 4 2 9
sebelum dibalik [TOP] 9 2 4 3
setelah dibalik [TOP] 3 4 2 9

### 2. ![alt text](outputdansoal/soal2.png)
![alt text](outputdansoal/soal22.png)

main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```

stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, int x) {
    if (!isFull(S)) {
        S.top++;
        S.data[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &S, int &x) {
    if (!isEmpty(S)) {
        x = S.data[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.data[i] << " ";
    }
    cout << endl;
}

void pushAscending(Stack &S, int x) {
    Stack temp;
    createStack(temp);
    int y;

    while (!isEmpty(S) && S.data[S.top] < x) {
        pop(S, y);
        push(temp, y);
    }

    push(S, x);

    while (!isEmpty(temp)) {
        pop(temp, y);
        push(S, y);
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    int x;

    while (!isEmpty(S)) {
        pop(S, x);
        push(temp, x);
    }
    S = temp;
}
```

stack.h
```C++
#ifndef STACK_H
#define STACK_H

#define MAX 10

struct Stack {
    int data[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
void pop(Stack &S, int &x);
void printInfo(Stack S);

void pushAscending(Stack &S, int x);
void balikStack(Stack &S);

#endif
```

### Output Unguided 2 :

##### Output 1
![alt text](outputdansoal/output2.png)

Program ini menggunakan struktur data Stack (tumpukan), tapi dengan variasi prosedur khusus bernama pushAscending.
Tujuannya:
Setiap kali kita menambahkan data baru ke Stack, maka nilainya tetap tersusun menaik (ascending) dari bawah ke atas.

Cara Kerja pushAscending(Stack &S, int x)
Prosedur ini memasukkan elemen x ke Stack S, tetapi tetap menjaga agar urutan nilainya menaik dari bawah ke atas.
1. Buat stack sementara (temp) untuk menyimpan data sementara.
Stack temp;
createStack(temp);
int y;

2. Pindahkan elemen dari Stack utama ke temp selama elemen di atas lebih kecil dari x.
Tujuannya: mencari posisi yang tepat untuk menempatkan x.
while (!isEmpty(S) && S.data[S.top] < x) {
    pop(S, y);
    push(temp, y);
}

3. Masukkan elemen x ke Stack utama.
push(S, x);

4. Kembalikan semua elemen dari temp ke Stack utama.
while (!isEmpty(temp)) {
    pop(temp, y);
    push(S, y);
}


-> Prosedur balikStack(Stack &S)
Ini untuk membalik urutan elemen di dalam stack.
Digunakan agar tampilan stack bisa menunjukkan urutan menaik dari atas ke bawah.

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    int x;
    while (!isEmpty(S)) {
        pop(S, x);
        push(temp, x);
    }
    S = temp;
}

- pushAscending = versi khusus push yang menjaga urutan nilai di stack tetap menaik.
- balikStack digunakan untuk membalik tampilan agar terlihat dari kecil ke besar.
- Hasil akhir memperlihatkan bagaimana stack bisa diatur agar tetap terurut meskipun menggunakan prinsip LIFO.

### 3. ![alt text](outputdansoal/soal3.png)

stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void push(Stack &S, char data) {
    if (!isFull(S)) {
        S.top++;
        S.isi[S.top] = data;
    } else {
        cout << "Stack penuh, tidak bisa push." << endl;
    }
}

void pop(Stack &S, char &data) {
    if (!isEmpty(S)) {
        data = S.isi[S.top];
        S.top--;
    } else {
        cout << "Stack kosong, tidak bisa pop." << endl;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.isi[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    char x;
    while (!isEmpty(S)) {
        pop(S, x);
        push(temp, x);
    }
    S = temp;
}

void getInputStream(Stack &S) {
    char c;
    cout << "Masukkan input: ";
    while (true) {
        c = cin.get();       
        if (c == '\n') break; 
        push(S, c);         
    }
}
```

stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define MAX 50

struct Stack {
    char isi[MAX];
    int top;
};

void createStack(Stack &S);
bool isFull(Stack S);
bool isEmpty(Stack S);
void push(Stack &S, char data);
void pop(Stack &S, char &data);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif
```

main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![alt text](outputdansoal/output3.png)

Program ini menunjukkan:
Cara kerja stack berbasis array
Operasi dasar: push, pop, isFull, isEmpty
Tambahan operasi: balikStack dan getInputStream
Cara membalik urutan karakter yang dimasukkan user menggunakan struktur stack.

Alur Program:
Menampilkan pesan “Hello world!”
Membuat stack kosong S
Memanggil getInputStream() → user memasukkan teks
Menampilkan isi stack (terbalik dari urutan input)
Membalik isi stack menggunakan balikStack()
Menampilkan hasil stack yang sudah dibalik lagi

## Kesimpulan
Dari semua percobaan yang sudah dilakukan, bisa disimpulkan bahwa stack adalah salah
satu struktur data yang cara kerjanya seperti tumpukan barang
data yang terakhir dimasukkan akan jadi yang pertama diambil.

Stack bisa dibuat dengan dua cara :
1. Menggunakan Linked List, yang bisa menampung data sebanyak apa pun.
2. Menggunakan Array, yang jumlah datanya terbatas sesuai kapasitas yang ditentukan.

Guided 1
Menunjukkan cara membuat stack dengan linked list.
Program ini bisa menambah (push), menghapus (pop), memperbarui (update), melihat isi stack (view),
dan mencari data (search). Kelebihannya: tidak ada batasan jumlah data.

Guided 2
Membuat stack menggunakan array.
Operasinya sama seperti Guided 1, tapi ini jumlah datanya dibatasi oleh ukuran maksimum.
cara menghitung posisi data dari elemen paling atas.

Unguided 1
Menambahkan fungsi `balikStack()` untuk membalik urutan isi stack.
Ini berguna kalau kita mau menampilkan data dari bawah ke atas.

Unguided 2
Memiliki fungsi baru `pushAscending()`
fungsinya untuk menambahkan data ke stack tapi tetap menjaga agar
urutannya menaik dari kecil ke besar. Jadi, tidak hanya sekadar menumpuk data,
tapi juga menjaga urutan nilainya.

Unguided 3
Mengajarkan cara membalik teks yang diketik oleh pengguna menggunakan stack.
Misalnya, kalau pengguna mengetik “ABC”, maka hasil balikannya jadi “CBA”.

-> Stack bekerja dengan cara mengambil data terakhir yang masuk terlebih dahulu.
-> Operasi dasarnya seperti push, pop, isEmpty, dan isFull sangat penting.
-> Stack sering dipakai dalam berbagai kasus nyata, seperti:
  - proses  undo di aplikasi,
  - pembalikan teks atau data,
  - pemanggilan fungsi rekursi, dan
  - evaluasi ekspresi matematika.
-> Stack dengan linked list lebih fleksibel karena bisa menampung data tanpa batas,
sedangkan yang array lebih sederhana tapi kapasitasnya terbatas.

## Referensi
[1] [https://bakrie.ac.id/articles/552-kenalan-dengan-pengertian-stack-dalam-pemrograman.html]

