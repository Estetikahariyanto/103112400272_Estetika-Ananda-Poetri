#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//tipe data
struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; //skala 0.0 - 5.0
};

struct Node {
    Song info;
    Node* prev;
    Node* next;
    Node(const Song& s) : info(s), prev(nullptr), next(nullptr) {}
};

struct List {
    Node* head;
    Node* tail;
    List() : head(nullptr), tail(nullptr) {}
};

double PopularityScore(const Song& s) {
    return 0.8 * s.PlayCount + 20.0 * s.Rating;
}

//deklarasi fungsi & prosedur
bool isEmpty(const List& L) {
    return L.head == nullptr;
}

void createList(List& L) {
    L.head = L.tail = nullptr;
}

Node* allocate(const Song& S) {
    return new Node(S);
}

void deallocate(Node* P) {
    delete P;
}

void insertFirst(List& L, const Song& S) {
    Node* P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List& L, const Song& S) {
    Node* P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

//insert after
bool insertAfter(List& L, Node* Q, const Song& S) {
    if (Q == nullptr) return false;
    if (Q == L.tail) {
        insertLast(L, S);
        return true;
    }
    Node* P = allocate(S);
    Node* R = Q->next;
    P->next = R;
    P->prev = Q;
    Q->next = P;
    if (R) R->prev = P;
    return true;
}

//insert before
bool insertBefore(List& L, Node* Q, const Song& S) {
    if (Q == nullptr) return false;
    if (Q == L.head) {
        insertFirst(L, S);
        return true;
    }
    Node* P = allocate(S);
    Node* LQ = Q->prev;
    P->prev = LQ;
    P->next = Q;
    Q->prev = P;
    if (LQ) LQ->next = P;
    return true;
}

//delete first
bool deleteFirst(List& L, Song& outS) {
    if (isEmpty(L)) return false;
    Node* P = L.head;
    outS = P->info;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.head = P->next;
        L.head->prev = nullptr;
    }
    deallocate(P);
    return true;
}

//delete last
bool deleteLast(List& L, Song& outS) {
    if (isEmpty(L)) return false;
    Node* P = L.tail;
    outS = P->info;
    if (L.head == L.tail) {
        L.head = L.tail = nullptr;
    } else {
        L.tail = P->prev;
        L.tail->next = nullptr;
    }
    deallocate(P);
    return true;
}

//delete after
bool deleteAfter(List& L, Node* Q, Song& outS) {
    if (Q == nullptr || Q->next == nullptr) return false;
    Node* P = Q->next;
    outS = P->info;
    Node* R = P->next;
    Q->next = R;
    if (R) R->prev = Q;
    if (P == L.tail) L.tail = Q;
    deallocate(P);
    return true;
}

//delete before
bool deleteBefore(List& L, Node* Q, Song& outS) {
    if (Q == nullptr || Q->prev == nullptr) return false;
    Node* P = Q->prev;
    outS = P->info;
    Node* Lp = P->prev;
    Q->prev = Lp;
    if (Lp) Lp->next = Q;
    if (P == L.head) L.head = Q;
    deallocate(P);
    return true;
}

//deleteAt
bool deleteAt(List& L, Node* Q, Song& outS) {
    if (Q == nullptr) return false;
    if (Q == L.head) return deleteFirst(L, outS);
    if (Q == L.tail) return deleteLast(L, outS);
    Node* Lq = Q->prev;
    Node* Rq = Q->next;
    outS = Q->info;
    Lq->next = Rq;
    Rq->prev = Lq;
    deallocate(Q);
    return true;
}

//update at posisi
bool updateAtPosition(List& L, int posisi, const Song& newSong) {
    if (posisi <= 0) return false;
    Node* cur = L.head;
    int idx = 1;
    while (cur && idx < posisi) { cur = cur->next; ++idx; }
    if (!cur) return false;
    cur->info = newSong;
    return true;
}

//update before
bool updateBefore(List& L, Node* Q, const Song& newSong) {
    if (Q == nullptr || Q->prev == nullptr) return false;
    Q->prev->info = newSong;
    return true;
}

//VIEW LIST
void viewList(const List& L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }
    cout << left << setw(5) << "Pos"
         << setw(30) << "Title"
         << setw(20) << "Artist"
         << setw(10) << "Duration"
         << setw(10) << "PlayCnt"
         << setw(8) << "Rating"
         << setw(15) << "PopularityScore" << "\n";
    cout << string(100, '-') << "\n";
    Node* cur = L.head;
    int pos = 1;
    while (cur) {
        cout << setw(5) << pos
             << setw(30) << cur->info.Title
             << setw(20) << cur->info.Artist
             << setw(10) << cur->info.DurationSec
             << setw(10) << cur->info.PlayCount
             << setw(8) << fixed << setprecision(1) << cur->info.Rating
             << setw(15) << fixed << setprecision(2) << PopularityScore(cur->info)
             << "\n";
        cur = cur->next;
        pos++;
    }
}

//SEARCH BY POPULARITY RANGE
vector<pair<int, Song>> searchByPopularityRange(const List& L, double minScore, double maxScore) {
    vector<pair<int, Song>> results;
    Node* cur = L.head;
    int pos = 1;
    while (cur) {
        double ps = PopularityScore(cur->info);
        if (ps >= minScore && ps <= maxScore) {
            results.emplace_back(pos, cur->info);
        }
        cur = cur->next;
        pos++;
    }
    return results;
}