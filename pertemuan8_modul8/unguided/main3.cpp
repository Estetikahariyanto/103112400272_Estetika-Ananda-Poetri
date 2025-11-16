#include "queue.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout << "Hello world!" << endl;
    cout << "--------------------------" << endl;
    cout << "H - T \t | Queue Info" << endl;
    cout << "--------------------------" << endl;

    enqueue3(Q, 5);  printQueue(Q);
    enqueue3(Q, 2);  printQueue(Q);
    enqueue3(Q, 7);  printQueue(Q);
    enqueue3(Q, 4);  printQueue(Q);
    enqueue3(Q, 9);  printQueue(Q);
    dequeue3(Q);     printQueue(Q);
    dequeue3(Q);     printQueue(Q);
    enqueue3(Q, 6);  printQueue(Q);
    enqueue3(Q, 8);  printQueue(Q);

    return 0;
}