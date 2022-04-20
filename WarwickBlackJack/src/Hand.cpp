#include "Hand.hpp"

Hand::Hand() { }
Hand::~Hand() {
    Clear();
}
void Hand::Add(Card* pCard) {
    m_Cards.push_back(pCard);
}
void Hand::Clear() {
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();
}
int Hand::GetTotalValue() const {
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

