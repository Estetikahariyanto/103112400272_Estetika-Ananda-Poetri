#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge;
        node1->firstEdge = Edge1;

        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) {
            if (PrevE == NULL) {
                node1->firstEdge = edgeBantu->Next;
            } else {
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

void DeleteNode(Graph &G, infoGraph X) {
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus);
        nodeLainnya = nodeLainnya->Next;
    }

    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge temp = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete temp;
    }
    nodeHapus->firstEdge = NULL;

    if (G.First == nodeHapus) {
        G.First = nodeHapus->Next;
    } else {
        adrNode bantu = G.First;
        while (bantu->Next != nodeHapus) {
            bantu = bantu->Next;
        }
        bantu->Next = nodeHapus->Next;
    }

    delete nodeHapus;
}

void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode bantu = G.First;
    while (bantu != NULL) {
        bantu->visited = 0;
        bantu = bantu->Next;
    }
}

void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    if (StartNode == NULL) return;

    queue<adrNode> Q;

    Q.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode bantu = Q.front();
        Q.pop();
        cout << bantu->info << " - ";

        adrEdge e = bantu->firstEdge;
        while (e != NULL) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1;
                Q.push(e->Node);
            }
            e = e->Next;
        }
    }
    cout << endl;
}

void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    if (StartNode == NULL) return;

    stack<adrNode> S;
    S.push(StartNode);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode bantu = S.top();
        S.pop();

        if (bantu->visited == 0) {
            bantu->visited = 1;
            cout << bantu->info << " - ";

            adrEdge e = bantu->firstEdge;
            while (e != NULL) {
                if (e->Node->visited == 0) {
                    S.push(e->Node);
                }
                e = e->Next;
            }
        }
    }
    cout << endl;
}