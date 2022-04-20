#include "Player.hpp"

Player::Player(const std::string& name) : GenericPlayer(name) { };
Player::~Player() { };

bool Player::isHitting() const {
    char more;
    std::cout << m_Name << ", one more? (y/n)";
    std::cin >> more;
    return (more == 'y' || more == 'Y');
}
void Player::Win() const {
    std::cout << m_Name << " wins!" << std::endl;
}
void Player::Lose() const {
    std::cout << m_Name << " loses!" << std::endl;
}
void Player::Push() const {
    std::cout << m_Name << " pushes." << std::endl;
}
