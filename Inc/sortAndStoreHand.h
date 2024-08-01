//
// Created by User on 2024/8/1.
//

#ifndef TEX_POKER_SORTANDSTOREHAND_H
#define TEX_POKER_SORTANDSTOREHAND_H
    #include "Card_basic.h"
    void sortAndStoreHand(Card hand[], Card handByPips[]);
    static int compareByPips(const void* a, const void* b);
#endif //TEX_POKER_SORTANDSTOREHAND_H
