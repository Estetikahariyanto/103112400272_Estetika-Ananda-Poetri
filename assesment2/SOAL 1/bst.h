#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node {
    int id;
    string nama;
    int stok;
    Node *left, *right;
};

Node* createNode(int, string, int);
Node* insert(Node*, int, string, int);
Node* searchById(Node*, int);
void searchByProduct(Node*, string);
void inOrder(Node*);
Node* findMin(Node*);
Node* findMax(Node*);
Node* deleteNode(Node*, int);
void deleteTree(Node*&);

#endif
