#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "Button.hpp"

class StaticText : public Button
{
public:
    StaticText(const int, const int, const int, const int, const std::string);
    void drawing();
};

#endif // STATICTEXT_HPP
