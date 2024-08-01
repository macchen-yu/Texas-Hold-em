//
// Created by User on 2024/8/1.
//
#include "shuffleDeck.h"
// 洗牌函數
void shuffleDeck(Card* deck, int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}