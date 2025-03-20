//
// Created by User on 2024/8/1.
//
#include "../Inc/EvaluateHand.h"
void countCardPips(Card hand[], int size, int matches[]) {
    int pipsCount[14] = { 0 };  // 點數範圍是 1 到 13，忽略 0

    // 統計每個點數出現的次數
    for (int i = 0; i < size; i++) {
        if (hand[i].pips > 0 && hand[i].pips <= 13) {
            pipsCount[hand[i].pips]++;
        }
    }

    // 統計結果
    matches[0] = 0; // 四張點數相同的牌
    matches[1] = 0; // 三張點數相同的牌
    matches[2] = 0; // 兩張點數相同的牌

    for (int i = 1; i <= 13; i++) {
        if (pipsCount[i] == 4) {
            matches[0]++;
        }
        else if (pipsCount[i] == 3) {
            matches[1]++;
        }
        else if (pipsCount[i] == 2) {
            matches[2]++;
        }
    }
}

// 函數檢查 handByPips 是否包含順子
/**
 * @brief Checks if the given hand contains a straight.
 *
 * This function checks if the provided hand contains a straight. A straight
 * consists of five consecutive cards, regardless of their suit.
 *
 * @param handByPips An array of cards sorted by their pips (rank).
 * @return true if the hand contains a straight, false otherwise.
 */
static bool hasStraight(Card* handByPips) {
    // 創建一個新的數組來存儲已經排序的點數
    int pips[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; ++i) {
        pips[i] = handByPips[i].pips;
    }

    // 對點數進行排序，將 -1 排到最前面
    // /////////qsort(pips, HAND_SIZE, sizeof(int), compareByPips);

    // 檢查是否有五張連續的牌
    // 檢查是否有五張67連續的牌
    int consecutive = 1;
    for (int i = 1; i < HAND_SIZE; ++i) {
        if (pips[i] == -1) continue; // 忽略 -1 的值
        if (pips[i] == pips[i - 1] + 1) {
            consecutive++;
            //if (consecutive == 5) {
            /*return true;
            }*/
            if (consecutive == 7) {
                return true;
            }
            else if (consecutive == 6) {
                return true;
            }
            else if (consecutive == 5) {
                return true;
            }
        }
        else if (pips[i] != pips[i - 1]) {
            consecutive = 1;
        }
    }

    // 檢查特例：A, 2, 3, 4, 5
    if (pips[0] == 1 && pips[1] == 2 && pips[2] == 3 && pips[3] == 4 && pips[4] == 5) {
        return true;
    }

    return false;
}
// 函數檢查 handBySuit 是否包含點數為 10、11、12、13 和 1 的牌
/**
 * @brief Checks if the given hand contains a royal flush.
 *
 * This function checks if the provided hand contains a royal flush. A royal flush
 * consists of the cards 10, J, Q, K, and A all of the same suit.
 *
 * @param handBySuit An array of cards filtered by the suit to check for a royal flush.
 * @return true if the hand contains a royal flush, false otherwise.
 */
static bool hasRoyalFlush(Card* handBySuit) {
    bool has10 = false, has11 = false, has12 = false, has13 = false, has1 = false;

    for (int i = 0; i < HAND_SIZE; ++i) {
        if (handBySuit[i].pips == 10) has10 = true;
        if (handBySuit[i].pips == 11) has11 = true;
        if (handBySuit[i].pips == 12) has12 = true;
        if (handBySuit[i].pips == 13) has13 = true;
        if (handBySuit[i].pips == 1) has1 = true;
    }

    return has10 && has11 && has12 && has13 && has1;
}
//函數將 handBySuit 中與指定 suit 不同的牌變為 suit = -1 和 pips = -1
/**
 * @brief Filters the given hand by suit, keeping only the cards of the specified suit.
 *
 * This function filters the provided hand array, modifying it to contain only the cards
 * of the specified suit. Cards not matching the specified suit are removed.
 *
 * @param suit       The suit to filter by.
 * @param handBySuit The array of cards to be filtered. This array is modified in place
 *                   to contain only the cards of the specified suit.
 */
static void filterHandBySuit(int suit, Card* handBySuit) {
    for (int i = 0; i < HAND_SIZE; ++i) {
        if (handBySuit[i].suit != suit) {
            handBySuit[i].suit = -1;
            handBySuit[i].pips = -1;
        }
    }
}
//當有suit超過五個時回傳花色
/**
 * @brief Determines the suit that forms a flush based on suit counts.
 *
 * This function checks the suit counts array to determine which suit
 * forms a flush (i.e., has five or more cards of the same suit).
 *
 * @param suitCount An array where each element represents the count of cards for each suit.
 *                  The array is assumed to have 4 elements, corresponding to the four suits.
 * @return The suit that forms a flush if a flush is present, otherwise -1.
 */
static int getFlushSuit(int* suitCount) {
    for (int i = 0; i < 4; ++i) {
        if (suitCount[i] >= 5) {
            return i;
        }
    }
    return -1;
}
// 函數檢查 suitCount 是否有數字大於等於 5
/**
 * @brief Checks if there is a flush based on suit counts.
 *
 * This function checks the suit counts array to determine if there are
 * five or more cards of the same suit, indicating a flush.
 *
 * @param suitCount An array where each element represents the count of cards for each suit.
 *                  The array is assumed to have 4 elements, corresponding to the four suits.
 * @return true if a flush is present, false otherwise.
 */
static bool hasFlush(int* suitCount) {
    for (int i = 0; i < 4; ++i) {
        if (suitCount[i] >= 5) {
            return true;
        }


    }
    return false;
}

// 評估手牌函數
/**
 * @brief Evaluates a poker hand and updates the counts for various hand rankings.
 *
 * This function evaluates a poker hand to determine its ranking and updates
 * the corresponding count in the provided counts array. The hand is evaluated
 * for flushes, straights, four of a kind, full house, three of a kind, two pairs,
 * one pair, and high card.
 *
 * @param handByPips An array of cards representing the hand to be evaluated.
 * @param counts     An array where the counts of different hand rankings are updated.
 *                   The array should be pre-allocated with at least 10 elements:
 *                   counts[0] - Royal Flush
 *                   counts[1] - Straight Flush
 *                   counts[2] - Four of a Kind
 *                   counts[3] - Full House
 *                   counts[4] - Flush
 *                   counts[5] - Straight
 *                   counts[6] - Three of a Kind
 *                   counts[7] - Two Pair
 *                   counts[8] - One Pair
 *                   counts[9] - High Card
 */
void evaluateHand(Card* handByPips, int* counts) {
    int pipsCount[14] = { 0 };  // 計算每個點數的張數
    int suitCount[4] = { 0 };   // 計算每個花色的張數
    for (int i = 0; i < HAND_SIZE; ++i) {
        pipsCount[handByPips[i].pips]++;
        suitCount[handByPips[i].suit]++;
    }
    if (hasFlush(suitCount)) {//同個花色大於五張
        int suit = getFlushSuit(suitCount);
        filterHandBySuit(suit, handByPips);//把不是同花色的牌拿掉
        if (hasRoyalFlush(handByPips)) {//檢查是不是黃家同花順
            counts[0] += 1;
        }
            //else if (hasStraight(handBySuit)) {
        else if (hasStraight(handByPips)) {

            counts[1] += 1; //同花順+1
        }
        else {
            counts[4] += 1;//同花+1
        }

    }
    else if (!hasFlush(suitCount)) {
        int matches[3]; //統計 4條 3張 2張
        countCardPips(handByPips, HAND_SIZE, matches);

        if (hasStraight(handByPips)) {//順子
            counts[5] += 1;
        }
        else if (matches[0] != 0) {//4條
            counts[2] += 1;
        }
        else if (matches[1] != 0 && matches[2] != 0) { //3張 2張各有一對
            counts[3] += 1;
        }
        else if (matches[1] != 0 && matches[2] == 0) { //3張 一樣
            counts[6] += 1;
        }
        else if (matches[1] == 0 && matches[2] >= 2) { //2對
            counts[7] += 1;
        }
        else if (matches[1] == 0 && matches[2] == 1) { //1對
            counts[8] += 1;
        }
        else {//其他
            counts[9] += 1;
        }


    }
}