//
// Created by User on 2024/8/1.
//
#include "initializeDeck.h"
// 初始化牌組
/**
 * @brief Initializes a deck of cards.
 *
 * This function initializes a standard deck of 52 playing cards. Each card
 * is represented by its suit and pip (rank). The deck array is filled with
 * cards in order, starting from Ace of Spades to King of Clubs.
 *
 * @param deck An array of cards to be initialized. The array should be
 *             pre-allocated with space for 52 cards.
 */
void initializeDeck(Card* deck) {
    for (int i = 0; i < NUM_CARDS; ++i) {
        deck[i].suit = i / 13;
        deck[i].pips = i % 13 + 1;
    }
}