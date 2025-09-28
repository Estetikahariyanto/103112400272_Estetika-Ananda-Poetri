#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    for (int i = n; i >= 0; i--) {
        //mencetak angka secara menurun
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        //mencetak angka secara menaik
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}