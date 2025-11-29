#include "tree.h"

address newNode(int x) {
    address p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(address &root, int x) {
    if (root == NULL) {
        root = newNode(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else {
        insertNode(root->right, x);
    }
}

void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == NULL) return 0;
    return root->info 
        + hitungTotalInfo(root->left) 
        + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) return 0;
    int leftDepth  = hitungKedalaman(root->left);
    int rightDepth = hitungKedalaman(root->right);
    return 1 + max(leftDepth, rightDepth);
}