//
//  DeckOfCards.cpp
//  chapter18_自动洗发牌
//
//  Created by Moon on 2020/12/6.
//  Copyright © 2020 Moon. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Card.h"
#include "DeckOfCards.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>


using namespace std;
using std::vector;

DeckOfCards::DeckOfCards()
{
    int num = 0;
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 13; i++)
        {
            deck.push_back(Card(i + 1,j + 1));
            num++;
        }
    }
    setCurrentCard(num);
}

void DeckOfCards::displayDeckOfCards()
{
    if(deck.empty() == 1)
    {
        cout << "deck is empty" << endl;
    }
    else{
        for(int i = 0; i < deck.size(); i++)
            {
                cout << deck[i].toString() << endl;
            }
    }
}

//Fisher–Yates随机置乱算法也被称做高纳德置乱算法，通俗说就是生成一个有限集合的随机排列。
//Fisher-Yates随机置乱算法是无偏的，所以每个排列都是等可能的，当前使用的Fisher-Yates随机置乱算法是相当有效的，需要的时间正比于要随机置乱的数，不需要额为的存储空间开销。
void DeckOfCards::shuffle()
{
    for(long int i = deck.size() - 1; i >= 1; i--)
    {
        //要取得[0,n]  就是rand（）%n+1     表示 从0到n的数
        srand((int)time(0));  // 产生随机种子  把0换成NULL也行
            for (int j = 0; j < rand() % ( i + 1 ); j++)
            {
                swap(deck[i], deck[j]);
            }
    }
}

//将deck容器底部的card成员出栈，并返回该成员
Card DeckOfCards::dealCard()
{
    setCurrentCard(deck.size() - 1);
    Card dealCard = deck.back();
    deck.pop_back();
    return dealCard;
}


bool DeckOfCards::moreCards()
{
    return !deck.empty();
}

int DeckOfCards::getCurrentCard()
{
    return currentCard;
}

void DeckOfCards::setCurrentCard(int num)
{
    currentCard = num;
}
