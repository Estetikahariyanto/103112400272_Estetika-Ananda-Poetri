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