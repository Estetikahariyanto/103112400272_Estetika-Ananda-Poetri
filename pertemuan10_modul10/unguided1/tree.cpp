#include <iostream>
#include "tree.h"
using namespace std;

Node* alokasi(int x) {
    Node* p = new Node;
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertNode(Node*& root, int x) {
    if (root == nullptr) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    } 
    else {
        insertNode(root->right, x);
    }
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}