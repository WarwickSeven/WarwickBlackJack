#include <iostream>
#include <vector>

class Card { // Lesson C Task 4
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    rank cRank;
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    suit cSuit;
    bool cIsFaceUp;

    Card(rank r, suit s, bool ifu) : cRank(r), cSuit(s), cIsFaceUp(ifu) { }
    
    void Flip() {
        cIsFaceUp = !(cIsFaceUp);
    }
    int GetValue() const {
        int value { 0 };
        if (cIsFaceUp) {
            value = cRank;
            if (value > 10) {
                value = 10;
            }
        }
        return value;
    }
};
class Hand { // Lesson D Task 3
protected:
    std::vector<Card*> m_Cards;
public:
    Hand() { }
    virtual ~Hand() { }
    
    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    }
    void Clear() {
        std::vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
            delete *iter;
            *iter = 0;
        }
        m_Cards.clear();
    }
    int GetTotalValue() const {
        if (m_Cards.empty()) {
            return 0;
        }
        if (m_Cards[0]->GetValue()==0) {
            return 0;
        }
        int tValue { 0 };
        std::vector<Card*>::const_iterator iter;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
            tValue += (*iter)->GetValue();
        }
        bool haveAce = false;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
            if ((*iter)->GetValue() == Card::ACE) {
                haveAce = true;
            }
        }
        if (haveAce && tValue <= 11) {
            tValue += 10;
        }
        return tValue;
    }
};

class GenericPlayer : public Hand { //Lesson E Task 4
protected:
    std::string m_Name;
public:
    GenericPlayer(const std::string& name = "default") { }
    virtual ~GenericPlayer() { }
    
    virtual bool isHitting() const = 0;
    
    bool isBusted() const {
        return (GetTotalValue() > 21);
    }
    void Bust() const {
        std::cout << m_Name << " looser.. " << std::endl;
    }
};

int main() {
    
    return 0;
}

