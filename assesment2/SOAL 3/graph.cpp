#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void createGraph(GraphKota &G) {
    G.first = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->namaKota = nama;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->kotaTujuan = tujuan;
    E->jarak = jarak;
    E->next = NULL;
    return E;
}

void insertNode(GraphKota &G, adrKota P) {
    P->next = G.first;
    G.first = P;
}

adrKota findNode(GraphKota G, string nama) {
    adrKota P = G.first;
    while (P != NULL) {
        if (P->namaKota == nama)
            return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(GraphKota &G, string kota1, string kota2, int jarak) {
    adrKota A = findNode(G, kota1);
    adrKota B = findNode(G, kota2);

    if (A && B) {
        adrEdge E1 = alokasiEdge(B, jarak);
        E1->next = A->firstEdge;
        A->firstEdge = E1;

        adrEdge E2 = alokasiEdge(A, jarak);
        E2->next = B->firstEdge;
        B->firstEdge = E2;
    }
}

void disconnectNode(GraphKota &G, string kota1, string kota2) {
    adrKota A = findNode(G, kota1);
    adrKota B = findNode(G, kota2);

    if (A && B) {
        adrEdge *E = &A->firstEdge;
        while (*E) {
            if ((*E)->kotaTujuan == B) {
                *E = (*E)->next;
                break;
            }
            E = &(*E)->next;
        }

        E = &B->firstEdge;
        while (*E) {
            if ((*E)->kotaTujuan == A) {
                *E = (*E)->next;
                break;
            }
            E = &(*E)->next;
        }
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota *P = &G.first;
    while (*P) {
        if ((*P)->namaKota == nama) {
            adrKota del = *P;
            *P = del->next;

            adrKota Q = G.first;
            while (Q) {
                disconnectNode(G, Q->namaKota, nama);
                Q = Q->next;
            }
            delete del;
            return;
        }
        P = &(*P)->next;
    }
}

void printGraph(GraphKota G) {
    cout << "=== representasi adjacency list graph ===\n";
    adrKota P = G.first;
    while (P) {
        cout << "node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E) {
            cout << E->kotaTujuan->namaKota
                 << "(" << E->jarak << " km), ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void resetVisited(GraphKota &G) {
    adrKota P = G.first;
    while (P) {
        P->visited = 0;
        P = P->next;
    }
}