#include "GameFinishedBoard.hpp"

GameFinishedBoard::GameFinishedBoard(const int winner) : Widget(0, 0, window_width, window_height)
{
    if(winner == -1)
    {
        message = "Player 2 won!";
        textColorR = 255;
        textColorG = 255;
        textColorB = 255;
    }
    else if(winner == 1)
    {
        message = "Player 1 won!";
        textColorR = 0;
        textColorG = 0;
        textColorB = 0;
    }
    else
    {
        message = "Tie!";
        textColorR = 128;
        textColorG = 128;
        textColorB = 128;
    }
}

void GameFinishedBoard::display()
{
    gout << color(153, 153, 0)
         << move_to(x, y)
         << box(size_x, size_y)
         << color(textColorR, textColorG, textColorB)
         << move_to((size_x - gout.twidth(message)) / 2, (size_y - gout.cascent()) / 2)
         << text(message);
}
