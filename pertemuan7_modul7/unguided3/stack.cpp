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