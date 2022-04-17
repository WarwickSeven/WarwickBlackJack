#include <iostream>
#include <vector>

class Card { // Lesson C Task 4
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    rank cRank;
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    suit cSuit;
    bool cIsFaceUp;
    
    friend std::ostream& operator<<(std::ostream& os, const  Card& aCard); //Lesson F Task 5
    
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
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlauer); //Lesson F Task 5
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
class Player : public GenericPlayer { //Lesson F Task 3
public:
    Player(const std::string& name) : GenericPlayer(name) { };
    virtual ~Player() { };
    
    virtual bool isHitting() const {
        char more;
        std::cout << m_Name << ", one more? (y/n)";
        std::cin >> more;
        return (more == 'y' || more == 'Y');
    }
    void Win() const {
        std::cout << m_Name << "wins!" << std::endl;
    }
    void Lose() const {
        std::cout << m_Name << "loses!" << std::endl;
    }
    void Push() const {
        std::cout << m_Name << "pushes." << std::endl;
    }
};

class House : public GenericPlayer { //Lesson F Task 4
public:
    House(const std::string& name = "House") : GenericPlayer(name) { }
    virtual ~House() { }
    
    virtual bool isHitting() const {
        return (GetTotalValue() <= 16);
    }
    void FlipFirstCard() {
        if (!(m_Cards.empty())) {
            m_Cards[0]->Flip();
        } else {
            std::cout << "There is no card to flip." << std::endl;
        }
    }
};

std::ostream& operator<<(std::ostream& os, const Card& aCard) { //Lesson F Task 5
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const std::string SUITS[] = { "c", "d", "h", "s" };
    if (aCard.cIsFaceUp) {
        os << RANKS[aCard.cRank] << SUITS[aCard.cSuit];
    } else {
        os << "XX";
    }
    return os;
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer) { //Lesson F Task 5
    os << aGenericPlayer.m_Name << " ";
    std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty()) {
        for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); pCard++) {
            os << *(*pCard) << " ";
        }
        if (aGenericPlayer.GetTotalValue() != 0) {
            std::cout << aGenericPlayer.GetTotalValue();
        }
    } else {
        os << "empty";
    }
    return os;
}

int main() {
    
    return 0;
}

