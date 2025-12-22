#include "bst.h"
#include <iostream>
using namespace std;

Node* createNode(int id, string nama, int stok) {
    Node* n = new Node;
    n->id = id;
    n->nama = nama;
    n->stok = stok;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int id, string nama, int stok) {
    if (!root) return createNode(id, nama, stok);
    if (id < root->id)
        root->left = insert(root->left, id, nama, stok);
    else if (id > root->id)
        root->right = insert(root->right, id, nama, stok);
    return root;
}

Node* searchById(Node* root, int id) {
    if (!root || root->id == id) return root;
    if (id < root->id)
        return searchById(root->left, id);
    return searchById(root->right, id);
}

void searchByProduct(Node* root, string nama) {
    if (!root) return;
    searchByProduct(root->left, nama);
    if (root->nama == nama)
        cout << root->id << " - " << root->nama
             << " (Stok: " << root->stok << ")\n";
    searchByProduct(root->right, nama);
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->id << " - " << root->nama
         << " (Stok: " << root->stok << ")\n";
    inOrder(root->right);
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

Node* deleteNode(Node* root, int id) {
    if (!root) return root;

    if (id < root->id)
        root->left = deleteNode(root->left, id);
    else if (id > root->id)
        root->right = deleteNode(root->right, id);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->id = temp->id;
        root->nama = temp->nama;
        root->stok = temp->stok;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

void deleteTree(Node*& root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}