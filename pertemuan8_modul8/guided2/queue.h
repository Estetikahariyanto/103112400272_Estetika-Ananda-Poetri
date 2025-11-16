#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

#define MAKSIMAL 10   // atau kapasitas sesuai kebutuhan

struct queue {
    int head;
    int tail;
    string nama[MAKSIMAL];
};

// Prototipe fungsi
void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif