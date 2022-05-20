#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

using namespace genv;

class Coordinate
{
public:
    int x;
    int y;
    Coordinate(const int, const int);
};

class Widget
{
protected:
    int x, y;
    int size_x, size_y;
    Coordinate* topL;
    Coordinate* bottomR;

public:
    Widget(const int, const int, const int, const int);
    virtual void drawing();
    bool isSelected(const int, const int);
};

#endif //WIDGET_HPP
