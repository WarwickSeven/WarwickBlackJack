#ifndef WARWICK_BJ_GAME_H
#define WARWICK_BJ_GAME_H
#include "Player.hpp"
#include "House.hpp"
#include "Deck.hpp"

class Game {
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
public:
    Game(const std::vector<std::string>& names);
    virtual ~Game();
    void play();
};

#endif
