#include "Widget.hpp"

Coordinate::Coordinate(const int _x, const int _y)
{
    Coordinate::x = _x;
    Coordinate::y = _y;
}


Widget::Widget(const int _x, const int _y, const int _size_x, const int _size_y) :x(_x), y(_y), size_x(_size_x), size_y(_size_y)
{
    topL = new Coordinate(_x, _y);
    bottomR = new Coordinate(_x + _size_x, _y + _size_y);
}

void Widget::drawing()
{}


bool Widget::isSelected(const int mouse_x, const int mouse_y)
{
    return mouse_x > x and mouse_x < x + size_x and mouse_y > y and mouse_y < y + size_y;
}
