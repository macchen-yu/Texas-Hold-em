
#ifndef TEX_POKER_EVALUATEHAND_H

#define TEX_POKER_EVALUATEHAND_H
    #include "Card_basic.h"
    void evaluateHand(Card* handByPips, int* counts) ;
    static bool hasFlush(int* suitCount);
    static int getFlushSuit(int* suitCount);
    static void filterHandBySuit(int suit, Card* handBySuit);
    static bool hasRoyalFlush(Card* handBySuit);
    static bool hasStraight(Card* handByPips);
    static void countCardPips(Card hand[], int size, int matches[]);
#endif //TEX_POKER_EVALUATEHAND_H