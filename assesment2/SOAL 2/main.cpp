#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    parentNode *G001 = alokasiNodeParent("G001", "action");
    parentNode *G002 = alokasiNodeParent("G002", "comedy");
    parentNode *G003 = alokasiNodeParent("G003", "horror");
    parentNode *G004 = alokasiNodeParent("G004", "romance");

    insertFirstParent(LP, G004);
    insertFirstParent(LP, G003);
    insertFirstParent(LP, G002);
    insertFirstParent(LP, G001);

    insertLastChild(G001->child, alokasiNodeChild("FA001", "the Raid", 101, 2011, 7.6));
    insertLastChild(G002->child, alokasiNodeChild("FC001", "agak Laen", 119, 2024, 8.0));
    insertLastChild(G002->child, alokasiNodeChild("FC002", "my Stupid Boss", 108, 2016, 6.8));
    insertLastChild(G003->child, alokasiNodeChild("FH001", "pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(G004->child, alokasiNodeChild("FR001", "habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(G004->child, alokasiNodeChild("FR002", "dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(LP);
    searchFilmByRatingRange(LP, 8.0, 8.5);
    deleteAfterParent(LP, G001);
    printStrukturMLL(LP);
}
