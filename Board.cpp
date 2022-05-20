#include "Board.hpp"


Board::Board(const int _x, const int _y, const int _size_x, const int _size_y):Widget(_x, _y, _size_x, _size_y)
{
    value = 0;
    topL = new Coordinate(_x, _y);
    bottomR = new Coordinate(_x + _size_x, _y + _size_y);
}

void Board::drawing()
{
    gout << color(51, 51, 0)<< move_to(topL->x, topL->y)<< box(bottomR->x - topL->x, bottomR->y - topL->y);

    gout << color(153, 153, 0)<< move_to(topL->x + 3, topL->y + 3)<< box(bottomR->x - topL->x - 3, bottomR->y - topL->y - 3);

    if (value ==1)
    {
            gout << color(0, 0, 0)<< move_to(x + 3, y + 4) << line(size_x - 4, size_y - 4)
             << move_to(x + 4, y + 4) << line(size_x - 4, size_y - 4)
             << move_to(x + size_x - 3, y + 3) << line(-size_x + 6, size_y - 6)
             << move_to(x + size_x - 4, y + 5) << line(-size_x + 6, size_y - 6);

    }
    else if (value == -1)
    {
            gout << color(255, 255, 255)<<move_to(x+size_x/2,y+4)<<line(size_x - 20, size_y -8)
            <<move_to(x+size_x/2 +1,y+4)<<line(size_x - 20, size_y -8)<<line(-size_x+8, 0)<<line(size_x-8,-2)
            <<move_to(x+4, y+size_y-6)<<line(size_x/2-2, -size_y+8)<<line(-size_x/2+2, size_y-8);
    }
}

int Board::getValue()
{
    return value;
}

void Board::handle(const event ev, int& timer, const std::vector<std::vector<Board*>*> playBoard)
{
    if(ev.type == ev_mouse and isSelected(ev.pos_x, ev.pos_y) and ev.button == btn_left and value == 0)
    {
        if (timer%2 == 0)
        {
            value = 1;
        }
        else
        {
            value = -1;
        }
        timer++;
    }
}





