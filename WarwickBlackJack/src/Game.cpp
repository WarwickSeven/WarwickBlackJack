#include "Game.hpp"


Game::Game(const std::vector<std::string>& names) {
std::vector<std::string>::const_iterator pName;

    for (pName = names.begin(); pName != names.end(); pName++) {
        m_Players.push_back(Player(*pName));
    }
    m_Deck.creation();
    m_Deck.shuffle();
}
Game::~Game() = default;

void Game::play() {
    std::vector<Player>::iterator pPlayer;
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
        m_Deck.deal(*pPlayer);
        m_Deck.deal(*pPlayer);
    }
    m_Deck.deal(m_House);
    m_Deck.deal(m_House);
    m_House.FlipFirstCard();
    
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
        std::cout << *pPlayer << std::endl;
    }
    std::cout << m_House << std::endl;
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
        m_Deck.addCards(*pPlayer);
    }
    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;
    m_Deck.addCards(m_House);
    
    if (m_House.isBusted()) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
            if (!(pPlayer->isBusted())) {
                pPlayer->Win();
            }
        }
    } else {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
            if (!(pPlayer->isBusted())) {
                if (pPlayer->GetTotalValue() > m_House.GetTotalValue()) {
                    pPlayer->Win();
                } else {
                    if (pPlayer->GetTotalValue() < m_House.GetTotalValue()) {
                        pPlayer->Lose();
                    } else {
                        pPlayer->Push();
                    }
                }
            }
        }
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
            pPlayer->Clear();
        }
        m_House.Clear();
    }
}
