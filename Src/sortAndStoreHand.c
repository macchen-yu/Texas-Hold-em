//
// Created by User on 2024/8/1.
//
#include "sortAndStoreHand.h"
//比較排組
static int compareByPips(const void* a, const void* b) {
    const Card* cardA = (const Card*)a;
    const Card* cardB = (const Card*)b;

    // 檢查點數是否為 -1
    if (cardA->pips == -1 && cardB->pips == -1) return 0;
    if (cardA->pips == -1) return -1;
    if (cardB->pips == -1) return 1;

    // 點數比較
    return cardA->pips - cardB->pips;
}
// 排序並儲存手牌
void sortAndStoreHand(Card hand[], Card handByPips[]) {
    // 複製手牌到 handByPips
    for (int i = 0; i < HAND_SIZE; i++) {
        handByPips[i] = hand[i];
    }

    // 按點數排序
    qsort(handByPips, HAND_SIZE, sizeof(Card), compareByPips);
}