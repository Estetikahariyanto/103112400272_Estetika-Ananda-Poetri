#ifndef TREE_H
#define TREE_H

struct Node {
    int info;
    Node* left;
    Node* right;
};

Node* alokasi(int x);

void insertNode(Node*& root, int x);

void inOrder(Node* root);

#endif