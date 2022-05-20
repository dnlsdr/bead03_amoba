#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "graphics.hpp"
#include "Widget.hpp"

using namespace genv;

class Button : public Widget
{
protected:
    int width;
    int height;
    std::string content;

public:
    Button(const int, const int, const int, const int, const std::string);
    virtual void drawing();
    void handle(genv::event);
};

#endif // BUTTON_HPP
