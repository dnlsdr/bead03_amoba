#ifndef MYAPPLICATION_HPP
#define MYAPPLICATION_HPP

#include "Application.hpp"
#include "Board.hpp"



class MyApplication : public Application
{
protected:
    std::vector<std::vector<Board*>*> playBoard;
    int timer = 0;

public:
    MyApplication();
    void drawing();
    void handle(MyApplication*);
};

#endif // MYAPPLICATION_HPP
