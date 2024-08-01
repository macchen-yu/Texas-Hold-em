//
// Created by User on 2024/8/1.
//
#include "shuffleDeck.h"
// 洗牌函數
/**
 * @brief Shuffles a deck of cards.
 *
 * This function shuffles a deck of cards using the Fisher-Yates shuffle algorithm.
 * It randomly swaps each card in the deck to ensure a well-shuffled deck.
 *
 * @param deck The array representing the deck of cards to be shuffled.
 * @param size The number of cards in the deck.
 */
void shuffleDeck(Card* deck, int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}