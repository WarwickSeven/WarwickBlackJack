#ifndef WARWICK_BJ_CARD_H
#define WARWICK_BJ_CARD_H
#include <iostream>

class Card {
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    Card(rank r, suit s);
    virtual ~Card();
    void Flip();
    int GetValue() const;
    friend std::ostream& operator<<(std::ostream& os, const  Card& aCard);
private:
    rank cRank;
    suit cSuit;
    bool cIsFaceUp;
};

#endif
