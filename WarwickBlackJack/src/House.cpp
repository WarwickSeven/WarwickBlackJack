#include "House.hpp"

House::House(const std::string& name) : GenericPlayer(name) { }
House::~House() = default;

bool House::isHitting() const {
    return (GetTotalValue() <= 16);
}
void House::FlipFirstCard() {
    if (!(m_Cards.empty())) {
        m_Cards[0]->Flip();
    } else {
        std::cout << "There is no card to flip." << std::endl;
    }
}
