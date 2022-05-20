#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Board.hpp"
#include "GameMaster.hpp"
#include "GameFinishedBoard.hpp"
#include "PlayerTurn.hpp"

#include <algorithm>

using namespace genv;

static const int window_width = 800;
static const int window_height = 600;

class Application
{

public:
    void eventLoop(std::vector<std::vector<Board*>*>, int&);
};

#endif // APPLICATION_HPP
