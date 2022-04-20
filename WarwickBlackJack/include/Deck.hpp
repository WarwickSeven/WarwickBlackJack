#ifndef WARWICK_BJ_DECK_H
#define WARWICK_BJ_DECK_H
#include "Hand.hpp"
#include "GenericPlayer.hpp"
#include <random>

class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();
    void creation();
    void shuffle();
    void deal(Hand& aHand);
    void addCards(GenericPlayer& aGenericPlayer);
};

#endif
