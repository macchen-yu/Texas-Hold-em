//
// Created by User on 2024/8/1.
//

#include "combineHand.h"
// 組合手牌函數
void combineHand(Card* hand, Card* holeCards, Card* community) {
    for (int i = 0; i < HOLE_CARDS; ++i) {
        hand[i] = holeCards[i];
    }
    for (int i = 0; i < COMMUNITY_CARDS; ++i) {
        hand[HOLE_CARDS + i] = community[i];
    }
}