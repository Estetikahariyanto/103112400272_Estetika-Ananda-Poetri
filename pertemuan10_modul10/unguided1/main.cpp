#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Node* root = nullptr;

    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 5);
    insertNode(root, 7);

    inOrder(root);

    return 0;
}