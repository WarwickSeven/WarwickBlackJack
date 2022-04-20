#ifndef WARWICK_BJ_GENERICPLAYER_H
#define WARWICK_BJ_GENERICPLAYER_H
#include "Hand.hpp"

class GenericPlayer : public Hand {
protected:
    std::string m_Name;
    GenericPlayer(const std::string& name);
public:
    virtual ~GenericPlayer();
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void Bust() const;
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
};

#endif
