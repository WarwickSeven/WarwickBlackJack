#ifndef WARWICK_BJ_HOUSE_H
#define WARWICK_BJ_HOUSE_H
#include "GenericPlayer.hpp"

class House : public GenericPlayer {
public:
    House(const std::string& name = "House");
    virtual ~House();
    virtual bool isHitting() const;
    void FlipFirstCard();
};

#endif
