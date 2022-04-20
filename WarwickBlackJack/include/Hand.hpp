#ifndef WARWICK_BJ_HAND_H
#define WARWICK_BJ_HAND_H
#include "Card.hpp"
#include <vector>

class Hand {
protected:
    std::vector<Card*> m_Cards;
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard);
    void Clear();
    int GetTotalValue() const;
};

#endif
