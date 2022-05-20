#ifndef GAMEFINISHEDBOARD_HPP
#define GAMEFINISHEDBOARD_HPP

#include "Widget.hpp"
#include "Application.hpp"

using namespace genv;

class GameFinishedBoard : public Widget
{
private:
    int textColorR;
    int textColorG;
    int textColorB;
    std::string message;
public:
    GameFinishedBoard(const int);
    void display();
};

#endif // GAMEFINISHEDBOARD_HPP
