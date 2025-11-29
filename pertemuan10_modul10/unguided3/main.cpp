#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left, *right;
};

//fungsi untuk membuat node baru
Node* newNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

//pre-order: root -> left -> right
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

//post-order: left -> right -> root
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->info << " ";
    }
}

int main() {
    //bentuk tree sesuai soal
    Node* root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(7);

    root->left->left = newNode(2);
    root->left->right = newNode(5);

    root->left->left->left = newNode(1);
    root->left->left->right = newNode(3);

    //memunculkan output
    cout << "Pre-order  : ";
    preorder(root);     // Hasil: 6 4 2 1 3 5 7
    cout << endl;

    cout << "Post-order : ";
    postorder(root);    // Hasil: 1 3 2 5 4 7 6
    cout << endl;

    return 0;
}