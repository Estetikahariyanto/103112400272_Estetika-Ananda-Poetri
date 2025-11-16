#include "queue.h"
#include <iomanip>
using namespace std;

// ===============================
// FUNGSI DASAR QUEUE
// ===============================
void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

void printQueue(Queue Q) {
    cout << left << setw(3) << Q.head << " - " << setw(3) << Q.tail << " | ";
    if (isEmpty(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.data[i] << " ";
        }
    }
    cout << endl;
}

// ===============================
// ALTERNATIF 1: HEAD DIAM, TAIL BERGERAK
// ===============================
void enqueue1(Queue &Q, int value) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.data[Q.tail] = value;
    }
}

void dequeue1(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }
    }
}

// ===============================
// ALTERNATIF 2: HEAD & TAIL BERGERAK
// ===============================
void enqueue2(Queue &Q, int value) {
    if (isFull(Q)) {
        cout << "Queue penuh! Data akan digeser..." << endl;
        int j = 0;
        for (int i = Q.head; i <= Q.tail; i++) {
            Q.data[j++] = Q.data[i];
        }
        Q.tail = j - 1;
        Q.head = 0;
    }

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.data[Q.tail] = value;
}

void dequeue2(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }
    }
}

// ===============================
// ALTERNATIF 3: CIRCULAR QUEUE
// ===============================
void enqueue3(Queue &Q, int value) {
    if ((Q.tail + 1) % MAX == Q.head) {
        cout << "Queue penuh (Circular)!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.data[Q.tail] = value;
}

void dequeue3(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong (Circular)!" << endl;
        return;
    }

    if (Q.head == Q.tail) {
        createQueue(Q);
    } else {
        Q.head = (Q.head + 1)%MAX;
    }
}