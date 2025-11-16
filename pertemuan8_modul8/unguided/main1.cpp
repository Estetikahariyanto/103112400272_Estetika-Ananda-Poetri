#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout << "Hello world!" << endl;
    cout << "--------------------------" << endl;
    cout << "H - T \t | Queue Info" << endl;
    cout << "--------------------------" << endl;

    printQueue(Q);
    enqueue1(Q, 5); printQueue(Q);
    enqueue1(Q, 2); printQueue(Q);
    enqueue1(Q, 7); printQueue(Q);
    dequeue1(Q); printQueue(Q);
    enqueue1(Q, 4); printQueue(Q);
    dequeue1(Q); printQueue(Q);
    dequeue1(Q); printQueue(Q);

    return 0;
}