#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    Node* root = NULL;

    root = insert(root, 50, "Monitor LED", 10);
    root = insert(root, 30, "Keyboard RGB", 20);
    root = insert(root, 70, "Mouse Gaming", 15);
    root = insert(root, 20, "Kabel HDMI", 50);
    root = insert(root, 40, "Headset 7.1", 12);
    root = insert(root, 60, "Webcam HD", 8);
    root = insert(root, 80, "Speaker BT", 5);

    cout << "InOrder:\n";
    inOrder(root);

    cout << "\nSearch ID 40:\n";
    Node* s = searchById(root, 40);
    if (s)
        cout << s->id << " - " << s->nama << endl;
    else
        cout << "Tidak ditemukan\n";

    cout << "\nSearch Product Webcam HD:\n";
    searchByProduct(root, "Webcam HD");

    cout << "\nMin ID: " << findMin(root)->id << endl;
    cout << "Max ID: " << findMax(root)->id << endl;

    root = deleteNode(root, 20);
    cout << "\nSetelah hapus ID 20:\n";
    inOrder(root);

    deleteTree(root);
    cout << "\nTree dihapus\n";

    return 0;
}