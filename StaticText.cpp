#include "StaticText.hpp"

StaticText::StaticText(const int _x, const int _y, const int _width, const int _height, const std::string _content) : Button(_x, _y, _width, _height, _content)
{
}

void StaticText::drawing()
{
    gout << color(100,100,100)
         << move_to(topL->x + width / 2 - gout.twidth(content) /2, topL->y + height / 2 - gout.cascent())
         << text(content);
}
