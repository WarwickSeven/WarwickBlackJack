#include "Deck.hpp"

Deck::Deck() {
    m_Cards.reserve(52);
    creation();
}
Deck::~Deck() = default;

void Deck::creation() {
    Clear();
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
        for (int r = Card::ACE; r <= Card::KING; ++r) {
            Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_Cards.begin(), m_Cards.end(), g);
}
void Deck::deal(Hand& aHand) {
    if (!(m_Cards.empty())) {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    } else {
        std::cout << "Out of cards. nothing to deal";
    }
}
void Deck::addCards(GenericPlayer& aGenericPlayer) {
    std::cout << std::endl;
    while (!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting()) {
        deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;
        if (aGenericPlayer.isBusted()) {
            aGenericPlayer.Bust();
        }
    }
}
