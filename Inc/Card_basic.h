//
// Created by User on 2024/8/1.
//

#ifndef TEX_POKER_CARD_BASIC_H

#define TEX_POKER_CARD_BASIC_H
    #include "common.h"
    #define NUM_CARDS 52
    //#define NUM_HANDS 1000000
    #define NUM_HANDS 13378456
    #define HAND_SIZE 7
    #define NUM_PLAYERS 10
    #define HOLE_CARDS 2
    #define COMMUNITY_CARDS 5

    // 定義花色類型
    typedef enum {
        HEARTS,    // 紅心
        DIAMONDS,  // 方塊
        CLUBS,     // 梅花
        SPADES     // 黑桃
    } Suit;

    // 定義卡片結構
    typedef struct {
        Suit suit;   // 花色
        short pips;  // 點數
    } Card;

#endif //TEX_POKER_CARD_BASIC_H
