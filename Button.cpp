#include "Button.hpp"

Button::Button(const int _x, const int _y, const int _width, const int _height, const std::string _content) : Widget(_x, _y, _width, _height)
{
    width = _width;
    height = _height;
    content = _content;
}

void Button::drawing()
{
}

void Button::handle(event ev)
{
}
