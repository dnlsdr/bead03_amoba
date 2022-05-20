#ifndef PLAYERTURN_HPP
#define PLAYERTURN_HPP

#include "Widget.hpp"

using namespace genv;

class PlayerTurn : public Widget
{
private:
    std::string message;
    int textColorR;
    int textColorB;
public:
    PlayerTurn(const int);
    void display();
};

#endif // PLAYERTURN_HPP
