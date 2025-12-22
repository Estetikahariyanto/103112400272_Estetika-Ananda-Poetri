#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    GraphKota G;
    createGraph(G);

    insertNode(G, alokasiNode("jakarta"));
    insertNode(G, alokasiNode("bogor"));
    insertNode(G, alokasiNode("depok"));
    insertNode(G, alokasiNode("bekasi"));
    insertNode(G, alokasiNode("tangerang"));

    connectNode(G, "jakarta", "bogor", 42);
    connectNode(G, "jakarta", "depok", 21);
    connectNode(G, "jakarta", "bekasi", 16);
    connectNode(G, "jakarta", "tangerang", 24);
    connectNode(G, "bogor", "bekasi", 60);
    connectNode(G, "bogor", "depok", 22);
    connectNode(G, "depok", "tangerang", 30);
    connectNode(G, "bekasi", "tangerang", 45);

    printGraph(G);

    cout << endl << "=== hasil traversal bfs & dfs ===" << endl;
    resetVisited(G);
    printBFS(G, "tangerang");
