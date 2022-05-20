#include "MyApplication.hpp"

MyApplication::MyApplication()
{
    for(int i = 0; i < 15; i++)
    {
        std::vector<Board*>* row = new std::vector<Board*>;

        for(int j = 0; j < 15; j++)
        {
            Board* temp = new Board(175 + j * 30, 90 + i * 30, 30, 30);
            row->push_back(temp);
        }
        playBoard.push_back(row);
    }

    gout << refresh;
}

void MyApplication::drawing()
{
    for_each(playBoard.begin(), playBoard.end(), [](std::vector<Board*>* row)
    {
        for_each(row->begin(), row->end(), [](Board* board)
        {
            board->drawing();
        });
    });

    gout << refresh;
}

void MyApplication::handle(MyApplication* window)
{
    gout.open(window_width, window_height);
    window->drawing();
    window->eventLoop(playBoard, timer);
}
