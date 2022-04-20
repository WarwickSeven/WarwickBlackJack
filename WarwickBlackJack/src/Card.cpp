#include "Card.hpp"

Card::Card(rank r, suit s) : cRank(r), cSuit(s), cIsFaceUp(true) { }

Card::~Card() = default;

void Card::Flip() {
    cIsFaceUp = !cIsFaceUp;
}
int Card::GetValue() const {
    int value { 0 };
    if (cIsFaceUp) {
        value = cRank;
        if (value > 10) {
            value = 10;
        }
    }
    return value;
}

std::ostream& operator<<(std::ostream& os, const Card& aCard) {
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const std::string SUITS[] = { "c", "d", "h", "s" };
    if (aCard.cIsFaceUp) {
        os << RANKS[aCard.cRank] << SUITS[aCard.cSuit];
    } else {
        os << "XX";
    }
    return os;
};
