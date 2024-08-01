//
// Created by User on 2024/8/1.
//

#include "combineHand.h"
// 組合手牌函數
/**
* @brief Combines the hole cards and community cards into a single hand.
*
* This function takes the player's hole cards and the community cards
* and combines them into a single hand array. The hand array will first
* contain the hole cards followed by the community cards.
*
* @param hand       The array where the combined hand will be stored.
*                   It should be pre-allocated with enough space to hold
*                   both the hole cards and community cards.
* @param holeCards  The array containing the player's hole cards. It is
*                   assumed to have HOLE_CARDS elements.
* @param community  The array containing the community cards. It is
*                   assumed to have COMMUNITY_CARDS elements.
*/
void combineHand(Card* hand, Card* holeCards, Card* community) {

    for (int i = 0; i < HOLE_CARDS; ++i) {
        hand[i] = holeCards[i];
    }
    for (int i = 0; i < COMMUNITY_CARDS; ++i) {
        hand[HOLE_CARDS + i] = community[i];
    }
}