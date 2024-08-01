//
// Created by User on 2024/8/1.
//
#include "initializeDeck.h"
// 初始化牌組
void initializeDeck(Card* deck) {
    for (int i = 0; i < NUM_CARDS; ++i) {
        deck[i].suit = i / 13;
        deck[i].pips = i % 13 + 1;
    }
}