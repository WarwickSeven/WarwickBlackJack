#include "GenericPlayer.hpp"

GenericPlayer::GenericPlayer(const std::string& name) : m_Name(name) { }
GenericPlayer::~GenericPlayer() = default;

bool GenericPlayer::isBusted() const {
    return (GetTotalValue() > 21);
}
void GenericPlayer::Bust() const {
    std::cout << m_Name << " busted." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer) {
    os << aGenericPlayer.m_Name << ":\t ";
    std::vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty()) {
        for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); pCard++) {
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.GetTotalValue() != 0) {
            std::cout << "(" << aGenericPlayer.GetTotalValue() << ")";
        }
    } else {
        os << "<empty>";
    }
    return os;
}
