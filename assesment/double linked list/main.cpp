#include "DLLPlaylist.h"
#include <iostream>

using namespace std;

int main() {
    List playlist;
    createList(playlist);

    Song s1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2f};
    Song s2 = {"Langkahmu", "Delta", 185, 320, 4.8f};
    Song s3 = {"Hujan Minggu", "Arka", 240, 90, 3.9f};

    insertLast(playlist, s1);
    insertLast(playlist, s2);
    insertLast(playlist, s3);

    cout << "Daftar lagu (awal):\n";
    viewList(playlist);
    cout << "\n";

    double minS = 100.0, maxS = 900.0;
    auto found = searchByPopularityRange(playlist, minS, maxS);
    cout << "Pencarian PopularityScore di antara " << minS << " dan " << maxS << ":\n";
    for (auto &p : found) {
        cout << "Pos " << p.first << " - " << p.second.Title
             << " (Score=" << fixed << setprecision(2) << PopularityScore(p.second) << ")\n";
    }
    cout << "\n";

    //update node pada posisi ke 2
    Song newSong = {"Pelita", "Luna", 200, 260, 4.5f};
    if (updateAtPosition(playlist, 2, newSong)) {
        cout << "Update posisi 2 berhasil.\n";
    }

    //setelah update
    cout << "Daftar lagu (setelah update):\n";
    viewList(playlist);
    cout << "\n";

    //operasi before
    insertBefore;
    Song = {"Senandung", "Mira", 175, 120, 4.0f};,

    //setelah insert before
    cout << "Daftar lagu (setelah insertBefore):\n";
    viewList(playlist);
    cout << "\n";

    //update before pada node posisi ke 2
    Song newSong = {"Pelita", "Luna", 200, 260, 4.5f};
    if (updateAtPosition(playlist, 2, newSong)) {
        cout << "Update posisi 2 berhasil.\n";
    }

    //setelah update pada node posisi ke 2
    cout << "Daftar lagu (setelah update):\n";
    viewList(playlist);
    cout << "\n";

    //delete before
    Song removed;
    if (deleteBefore(playlist, removed)) {
        cout << "Dihapus lagu pertama: " << removed.Title << "\n";
    }

    cout << "Daftar lagu (setelah deleteFirst):\n";
    viewList(playlist);

    search PopularityScore(min = 150.0, max = 300.0);

    return 0;
}