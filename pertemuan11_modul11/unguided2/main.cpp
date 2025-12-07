#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    NodeParent Aves = LP.first;
    insertLastChild(Aves->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(Aves->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    NodeParent Mamalia = Aves->next;
    insertLastChild(Mamalia->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(Mamalia->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(Mamalia->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    NodeParent Amfibi = Mamalia->next->next;
    insertLastChild(Amfibi->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    cout << "==== HASIL PRINT MLL ====" << endl;
    printMLLStructure(LP);

    cout << "==== HASIL PENCARIAN HEWAN TANPA EKOR ====" << endl;
    searchHewanByEkor(LP, false);

    return 0;
}