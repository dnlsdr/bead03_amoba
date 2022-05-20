#include "PlayerTurn.hpp"

PlayerTurn::PlayerTurn(const int player) : Widget(0, 0, 100, 150)
{
    if(player == -1)
    {
        message = "Player 2";
        textColorR = 255;
        textColorB = 0;
    }
    else
    {
        message = "Player 1";
        textColorR = 0;
        textColorB = 255;
    }
}

void PlayerTurn::display()
{
    gout << color(textColorR, 200, textColorB)
         << move_to((size_x - gout.twidth(message)) / 2, size_y / 2)
         << text(message);
}
