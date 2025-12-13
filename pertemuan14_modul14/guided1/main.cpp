#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'C', 'D');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'D', 'E');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===\\n";
    PrintInfoGraph(G);

    cout << "\\n";
    PrintBFS(G, 'A');

    cout << "\\n";
    PrintDFS(G, 'A');

    return 0;
}