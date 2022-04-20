#ifndef WARWICK_BJ_PLAYER_H
#define WARWICK_BJ_PLAYER_H
#include "GenericPlayer.hpp"

class Player : public GenericPlayer {
public:
    Player(const std::string& name= "");
    virtual ~Player();
    virtual bool isHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};

#endif
