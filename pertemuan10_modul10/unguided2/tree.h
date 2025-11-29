#ifndef tree_H
#define tree_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left, *right;
};

typedef Node* address;

address newNode(int x);
void insertNode(address &root, int x);
void InOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start = 0);
int hitungKedalaman(address root, int start = 0);

#endif