//
//  DeckOfCards.h
//  chapter18_自动洗发牌
//
//  Created by Moon on 2020/12/6.
//  Copyright © 2020 Moon. All rights reserved.
//

#include <string>
#include "Card.h"
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

#ifndef DeckOfCards_h
#define DeckOfCards_h

//创建一副扑克牌
class DeckOfCards
{
public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards();
    void setCurrentCard( int );
    int getCurrentCard();
    void displayDeckOfCards();
   
private:
    vector<Card> deck;
    int currentCard;//1-52
};

#endif /* DeckOfCards_h */
