#ifndef BOARD_HPP
#define BOARD_HPP

#include "Widget.hpp"
#include <vector>



class Board : public Widget
{
protected:
    int value;
    Coordinate* topL;
    Coordinate* bottomR;

public:
    Board(const int, const int, const int, const int);
    void drawing() override;
    int getValue();
    void handle(const genv::event, int&, const std::vector<std::vector<Board*>*>);
};

#endif // BOARD_HPP

