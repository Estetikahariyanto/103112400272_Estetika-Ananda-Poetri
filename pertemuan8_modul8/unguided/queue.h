#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

const int MAX = 5;

struct Queue {
    int data[MAX];
    int head;
    int tail;
};

// ===== FUNGSI DASAR =====
void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void printQueue(Queue Q);

// ===== ALTERNATIF 1: HEAD DIAM, TAIL BERGERAK =====
void enqueue1(Queue &Q, int value);
void dequeue1(Queue &Q);

// ===== ALTERNATIF 2: HEAD & TAIL BERGERAK =====
void enqueue2(Queue &Q, int value);
void dequeue2(Queue &Q);

// ===== ALTERNATIF 3: CIRCULAR QUEUE =====
void enqueue3(Queue &Q, int value);
void dequeue3(Queue &Q);

#endif