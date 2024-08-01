//
// Created by User on 2024/8/1.
//
#include "sortAndStoreHand.h"
//比較排組
/**
 * @brief Compares two cards by their pips (rank).
 *
 * This function is used by qsort to sort cards by their pips (rank).
 * It handles special cases where the pips are -1, which can be used
 * to represent an invalid or placeholder card.
 *
 * @param a Pointer to the first card.
 * @param b Pointer to the second card.
 * @return Negative value if the first card's pips are less than the second card's pips,
 *         zero if they are equal, positive value if the first card's pips are greater than the second card's pips.
 */
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
/**
 * @brief Compares two cards by their pips (rank).
 *
 * This function is used by qsort to sort cards by their pips (rank).
 *
 * @param a Pointer to the first card.
 * @param b Pointer to the second card.
 * @return Negative value if the first card's pips are less than the second card's pips,
 *         zero if they are equal, positive value if the first card's pips are greater than the second card's pips.
 */
void sortAndStoreHand(Card hand[], Card handByPips[]) {
    // 複製手牌到 handByPips
    for (int i = 0; i < HAND_SIZE; i++) {
        handByPips[i] = hand[i];
    }

    // 按點數排序
    qsort(handByPips, HAND_SIZE, sizeof(Card), compareByPips);
}