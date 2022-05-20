#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "Board.hpp"
#include <algorithm>

class GameMaster
{
protected:
    int winningValue = 0;
    int endValue;
public:
    GameMaster();
    bool rowScan(const int, const std::vector<std::vector<Board*>*>);
    bool columnScan(const int, const std::vector<std::vector<Board*>*>);
    bool isplayBoardFull(const std::vector<std::vector<Board*>*>);
    bool crossLtoR(const int, const std::vector<std::vector<Board*>*>);
    bool crossRtoL(const int, const std::vector<std::vector<Board*>*>);
    bool handle(const int, const std::vector<std::vector<Board*>*>);
};

#endif // GAMEMASTER_HPP
