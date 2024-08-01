//
// Created by User on 2024/8/1.
//

#include "dealHands.h"
// 發牌函數
void dealHands(Card* deck, Card hands[NUM_PLAYERS][HOLE_CARDS], Card* community) {
    int cardIndex = 0;

    // 發底牌
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        for (int j = 0; j < HOLE_CARDS; ++j) {
            hands[i][j] = deck[cardIndex++];
        }
    }

    // 發公共牌
    for (int i = 0; i < COMMUNITY_CARDS; ++i) {
        community[i] = deck[cardIndex++];
    }
}