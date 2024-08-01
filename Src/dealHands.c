//
// Created by User on 2024/8/1.
//

#include "dealHands.h"
// 發牌函數
/**
 * @brief Deals hole cards to each player and community cards from the deck.
 *
 * This function takes a shuffled deck of cards and deals hole cards to
 * each player, followed by dealing the community cards.
 *
 * @param deck       The array representing the shuffled deck of cards.
 *                   It is assumed to have enough cards for the operation.
 * @param hands      A 2D array where each row represents a player's hole
 *                   cards. It should be pre-allocated to have
 *                   NUM_PLAYERS rows and HOLE_CARDS columns.
 * @param community  The array where the community cards will be stored.
 *                   It should be pre-allocated with COMMUNITY_CARDS elements.
 */
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