#include <Card_basic.h>
#include <EvaluateHand.h>
#include <shuffleDeck.h>
#include <dealHands.h>
#include <combineHand.h>
#include <sortAndStoreHand.h>
#include <initializeDeck.h>

// 排序並儲存結果函數

int main() {
    srand(time(NULL));

    Card deck[NUM_CARDS];
    Card hands[NUM_PLAYERS][HOLE_CARDS];
    Card community[COMMUNITY_CARDS];
    Card combinedHand[HAND_SIZE];
    Card handByPips[HAND_SIZE];
    Card handBySuit[HAND_SIZE];
    int counts[10] = { 0 }; // 0: 皇家同花順, 1: 同花順, 2: 四條, 3: 葫蘆, 4: 同花, 5: 順子, 6: 三條, 7: 兩對, 8: 一對, 9: 高牌

    initializeDeck(deck);

    // 進行 NUM_HANDS 次迭代，每次迭代模擬一次完整的牌局
    for (int i = 0; i < NUM_HANDS; ++i) {
        // 將牌組進行洗牌
        shuffleDeck(deck, NUM_CARDS);

        // 將洗好的牌組發給玩家並發公共牌
        dealHands(deck, hands, community);

        // 對每個玩家的手牌進行處理
        for (int j = 0; j < NUM_PLAYERS; ++j) {
            // 將玩家的底牌和公共牌組合成最終的手牌
            combineHand(combinedHand, hands[j], community);

            // 排序並儲存手牌
            sortAndStoreHand(combinedHand, handByPips);

            // 評估手牌
            evaluateHand(handByPips, counts);
        }
    }

    int totalHands = NUM_HANDS * NUM_PLAYERS;

    // 按照圖片中的順序打印結果
    printf("Royal flush: %d (%.8f)\n", counts[0], (double)counts[0] / totalHands);
    printf("Straight flush: %d (%.8f)\n", counts[1], (double)counts[1] / totalHands);
    printf("Four of a kind: %d (%.8f)\n", counts[2], (double)counts[2] / totalHands);
    printf("Full house: %d (%.8f)\n", counts[3], (double)counts[3] / totalHands);
    printf("Flush: %d (%.8f)\n", counts[4], (double)counts[4] / totalHands);
    printf("Straight: %d (%.8f)\n", counts[5], (double)counts[5] / totalHands);
    printf("Three of a kind: %d (%.8f)\n", counts[6], (double)counts[6] / totalHands);
    printf("Two pair: %d (%.8f)\n", counts[7], (double)counts[7] / totalHands);
    printf("One pair: %d (%.8f)\n", counts[8], (double)counts[8] / totalHands);
    printf("High card: %d (%.8f)\n", counts[9], (double)counts[9] / totalHands);

    double sumProbabilities = 0.0;
    for (int i = 0; i < 10; ++i) {
        sumProbabilities += (double)counts[i] / totalHands;
    }
    printf("Total: %d\n", totalHands);
    printf("Sum of all probabilities: %.8f\n", sumProbabilities);

    return 0;
}